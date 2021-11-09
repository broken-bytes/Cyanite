#include "RenderBackendVulkan.hxx"
#include <iostream>
#include <SDL.h>
#include <SDL_vulkan.h>
#include "vulkan/DeviceInfo.hxx"

constexpr uint8_t FrameCount = 2;
constexpr uint8_t Contexts = 4;
constexpr uint8_t CommandLists = 16;

namespace BrokenBytes::Cyanite::Engine::Rendering {
	constexpr std::array<const char*, 1 > VK_EXTENSIONS_REQUIRED = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};


	RenderBackendVulkan::RenderBackendVulkan(SDL_Window* window, uint16_t width, uint16_t height) : RenderBackend(window, width, height) {
	}

	RenderBackendVulkan::~RenderBackendVulkan() {

	}

	auto RenderBackendVulkan::Init() -> uint8_t {
		try {
			CreateVkInstance();
			CreateVkSurface();
			BindPhysicalDevice(QueryHighPerformanceGPU());
			return EXIT_SUCCESS;
		}
		catch (std::runtime_error& err) {
			std::cout << err.what() << std::endl;
			return EXIT_FAILURE;
		}
	}

	auto RenderBackendVulkan::Update() -> void {

	}

	auto RenderBackendVulkan::Render() -> void {
	}

	auto RenderBackendVulkan::Deinit() -> void {
		vkDestroyInstance(_vInstance, nullptr);
		vkDestroyDevice(_vDevice, nullptr);
		vkDestroySurfaceKHR(_vInstance, _vSurface, nullptr);
	}

	auto RenderBackendVulkan::VRAM() -> uint64_t
	{
		return 0;
	}

	auto RenderBackendVulkan::LoadPipeline() -> void
	{
	}

	auto RenderBackendVulkan::LoadAssets() -> void
	{
	}

	auto RenderBackendVulkan::CheckVulkanDeviceExtensionsSupport(VkPhysicalDevice device) -> bool {
		uint32_t extensionCount = 0;
		if (!VK_SUCCESS == vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr)) {
			throw std::runtime_error("Could not query device capabilities");
		}

		if (extensionCount == 0) {
			throw std::runtime_error("Device capabilities lacks required capabilities");
		}

		std::vector<VkExtensionProperties> extensions(extensionCount);

		if (!VK_SUCCESS == vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, extensions.data())) {
			throw std::runtime_error("Could not query device capabilities");
		}

		for (const auto& deviceExtension : VK_EXTENSIONS_REQUIRED) {
			bool hasExtension = false;
			for (const auto& extension : extensions) {
				if (strcmp(extension.extensionName, deviceExtension) == 0) {
					hasExtension = true;
					break;
				}
			}

			if (!hasExtension) {
				return false;
			}
		}

		return true;
	}

	auto RenderBackendVulkan::CheckVulkanExtensionsSupport(std::vector<const char*> extensions) -> bool {
		uint32_t extensionCount = 0;
		if (VK_SUCCESS != vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr)) {
			throw std::runtime_error("Could not retrieve Vulkan extensions support");
		}

		std::vector<VkExtensionProperties> eProps = std::vector<VkExtensionProperties>(extensionCount);

		if (VK_SUCCESS != vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, eProps.data())) {
			throw std::runtime_error("Could not retrieve Vulkan extensions support");
		}

		for (const auto& layer : extensions) {
			bool hasSupport = false;

			for (const auto& found : eProps) {
				if (strcmp(found.extensionName, layer) == 0) {
					hasSupport = true;
					break;
				}
			}
			if (!hasSupport) {
				return false;
			}
		}
		return true;
	}

	auto RenderBackendVulkan::CreateVkInstance() -> void {
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.applicationVersion = VK_MAKE_API_VERSION("a", 0, 0, 1);
		appInfo.engineVersion = VK_MAKE_API_VERSION("a", 0, 0, 1);
		appInfo.pApplicationName = "Cyanite";
		appInfo.pEngineName = "CyaniteEngine";
		appInfo.apiVersion = VK_API_VERSION_1_2;

		uint32_t extensionCount;

		if (!SDL_Vulkan_GetInstanceExtensions(_window, &extensionCount, nullptr)) {
			throw std::runtime_error("SDL Failed to to retrieve Vulkan extensions");
		}
		std::vector<const char*> extensions = std::vector<const char*>(extensionCount);

		if (!SDL_Vulkan_GetInstanceExtensions(_window, &extensionCount, extensions.data())) {
			throw std::runtime_error("SDL Failed to to retrieve Vulkan extensions");
		}

		if (!CheckVulkanExtensionsSupport(extensions)) {
			throw std::runtime_error("Vulkan cannoit instantiate instance. Missing extensions");
		}

		VkInstanceCreateInfo createInfo = {};
		createInfo.sType = VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensionCount);
		createInfo.ppEnabledExtensionNames = extensions.data();
		createInfo.ppEnabledLayerNames = 0;
		createInfo.enabledLayerCount = 0;

		VkInstance instance = {};
		if (VK_SUCCESS != vkCreateInstance(&createInfo, nullptr, &instance)) {
			throw std::runtime_error("Vulkan could not be instantiated");
		}
		this->_vInstance = instance;
	}

	auto RenderBackendVulkan::CreateVkSurface() -> void {
		VkSurfaceKHR surface = {};
		if (!SDL_Vulkan_CreateSurface(_window, _vInstance, &surface)) {
			throw std::runtime_error("Could not create SDL Vulkan surface");
		}
		_vSurface = surface;
	}

	auto RenderBackendVulkan::GetDeviceInfo(const VkPhysicalDevice device)->DeviceInfo& {
		DeviceInfo info = { };
		uint32_t queueFamCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamCount, nullptr);
		std::vector<VkQueueFamilyProperties> queueList(queueFamCount);
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamCount, queueList.data());

		bool hasGraphicsQueue = false;
		VkBool32 hasPresentationQueue = false;
		uint32_t index = 0;
		for (const auto& queue : queueList) {
			if (queue.queueCount > 0 && queue.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
				hasGraphicsQueue = true;
				info.GraphicsQueue = index;
			}

			if (queue.queueCount > 0 && queue.queueFlags) {
				hasGraphicsQueue = true;
				info.GraphicsQueue = index;
			}

			if (VK_SUCCESS != vkGetPhysicalDeviceSurfaceSupportKHR(device, index, _vSurface, &hasPresentationQueue)) {
				throw std::runtime_error("Failed to get support support");
			}
			if (queue.queueCount > 0 && hasPresentationQueue) {
				info.PresentationQueue = index;
			}

			if (hasGraphicsQueue && hasPresentationQueue) {
				break;
			}
			index++;
		}

		if (!hasGraphicsQueue) {
			throw std::runtime_error("GPU does not have a valid graphics queue");
		}

		return info;
	}


	auto RenderBackendVulkan::BindPhysicalDevice(VkPhysicalDevice device) -> void {
		_pDevice = device;
		DeviceInfo deviceInfo = GetDeviceInfo(_pDevice);

		std::vector<VkDeviceQueueCreateInfo> qInfos;
		std::set<int32_t> queueIndices = { deviceInfo.GraphicsQueue, deviceInfo.PresentationQueue };
		for (auto qFamIndex : queueIndices) {
			VkDeviceQueueCreateInfo qInfo = {};
			qInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			qInfo.queueFamilyIndex = deviceInfo.GraphicsQueue;
			qInfo.queueCount = 1;
			float priority = 1.0f;
			qInfo.pQueuePriorities = &priority;
			qInfos.emplace_back(qInfo);
		}

		VkDeviceCreateInfo dInfo = {};
		dInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		dInfo.pQueueCreateInfos = qInfos.data();
		dInfo.queueCreateInfoCount = static_cast<uint32_t>(qInfos.size());
		dInfo.enabledExtensionCount = static_cast<uint32_t>(VK_EXTENSIONS_REQUIRED.size());
		dInfo.ppEnabledExtensionNames = VK_EXTENSIONS_REQUIRED.data();

		VkPhysicalDeviceFeatures features = {};
		dInfo.pEnabledFeatures = &features;

		VkDevice vDevice = {};
		if (VK_SUCCESS != vkCreateDevice(_pDevice, &dInfo, nullptr, &vDevice)) {
			throw std::runtime_error("Failed to create logical vulkan device");
		}

		_vDevice = vDevice;

		VkQueue graphicsQueue = {}; 
		VkQueue presentationQueue = {};
		vkGetDeviceQueue(_vDevice, deviceInfo.GraphicsQueue, 0, &graphicsQueue);
		vkGetDeviceQueue(_vDevice, deviceInfo.PresentationQueue, 0, &presentationQueue);
		_graphicsQueue = graphicsQueue;
		_presentationQueue = presentationQueue;
	}

	auto RenderBackendVulkan::QueryHighPerformanceGPU() -> VkPhysicalDevice {
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(_vInstance, &deviceCount, nullptr);

		if (deviceCount == 0) {
			throw std::runtime_error("No Vulkan GPU device found");
		}

		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(_vInstance, &deviceCount, devices.data());

		bool hasValidDevice = false;
		VkPhysicalDevice targetDevice = {};
		VkPhysicalDeviceFeatures features = {};
		for (const auto& device : devices) {
			vkGetPhysicalDeviceFeatures(device, &features);
			auto info = GetDeviceInfo(device);
			auto hasSupport = CheckVulkanDeviceExtensionsSupport(device);
			if (info.IsValid() && hasSupport) {
				targetDevice = device;
				hasValidDevice = true;
				break;
			}
		}

		if (!hasValidDevice) {
			throw std::runtime_error("No valid Graphics Processor found.");
		}

		return targetDevice;
	}
}