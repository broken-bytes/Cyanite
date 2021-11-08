#pragma once

#include <directx/d3d12.h>
#include <directx/d3dx12.h>
#include <dxgi1_6.h>
#include <cstdint>
#include <winrt/base.h>


#include "Camera.hxx"
#include "Light.hxx"
#include "RenderBackend.hxx"
#include "d3d12/FrameResource.hxx"

using namespace winrt;


namespace BrokenBytes::Cyanite::Engine::Rendering {
	class RenderBackendD3D12 : public RenderBackend {
	public:
		RenderBackendD3D12(Window window, uint16_t width, uint16_t height);
		~RenderBackendD3D12();
		auto Init() -> void override;
		auto Update() -> void override;
		auto Render() -> void override;
		auto Deinit() -> void override;
		auto VRAM() -> uint64_t override;
	private:
		// Config
		static const uint8_t FrameCount = 2;
		static const uint8_t Contexts = 4;
		static const uint8_t CommandLists = 16;

		// Pipeline objects
		CD3DX12_VIEWPORT _viewport;
		CD3DX12_RECT _scissorsRect;
		com_ptr<IDXGISwapChain4> _swapChain;
		com_ptr<ID3D12Device8> _device;
		std::array<com_ptr<ID3D12Resource2>, RenderBackendD3D12::FrameCount> _renderTargets;
		com_ptr<ID3D12Resource2> _depthStencil;
		com_ptr<ID3D12CommandAllocator> _commandAllocator;
		com_ptr<ID3D12CommandQueue> _commandQueue;
		com_ptr<ID3D12RootSignature> _rootSignature;
		com_ptr<ID3D12DescriptorHeap> _rtvHeap;
		com_ptr<ID3D12DescriptorHeap> _dsvHeap;
		com_ptr<ID3D12DescriptorHeap> _cbvSrcHeap;
		com_ptr<ID3D12DescriptorHeap> _samplerHeap;
		com_ptr<ID3D12PipelineState> _pipelineState;
		com_ptr<ID3D12PipelineState> _pipelineStateShadowMap;

		//App Resources
		D3D12_VERTEX_BUFFER_VIEW _vertexBufferView;
		D3D12_INDEX_BUFFER_VIEW _indexBufferView;
		std::vector<com_ptr<ID3D12Resource2>> _textures;
		std::vector<com_ptr<ID3D12Resource2>> _textureUploads;
		com_ptr<ID3D12Resource2> _indexBuffer;
		com_ptr<ID3D12Resource2> _indexBufferUpload;
		com_ptr<ID3D12Resource2> _vertexBuffer;
		com_ptr<ID3D12Resource2> _vertexBufferUpload;
		uint64_t _rtvDescriptorSize;
		std::vector<Light> _lights;
		std::vector<Camera> _lightsCameras;
		Camera _camera;

		// Synchronization Variables
		std::array<HANDLE, Contexts> _workerBeginRenderFrame;
		std::array<HANDLE, Contexts> _workerFinishShadowPass;
		std::array<HANDLE, Contexts> _workerFinishedRenderFrame;
		std::array<HANDLE, Contexts> _threadHandles;
		UINT _frameIndex;
		HANDLE _fenceEvent;
		com_ptr<ID3D12Fence> _fence;
		UINT64 _fenceValue;

		// Singleton object so that worker threads can share members.
		static RenderBackendD3D12* _App;


		struct ThreadParameter
		{
			int threadIndex;
		};
		std::array<ThreadParameter, Contexts> _threadParameters;

		void WorkerThread(int threadIndex);
		void SetCommonPipelineState(ID3D12GraphicsCommandList* commandList);

		void LoadPipeline();
		void LoadAssets();
		void RestoreD3DResources();
		void ReleaseD3DResources();
		void WaitForGpu();
		void LoadContexts();
		void BeginFrame();
		void MidFrame();
		void EndFrame();
	};
}
