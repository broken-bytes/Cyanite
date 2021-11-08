#include "RenderBackendVulkan.hxx"

constexpr uint8_t FrameCount = 2;
constexpr uint8_t Contexts = 4;
constexpr uint8_t CommandLists = 16;

BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::RenderBackendVulkan(Window window, uint16_t width, uint16_t height) : RenderBackend(window, width, height) {
}

auto BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::Init() -> void
{
}

auto BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::Update() -> void
{

}

auto BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::Render() -> void
{
}

auto BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::Deinit() -> void
{

}

auto BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::VRAM() -> uint64_t
{
	return 0;
}

void BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::LoadPipeline()
{
}

void BrokenBytes::Cyanite::Engine::Rendering::RenderBackendVulkan::LoadAssets()
{
}
