#include "RenderBackendVulkan.hxx"
#include <iostream>
#include <SDL.h>
#include <SDL_vulkan.h>
#include <algorithm>
#include "vulkan/DeviceInfo.hxx"
#undef min,max

constexpr uint8_t FrameCount = 2;
constexpr uint8_t Contexts = 4;
constexpr uint8_t CommandLists = 16;

namespace BrokenBytes::Cyanite::Engine::Rendering {
	constexpr std::array<const char*, 1 > VK_EXTENSIONS_REQUIRED = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};


	RenderBackendVulkan::RenderBackendVulkan(SDL_Window* window, uint32_t width, uint32_t height) : RenderBackend(window, width, height) {
	}

	RenderBackendVulkan::~RenderBackendVulkan() {
		std::cout << "Destroy Render Backend Vulkan" << std::endl;
	}

	auto RenderBackendVulkan::Init() -> uint8_t {
		try {
			CreateVkInstance();
			CreateVkSurface();
			BindPhysicalDevice(QueryHighPerformanceGPU());
			auto caps = GetSwapchainCapabilities(_pDevice, _vSurface);
			CreateVKSwapchain(caps);
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
		for (auto image : _sImages) {
			vkDestroyImageView(_vDevice, image.View, nullptr);
		}
		vkDestroySwapchainKHR(_vDevice, _vSwapchain, nullptr);
		std::cout << "Deinit Swapchain" << std::endl;

		vkDestroySurfaceKHR(_vInstance, _vSurface, nullptr);
		std::cout << "Deinit Surface" << std::endl;

		vkDestroyDevice(_vDevice, nullptr);
		std::cout << "Deinit Device" << std::endl;

		vkDestroyInstance(_vInstance, nullptr);
		std::cout << "Deinit Instance" << std::endl;

		std::cout << "Deinit Render Backend Vulkan" << std::endl;
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

	auto RenderBackendVulkan::GetSwapchainCapabilities(VkPhysicalDevice device, VkSurfaceKHR surface) -> SwapchainCapabilities {
		SwapchainCapabilities caps = {};

		if (VK_SUCCESS != vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &caps.Capabilities)) {
			throw std::runtime_error("Failed getting vulkan device capabilties");
		}

		uint32_t formatCount = 0;
		if (VK_SUCCESS != vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, nullptr)) {
			throw std::runtime_error("Failed getting vulkan device formats");
		}

		if (formatCount != 0) {
			caps.Formats.resize(formatCount);

			if (VK_SUCCESS != vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, caps.Formats.data())) {
				throw std::runtime_error("Failed getting vulkan device formats");
			}
		}

		uint32_t presentationCount = 0;
		if (VK_SUCCESS != vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentationCount, nullptr)) {
			throw std::runtime_error("Failed getting vulkan device presentation modes");
		}

		if (presentationCount != 0) {
			caps.Modes.resize(presentationCount);

			if (VK_SUCCESS != vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentationCount, caps.Modes.data())) {
				throw std::runtime_error("Failed getting vulkan device formats");
			}
		}

		return caps;
	}

	auto RenderBackendVulkan::GetPreferedSwapchainFormat(SwapchainCapabilities& caps) -> VkSurfaceFormatKHR {
		if (caps.Formats.size() == 1 && caps.Formats[0].format == VK_FORMAT_UNDEFINED) {
			return { VK_FORMAT_R8G8B8_UNORM, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR };
		}

		for (const auto& format : caps.Formats) {
			if (
				(format.format == VK_FORMAT_R8G8B8_UNORM || format.format == VK_FORMAT_B8G8R8_UNORM)
				&& format.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
				return format;
			}
		}

		return caps.Formats[0];
	}

	auto RenderBackendVulkan::GetPreferedSwapchainPresentMode(SwapchainCapabilities& caps) -> VkPresentModeKHR {
		for (const auto& present : caps.Modes) {
			if (present == VK_PRESENT_MODE_MAILBOX_KHR) {
				return present;
			}
			else if (present == VK_PRESENT_MODE_IMMEDIATE_KHR) {
				return present;
			}
		}

		return VK_PRESENT_MODE_FIFO_KHR;
	}

	auto RenderBackendVulkan::GetPreferedSwapchainResolution(VkSurfaceCapabilitiesKHR& caps) -> VkExtent2D {
		if (caps.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
			return caps.currentExtent;
		}

		int32_t width = 0;
		int32_t height = 0;

		SDL_GetWindowSize(_window, &width, &height);

		VkExtent2D extent = {};
		extent.width = static_cast<uint32_t>(width);
		extent.height = static_cast<uint32_t>(height);

		extent.width = std::max(caps.minImageExtent.width, std::min(caps.maxImageExtent.width, extent.width));
		extent.height = std::max(caps.minImageExtent.height, std::min(caps.maxImageExtent.height, extent.height));

		return extent;
	}



	auto RenderBackendVulkan::CreateVKSwapchain(SwapchainCapabilities& config) -> void {
		auto format = GetPreferedSwapchainFormat(config);
		auto mode = GetPreferedSwapchainPresentMode(config);
		auto resolution = GetPreferedSwapchainResolution(config.Capabilities);

		uint32_t swapchainImages = config.Capabilities.minImageCount + 1;

		// No image limit
		if (config.Capabilities.maxImageCount > 0
			&& swapchainImages > config.Capabilities.maxImageCount) {
			swapchainImages = config.Capabilities.maxImageCount;
		}

		VkSwapchainCreateInfoKHR createInfo = {};
		createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		createInfo.presentMode = mode;
		createInfo.imageFormat = format.format;
		createInfo.imageColorSpace = format.colorSpace;
		createInfo.surface = _vSurface;
		createInfo.imageExtent = resolution;
		createInfo.minImageCount = swapchainImages;
		createInfo.imageArrayLayers = 1;
		createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		createInfo.preTransform = config.Capabilities.currentTransform;
		createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
		createInfo.clipped = VK_TRUE;

		auto queues = GetDeviceInfo(_pDevice);

		// Seperate queues, need to share images
		if (queues.GraphicsQueue != queues.PresentationQueue) {
			std::array<uint32_t, 2> queueIndices = {
				queues.GraphicsQueue,
				queues.PresentationQueue
			};
			createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
			createInfo.queueFamilyIndexCount = 2;
			createInfo.pQueueFamilyIndices = queueIndices.data();
		}
		else {
			createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
			createInfo.pQueueFamilyIndices = nullptr;
			createInfo.queueFamilyIndexCount = 0;
		}

		// Switching between swapchain(resize etc.)
		createInfo.oldSwapchain = VK_NULL_HANDLE;

		if (!VK_SUCCESS == vkCreateSwapchainKHR(_vDevice, &createInfo, nullptr, &_vSwapchain)) {
			throw std::runtime_error("Could not create vulkan swapchain");
		}

		_scImageFormat = format.format;
		_scExtent = resolution;

		uint32_t sImageCount = 0;
		if (VK_SUCCESS != vkGetSwapchainImagesKHR(_vDevice, _vSwapchain, &sImageCount, nullptr)) {
			throw std::runtime_error("Failed to get swapchain images");
		}

		std::vector<VkImage> images(sImageCount);

		if (VK_SUCCESS != vkGetSwapchainImagesKHR(_vDevice, _vSwapchain, &sImageCount, images.data())) {
			throw std::runtime_error("Failed to get swapchain images");
		}

		for (auto image : images) {
			SwapchainImage sImage = {};
			sImage.Image = image;
			sImage.View = CreateImageView(image, _scImageFormat, VK_IMAGE_ASPECT_COLOR_BIT);
			_sImages.push_back(sImage);
		}

	}

	auto RenderBackendVulkan::GetDeviceInfo(const VkPhysicalDevice device)->DeviceInfo& {
		DeviceInfo info = { };
		uint32_t queueFamCount = 0;
		auto props = VkPhysicalDeviceProperties{};
		vkGetPhysicalDeviceProperties(device, &props);
		if (props.deviceType == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			info.Discrete = true;
		}
		else if (props.deviceType == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU) {
			info.Discrete = false;
		}
		else {
			throw std::runtime_error("Unknown GPU type");
		}

		auto memoryProps = VkPhysicalDeviceMemoryProperties{};
		vkGetPhysicalDeviceMemoryProperties(device, &memoryProps);

		auto heapsPointer = memoryProps.memoryHeaps;
		auto heaps = std::vector<VkMemoryHeap>(heapsPointer, heapsPointer + memoryProps.memoryHeapCount);

		uint64_t memory = 0;

		for (const auto& heap : heaps) {
			if (heap.flags & VkMemoryHeapFlagBits::VK_MEMORY_HEAP_DEVICE_LOCAL_BIT) {
				memory += heap.size;
			}
		}

		info.VRAM = memory;

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

	auto RenderBackendVulkan::CreateImageView(VkImage image, VkFormat format, VkImageAspectFlags flags) -> VkImageView
	{
		VkImageViewCreateInfo info = {};
		info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		info.image = image;
		info.viewType = VK_IMAGE_VIEW_TYPE_2D;
		info.format = format;
		info.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
		info.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
		info.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
		info.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;

		// Resources -> Selective image components
		info.subresourceRange.aspectMask = flags; // Parts of image to be used
		info.subresourceRange.baseMipLevel = 0; // Start at first mipmaps
		info.subresourceRange.levelCount = 1; // Just one level of mipmaps
		info.subresourceRange.baseArrayLayer = 0; // Start array lvl to view from at 0
		info.subresourceRange.layerCount = 1; // Just one layer

		VkImageView view;
		if (VK_SUCCESS != vkCreateImageView(_vDevice, &info, nullptr, &view)) {
			throw std::runtime_error("Could not create image view");
		}

		return view;
	}

	auto RenderBackendVulkan::QueryHighPerformanceGPU() -> VkPhysicalDevice {
		uint32_t deviceCount = 0;
		if (VK_SUCCESS != vkEnumeratePhysicalDevices(_vInstance, &deviceCount, nullptr)) {
			throw std::runtime_error("Could not query device GPUs");
		}

		if (deviceCount == 0) {
			throw std::runtime_error("No Vulkan GPU device found");
		}

		std::vector<VkPhysicalDevice> devices(deviceCount);
		if (VK_SUCCESS != vkEnumeratePhysicalDevices(_vInstance, &deviceCount, devices.data())) {
			throw std::runtime_error("Could not query device GPUs");
		}

		bool hasValidDevice = false;
		VkPhysicalDevice targetDevice = {};
		VkPhysicalDeviceFeatures features = {};

		std::vector<DeviceInfo> infos = std::vector<DeviceInfo>();

		for (const auto& device : devices) {
			vkGetPhysicalDeviceFeatures(device, &features);
			auto caps = GetSwapchainCapabilities(device, _vSurface);
			auto info = GetDeviceInfo(device);
			info.Device = device;
			std::cout << info.VRAM << "b" << std::endl;
			std::cout << info.Discrete << std::endl;

			auto hasSupport = CheckVulkanDeviceExtensionsSupport(device);
			if (hasSupport) {
				bool validSwapchain = false;
				auto swapChainCaps = GetSwapchainCapabilities(device, _vSurface);
				validSwapchain = !swapChainCaps.Formats.empty() && !swapChainCaps.Modes.empty();

				if (info.IsValid() && hasSupport && validSwapchain) {
					infos.emplace_back(info);
					hasValidDevice = true;
				}
			}
		}

		std::sort(infos.begin(), infos.end(), [](DeviceInfo& lhs, DeviceInfo& rhs) {
			if (lhs.Discrete > rhs.Discrete) {
				return true;
			}
			else if (lhs.Discrete == rhs.Discrete) {
				if (lhs.VRAM > rhs.VRAM) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
			});

		if (!hasValidDevice) {
			throw std::runtime_error("No valid Graphics Processor found.");
		}

		return infos[0].Device;
	}
}