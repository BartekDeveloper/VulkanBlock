$doxydocs=
{
  classes => [
    {
      name => 'BlockyVulkan::Device',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'device.hpp'
      },
      all_members => [
        {
          name => 'beginSingleTimeCommands',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'checkDeviceExtensionSupport',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'checkValidationLayerSupport',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'commandPool',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'copyBuffer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'copyBufferToImage',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'createBuffer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'createCommandPool',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'createImageWithInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'createInstance',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'createLogicalDevice',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'createSurface',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'debugMessenger',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'Device',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'Device',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'Device',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'device',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'device_',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'deviceExtensions',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'enableValidationLayers',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'endSingleTimeCommands',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'findMemoryType',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'findPhysicalQueueFamilies',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'findQueueFamilies',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'findSupportedFormat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'getCommandPool',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'getRequiredExtensions',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'getSwapChainSupport',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'graphicsQueue',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'graphicsQueue_',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'hasGflwRequiredInstanceExtensions',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'instance',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'isDeviceSuitable',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'physicalDevice',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'pickPhysicalDevice',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'populateDebugMessengerCreateInfo',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'presentQueue',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'presentQueue_',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'properties',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'querySwapChainSupport',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'setupDebugMessenger',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'surface',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'surface_',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'validationLayers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => 'window',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Device'
        },
        {
          name => '~Device',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Device'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Device',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'window',
                type => 'Window &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~Device',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Device',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Device &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Device &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Device',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'Device &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Device &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'Device &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getCommandPool',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkCommandPool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'device',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkDevice',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'surface',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkSurfaceKHR',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'graphicsQueue',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkQueue',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'presentQueue',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkQueue',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getSwapChainSupport',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SwapChainSupportDetails',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'findMemoryType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'typeFilter',
                type => 'uint32_t'
              },
              {
                declaration_name => 'properties',
                type => 'VkMemoryPropertyFlags'
              }
            ]
          },
          {
            kind => 'function',
            name => 'findPhysicalQueueFamilies',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'QueueFamilyIndices',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'findSupportedFormat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkFormat',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'candidates',
                type => 'const std::vector< VkFormat > &'
              },
              {
                declaration_name => 'tiling',
                type => 'VkImageTiling'
              },
              {
                declaration_name => 'features',
                type => 'VkFormatFeatureFlags'
              }
            ]
          },
          {
            kind => 'function',
            name => 'createBuffer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'size',
                type => 'VkDeviceSize'
              },
              {
                declaration_name => 'usage',
                type => 'VkBufferUsageFlags'
              },
              {
                declaration_name => 'properties',
                type => 'VkMemoryPropertyFlags'
              },
              {
                declaration_name => 'buffer',
                type => 'VkBuffer &'
              },
              {
                declaration_name => 'bufferMemory',
                type => 'VkDeviceMemory &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'beginSingleTimeCommands',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkCommandBuffer',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'endSingleTimeCommands',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'commandBuffer',
                type => 'VkCommandBuffer'
              }
            ]
          },
          {
            kind => 'function',
            name => 'copyBuffer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'srcBuffer',
                type => 'VkBuffer'
              },
              {
                declaration_name => 'dstBuffer',
                type => 'VkBuffer'
              },
              {
                declaration_name => 'size',
                type => 'VkDeviceSize'
              }
            ]
          },
          {
            kind => 'function',
            name => 'copyBufferToImage',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'buffer',
                type => 'VkBuffer'
              },
              {
                declaration_name => 'image',
                type => 'VkImage'
              },
              {
                declaration_name => 'width',
                type => 'uint32_t'
              },
              {
                declaration_name => 'height',
                type => 'uint32_t'
              },
              {
                declaration_name => 'layerCount',
                type => 'uint32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'createImageWithInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'imageInfo',
                type => 'const VkImageCreateInfo &'
              },
              {
                declaration_name => 'properties',
                type => 'VkMemoryPropertyFlags'
              },
              {
                declaration_name => 'image',
                type => 'VkImage &'
              },
              {
                declaration_name => 'imageMemory',
                type => 'VkDeviceMemory &'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'enableValidationLayers',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const bool',
            initializer => '= true'
          },
          {
            kind => 'variable',
            name => 'properties',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPhysicalDeviceProperties'
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'createInstance',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setupDebugMessenger',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createSurface',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'pickPhysicalDevice',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createLogicalDevice',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createCommandPool',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'isDeviceSuitable',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'device',
                type => 'VkPhysicalDevice'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getRequiredExtensions',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< const char * >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'checkValidationLayerSupport',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'findQueueFamilies',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'QueueFamilyIndices',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'device',
                type => 'VkPhysicalDevice'
              }
            ]
          },
          {
            kind => 'function',
            name => 'populateDebugMessengerCreateInfo',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'createInfo',
                type => 'VkDebugUtilsMessengerCreateInfoEXT &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'hasGflwRequiredInstanceExtensions',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'checkDeviceExtensionSupport',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'device',
                type => 'VkPhysicalDevice'
              }
            ]
          },
          {
            kind => 'function',
            name => 'querySwapChainSupport',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SwapChainSupportDetails',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'device',
                type => 'VkPhysicalDevice'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'instance',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkInstance'
          },
          {
            kind => 'variable',
            name => 'debugMessenger',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkDebugUtilsMessengerEXT'
          },
          {
            kind => 'variable',
            name => 'physicalDevice',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPhysicalDevice',
            initializer => '= VK_NULL_HANDLE'
          },
          {
            kind => 'variable',
            name => 'window',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Window &'
          },
          {
            kind => 'variable',
            name => 'commandPool',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkCommandPool'
          },
          {
            kind => 'variable',
            name => 'device_',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkDevice'
          },
          {
            kind => 'variable',
            name => 'surface_',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkSurfaceKHR'
          },
          {
            kind => 'variable',
            name => 'graphicsQueue_',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkQueue'
          },
          {
            kind => 'variable',
            name => 'presentQueue_',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkQueue'
          },
          {
            kind => 'variable',
            name => 'validationLayers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const std::vector< const char * >',
            initializer => '= {"VK_LAYER_KHRONOS_validation"}'
          },
          {
            kind => 'variable',
            name => 'deviceExtensions',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const std::vector< const char * >',
            initializer => '= {VK_KHR_SWAPCHAIN_EXTENSION_NAME}'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::FirstTest',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'first_test.hpp'
      },
      all_members => [
        {
          name => 'commandBuffers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'CreateCommandBuffers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'CreatePipeline',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'CreatePipelineLayout',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'device',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'DrawFrame',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'FirstTest',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'FirstTest',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'FreeCommandBuffers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'gameObjects',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'HEIGHT',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'LoadGameObjects',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'pipeline',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'pipelineLayout',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'RecordCommandBuffer',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'RecreateSwapChain',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'RenderGameObjects',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'Run',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'Sierpinski',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'swapChain',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'WIDTH',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'window',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::FirstTest'
        },
        {
          name => '~FirstTest',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::FirstTest'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'FirstTest',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => '~FirstTest',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'FirstTest',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const FirstTest &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'FirstTest &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const FirstTest &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Run',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Sierpinski',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'vertices',
                type => 'std::vector< Model::Vertex > &'
              },
              {
                declaration_name => 'depth',
                type => 'int'
              },
              {
                declaration_name => 'left',
                type => 'glm::vec2'
              },
              {
                declaration_name => 'right',
                type => 'glm::vec2'
              },
              {
                declaration_name => 'top',
                type => 'glm::vec2'
              }
            ]
          }
        ]
      },
      public_static_members => {
        members => [
          {
            kind => 'variable',
            name => 'WIDTH',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static constexpr int',
            initializer => '{800}'
          },
          {
            kind => 'variable',
            name => 'HEIGHT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static constexpr int',
            initializer => '{600}'
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'LoadGameObjects',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'CreatePipelineLayout',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'CreatePipeline',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'CreateCommandBuffers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'FreeCommandBuffers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'DrawFrame',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'RecreateSwapChain',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'RecordCommandBuffer',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'imageIndex',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'RenderGameObjects',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'commandBuffer',
                type => 'VkCommandBuffer'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'window',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Window',
            initializer => '{WIDTH, HEIGHT, "Hello Vulkan!"}'
          },
          {
            kind => 'variable',
            name => 'device',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Device',
            initializer => '{window}'
          },
          {
            kind => 'variable',
            name => 'swapChain',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::unique_ptr< SwapChain >'
          },
          {
            kind => 'variable',
            name => 'pipeline',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::unique_ptr< Pipeline >'
          },
          {
            kind => 'variable',
            name => 'pipelineLayout',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineLayout'
          },
          {
            kind => 'variable',
            name => 'commandBuffers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkCommandBuffer >'
          },
          {
            kind => 'variable',
            name => 'gameObjects',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< GameObject >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::GameObject',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'game_object.hpp'
      },
      all_members => [
        {
          name => 'color',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'createGameObject',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'GameObject',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'GameObject',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'GameObject',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'GetId',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'id',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'id_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'model',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        },
        {
          name => 'transform2D',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::GameObject'
        }
      ],
      public_typedefs => {
        members => [
          {
            kind => 'typedef',
            name => 'id_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'unsigned int',
            initializer => ' unsigned int'
          }
        ]
      },
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'GameObject',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const GameObject &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'GameObject &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const GameObject &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'GameObject',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'GameObject &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'GameObject &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'GameObject &&'
              }
            ]
          },
          {
            kind => 'function',
            name => 'GetId',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const id_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'model',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::shared_ptr< Model >',
            initializer => '{}'
          },
          {
            kind => 'variable',
            name => 'color',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::vec3',
            initializer => '{}'
          },
          {
            kind => 'variable',
            name => 'transform2D',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Transform2D_Component',
            initializer => '{}'
          }
        ]
      },
      public_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'createGameObject',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static GameObject',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'GameObject',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'objId',
                type => 'id_t'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'id',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'id_t'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::Model',
      kind => 'class',
      inner => [
        {
          name => 'BlockyVulkan::Model::Vertex'
        }
      ],
      includes => {
        local => 'no',
        name => 'model.hpp'
      },
      all_members => [
        {
          name => 'Bind',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'CreateVertexBuffers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'device',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'Draw',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'Model',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'Model',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'vertexBuffer',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'vertexBufferMemory',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => 'vertexCount',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Model'
        },
        {
          name => '~Model',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Model',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'device',
                type => 'Device &'
              },
              {
                declaration_name => 'verticies',
                type => 'const std::vector< Vertex > &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~Model',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Model',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Model &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Model &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Model &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Bind',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'commandBuffer',
                type => 'VkCommandBuffer'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Draw',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'commandBuffer',
                type => 'VkCommandBuffer'
              }
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'CreateVertexBuffers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'verticies',
                type => 'const std::vector< Vertex > &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'device',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Device &'
          },
          {
            kind => 'variable',
            name => 'vertexBuffer',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkBuffer'
          },
          {
            kind => 'variable',
            name => 'vertexBufferMemory',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkDeviceMemory'
          },
          {
            kind => 'variable',
            name => 'vertexCount',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::Pipeline',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'pipeline.hpp'
      },
      all_members => [
        {
          name => 'Bind',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'CreateGraphicsPipeline',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'CreateShaderModule',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'DefaultPipelineConfigInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'Device',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'fragShaderModule',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'graphicsPipeline',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'Pipeline',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'Pipeline',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'Pipeline',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'ReadFile',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'vertShaderModule',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Pipeline'
        },
        {
          name => '~Pipeline',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Pipeline'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Pipeline',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'device',
                type => 'Device &'
              },
              {
                declaration_name => 'vertFilePath',
                type => 'const std::string &'
              },
              {
                declaration_name => 'fragFilePath',
                type => 'const std::string &'
              },
              {
                declaration_name => 'configInfo',
                type => 'const PipelineConfigInfo'
              }
            ]
          },
          {
            kind => 'function',
            name => '~Pipeline',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Pipeline',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Pipeline &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Pipeline &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Pipeline &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'Pipeline',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Bind',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'commandBuffer',
                type => 'VkCommandBuffer'
              }
            ]
          }
        ]
      },
      public_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'DefaultPipelineConfigInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'configInfo',
                type => 'PipelineConfigInfo &'
              }
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'CreateGraphicsPipeline',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'vertFilePath',
                type => 'const std::string &'
              },
              {
                declaration_name => 'fragFilePath',
                type => 'const std::string &'
              },
              {
                declaration_name => 'configInfo',
                type => 'const PipelineConfigInfo &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'CreateShaderModule',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'code',
                type => 'const std::vector< char > &'
              },
              {
                declaration_name => 'shaderModule',
                type => 'VkShaderModule *'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'Device',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Device &'
          },
          {
            kind => 'variable',
            name => 'graphicsPipeline',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipeline'
          },
          {
            kind => 'variable',
            name => 'vertShaderModule',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkShaderModule'
          },
          {
            kind => 'variable',
            name => 'fragShaderModule',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkShaderModule'
          }
        ]
      },
      private_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'ReadFile',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static std::vector< char >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'filePath',
                type => 'const std::string &'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::PipelineConfigInfo',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'pipeline.hpp'
      },
      all_members => [
        {
          name => 'colorBlendAttachment',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'colorBlendInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'depthStencilInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'dynamicStateEnables',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'dynamicStateInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'inputAssemblyInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'multisampleInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'PipelineConfigInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'pipelineLayout',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'rasterizationInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'renderPass',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'subpass',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'viewportInfo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::PipelineConfigInfo'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'PipelineConfigInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'PipelineConfigInfo &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const PipelineConfigInfo &'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'viewportInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineViewportStateCreateInfo'
          },
          {
            kind => 'variable',
            name => 'inputAssemblyInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineInputAssemblyStateCreateInfo'
          },
          {
            kind => 'variable',
            name => 'rasterizationInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineRasterizationStateCreateInfo'
          },
          {
            kind => 'variable',
            name => 'multisampleInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineMultisampleStateCreateInfo'
          },
          {
            kind => 'variable',
            name => 'colorBlendInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineColorBlendStateCreateInfo'
          },
          {
            kind => 'variable',
            name => 'depthStencilInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineDepthStencilStateCreateInfo'
          },
          {
            kind => 'variable',
            name => 'colorBlendAttachment',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineColorBlendAttachmentState'
          },
          {
            kind => 'variable',
            name => 'dynamicStateEnables',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkDynamicState >'
          },
          {
            kind => 'variable',
            name => 'dynamicStateInfo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineDynamicStateCreateInfo'
          },
          {
            kind => 'variable',
            name => 'pipelineLayout',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPipelineLayout',
            initializer => '= nullptr'
          },
          {
            kind => 'variable',
            name => 'renderPass',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkRenderPass',
            initializer => '= nullptr'
          },
          {
            kind => 'variable',
            name => 'subpass',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            initializer => '= 0'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::QueueFamilyIndices',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'device.hpp'
      },
      all_members => [
        {
          name => 'graphicsFamily',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::QueueFamilyIndices'
        },
        {
          name => 'graphicsFamilyHasValue',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::QueueFamilyIndices'
        },
        {
          name => 'isComplete',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::QueueFamilyIndices'
        },
        {
          name => 'presentFamily',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::QueueFamilyIndices'
        },
        {
          name => 'presentFamilyHasValue',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::QueueFamilyIndices'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'isComplete',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'graphicsFamily',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t'
          },
          {
            kind => 'variable',
            name => 'presentFamily',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t'
          },
          {
            kind => 'variable',
            name => 'graphicsFamilyHasValue',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            initializer => '= false'
          },
          {
            kind => 'variable',
            name => 'presentFamilyHasValue',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            initializer => '= false'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::SimplePushConstantData',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'color',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SimplePushConstantData'
        },
        {
          name => 'offset',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SimplePushConstantData'
        },
        {
          name => 'transform',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SimplePushConstantData'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'transform',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::mat2',
            initializer => '{1.f}'
          },
          {
            kind => 'variable',
            name => 'offset',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::vec2'
          },
          {
            kind => 'variable',
            name => 'color',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::vec3'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::SwapChain',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'swap_chain.hpp'
      },
      all_members => [
        {
          name => 'acquireNextImage',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'chooseSwapExtent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'chooseSwapPresentMode',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'chooseSwapSurfaceFormat',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'createDepthResources',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'createFramebuffers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'createImageViews',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'createRenderPass',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'createSwapChain',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'createSyncObjects',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'currentFrame',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'depthImageMemorys',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'depthImages',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'depthImageViews',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'device',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'extentAspectRatio',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'findDepthFormat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'getFrameBuffer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'getImageView',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'getRenderPass',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'getSwapChainExtent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'getSwapChainImageFormat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'height',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'imageAvailableSemaphores',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'imageCount',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'imagesInFlight',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'inFlightFences',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'Init',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'MAX_FRAMES_IN_FLIGHT',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'oldSwapChain',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'renderFinishedSemaphores',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'renderPass',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'submitCommandBuffers',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'SwapChain',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'SwapChain',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'SwapChain',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'swapChain',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'swapChainExtent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'swapChainFramebuffers',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'swapChainImageFormat',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'swapChainImages',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'swapChainImageViews',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'width',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'windowExtent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::SwapChain'
        },
        {
          name => '~SwapChain',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChain'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'SwapChain',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'deviceRef',
                type => 'Device &'
              },
              {
                declaration_name => 'windowExtent',
                type => 'VkExtent2D'
              }
            ]
          },
          {
            kind => 'function',
            name => 'SwapChain',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'deviceRef',
                type => 'Device &'
              },
              {
                declaration_name => 'windowExtent',
                type => 'VkExtent2D'
              },
              {
                declaration_name => 'previous',
                type => 'std::shared_ptr< SwapChain >'
              }
            ]
          },
          {
            kind => 'function',
            name => '~SwapChain',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'SwapChain',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const SwapChain &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SwapChain &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const SwapChain &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getFrameBuffer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkFramebuffer',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'index',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getRenderPass',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkRenderPass',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getImageView',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkImageView',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'index',
                type => 'int'
              }
            ]
          },
          {
            kind => 'function',
            name => 'imageCount',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getSwapChainImageFormat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkFormat',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getSwapChainExtent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkExtent2D',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'width',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'height',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'extentAspectRatio',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'float',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'findDepthFormat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkFormat',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'acquireNextImage',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkResult',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'imageIndex',
                type => 'uint32_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'submitCommandBuffers',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkResult',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'buffers',
                type => 'const VkCommandBuffer *'
              },
              {
                declaration_name => 'imageIndex',
                type => 'uint32_t *'
              }
            ]
          }
        ]
      },
      public_static_members => {
        members => [
          {
            kind => 'variable',
            name => 'MAX_FRAMES_IN_FLIGHT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static constexpr int',
            initializer => '= 2'
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'Init',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createSwapChain',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createImageViews',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createDepthResources',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createRenderPass',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createFramebuffers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createSyncObjects',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'chooseSwapSurfaceFormat',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkSurfaceFormatKHR',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'availableFormats',
                type => 'const std::vector< VkSurfaceFormatKHR > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'chooseSwapPresentMode',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkPresentModeKHR',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'availablePresentModes',
                type => 'const std::vector< VkPresentModeKHR > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'chooseSwapExtent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkExtent2D',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'capabilities',
                type => 'const VkSurfaceCapabilitiesKHR &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'swapChainImageFormat',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkFormat'
          },
          {
            kind => 'variable',
            name => 'swapChainExtent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkExtent2D'
          },
          {
            kind => 'variable',
            name => 'swapChainFramebuffers',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkFramebuffer >'
          },
          {
            kind => 'variable',
            name => 'renderPass',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkRenderPass'
          },
          {
            kind => 'variable',
            name => 'depthImages',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkImage >'
          },
          {
            kind => 'variable',
            name => 'depthImageMemorys',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkDeviceMemory >'
          },
          {
            kind => 'variable',
            name => 'depthImageViews',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkImageView >'
          },
          {
            kind => 'variable',
            name => 'swapChainImages',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkImage >'
          },
          {
            kind => 'variable',
            name => 'swapChainImageViews',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkImageView >'
          },
          {
            kind => 'variable',
            name => 'device',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Device &'
          },
          {
            kind => 'variable',
            name => 'windowExtent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkExtent2D'
          },
          {
            kind => 'variable',
            name => 'swapChain',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkSwapchainKHR'
          },
          {
            kind => 'variable',
            name => 'oldSwapChain',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::shared_ptr< SwapChain >'
          },
          {
            kind => 'variable',
            name => 'imageAvailableSemaphores',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkSemaphore >'
          },
          {
            kind => 'variable',
            name => 'renderFinishedSemaphores',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkSemaphore >'
          },
          {
            kind => 'variable',
            name => 'inFlightFences',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkFence >'
          },
          {
            kind => 'variable',
            name => 'imagesInFlight',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkFence >'
          },
          {
            kind => 'variable',
            name => 'currentFrame',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t',
            initializer => '= 0'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::SwapChainSupportDetails',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'device.hpp'
      },
      all_members => [
        {
          name => 'capabilities',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChainSupportDetails'
        },
        {
          name => 'formats',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChainSupportDetails'
        },
        {
          name => 'presentModes',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::SwapChainSupportDetails'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'capabilities',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkSurfaceCapabilitiesKHR'
          },
          {
            kind => 'variable',
            name => 'formats',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkSurfaceFormatKHR >'
          },
          {
            kind => 'variable',
            name => 'presentModes',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::vector< VkPresentModeKHR >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::Transform2D_Component',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'game_object.hpp'
      },
      all_members => [
        {
          name => 'mat2',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Transform2D_Component'
        },
        {
          name => 'translation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Transform2D_Component'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'mat2',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::mat2',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'translation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::vec2',
            initializer => '{}'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::Model::Vertex',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'model.hpp'
      },
      all_members => [
        {
          name => 'color',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model::Vertex'
        },
        {
          name => 'GetAttributeDescriptions',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model::Vertex'
        },
        {
          name => 'GetBindingDescriptions',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model::Vertex'
        },
        {
          name => 'position',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Model::Vertex'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'position',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::vec2'
          },
          {
            kind => 'variable',
            name => 'color',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'glm::vec3'
          }
        ]
      },
      public_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'GetBindingDescriptions',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static std::vector< VkVertexInputBindingDescription >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'GetAttributeDescriptions',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static std::vector< VkVertexInputAttributeDescription >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BlockyVulkan::Window',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'window.hpp'
      },
      all_members => [
        {
          name => 'CreateWindowSurface',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'FrameBufferResizeCallback',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'frameBufferResized',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'getExtend',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'height',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'InitWindow',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'name',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'ResetFlag_WindowResized',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'ShouldClose',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'WasWindowResized',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'width',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'Window',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'Window',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => 'window',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'BlockyVulkan::Window'
        },
        {
          name => '~Window',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BlockyVulkan::Window'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'Window',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'w',
                type => 'int'
              },
              {
                declaration_name => 'h',
                type => 'int'
              },
              {
                declaration_name => 'name',
                type => 'std::string'
              }
            ]
          },
          {
            kind => 'function',
            name => '~Window',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Window',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Window &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Window &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const Window &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'ShouldClose',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getExtend',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkExtent2D',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'WasWindowResized',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'ResetFlag_WindowResized',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'CreateWindowSurface',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'instance',
                type => 'VkInstance'
              },
              {
                declaration_name => 'surface',
                type => 'VkSurfaceKHR *'
              }
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'InitWindow',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'width',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'height',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int'
          },
          {
            kind => 'variable',
            name => 'frameBufferResized',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          },
          {
            kind => 'variable',
            name => 'name',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::string'
          },
          {
            kind => 'variable',
            name => 'window',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'GLFWwindow *'
          }
        ]
      },
      private_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'FrameBufferResizeCallback',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'window',
                type => 'GLFWwindow *'
              },
              {
                declaration_name => 'width',
                type => 'int'
              },
              {
                declaration_name => 'height',
                type => 'int'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  concepts => [
  ],
  modules => [
  ],
  namespaces => [
    {
      name => 'BlockyVulkan',
      classes => [
        {
          name => 'BlockyVulkan::Device'
        },
        {
          name => 'BlockyVulkan::FirstTest'
        },
        {
          name => 'BlockyVulkan::GameObject'
        },
        {
          name => 'BlockyVulkan::Model'
        },
        {
          name => 'BlockyVulkan::Pipeline'
        },
        {
          name => 'BlockyVulkan::PipelineConfigInfo'
        },
        {
          name => 'BlockyVulkan::QueueFamilyIndices'
        },
        {
          name => 'BlockyVulkan::SimplePushConstantData'
        },
        {
          name => 'BlockyVulkan::SwapChain'
        },
        {
          name => 'BlockyVulkan::SwapChainSupportDetails'
        },
        {
          name => 'BlockyVulkan::Transform2D_Component'
        },
        {
          name => 'BlockyVulkan::Window'
        }
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'debugCallback',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static VKAPI_ATTR VkBool32 VKAPI_CALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'messageSeverity',
                type => 'VkDebugUtilsMessageSeverityFlagBitsEXT'
              },
              {
                declaration_name => 'messageType',
                type => 'VkDebugUtilsMessageTypeFlagsEXT'
              },
              {
                declaration_name => 'pCallbackData',
                type => 'const VkDebugUtilsMessengerCallbackDataEXT *'
              },
              {
                declaration_name => 'pUserData',
                type => 'void *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'CreateDebugUtilsMessengerEXT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkResult',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'instance',
                type => 'VkInstance'
              },
              {
                declaration_name => 'pCreateInfo',
                type => 'const VkDebugUtilsMessengerCreateInfoEXT *'
              },
              {
                declaration_name => 'pAllocator',
                type => 'const VkAllocationCallbacks *'
              },
              {
                declaration_name => 'pDebugMessenger',
                type => 'VkDebugUtilsMessengerEXT *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'DestroyDebugUtilsMessengerEXT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'instance',
                type => 'VkInstance'
              },
              {
                declaration_name => 'debugMessenger',
                type => 'VkDebugUtilsMessengerEXT'
              },
              {
                declaration_name => 'pAllocator',
                type => 'const VkAllocationCallbacks *'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  files => [
    {
      name => 'main.cpp',
      includes => [
        {
          name => 'src/test_1/first_test.hpp',
          ref => 'first__test_8hpp'
        },
        {
          name => 'iostream'
        },
        {
          name => 'cstdlib'
        },
        {
          name => 'exception'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'device.cpp',
      includes => [
        {
          name => 'device.hpp',
          ref => 'device_8hpp'
        },
        {
          name => 'cstring'
        },
        {
          name => 'iostream'
        },
        {
          name => 'set'
        },
        {
          name => 'unordered_set'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'debugCallback',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static VKAPI_ATTR VkBool32 VKAPI_CALL',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'messageSeverity',
                type => 'VkDebugUtilsMessageSeverityFlagBitsEXT'
              },
              {
                declaration_name => 'messageType',
                type => 'VkDebugUtilsMessageTypeFlagsEXT'
              },
              {
                declaration_name => 'pCallbackData',
                type => 'const VkDebugUtilsMessengerCallbackDataEXT *'
              },
              {
                declaration_name => 'pUserData',
                type => 'void *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'CreateDebugUtilsMessengerEXT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'VkResult',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'instance',
                type => 'VkInstance'
              },
              {
                declaration_name => 'pCreateInfo',
                type => 'const VkDebugUtilsMessengerCreateInfoEXT *'
              },
              {
                declaration_name => 'pAllocator',
                type => 'const VkAllocationCallbacks *'
              },
              {
                declaration_name => 'pDebugMessenger',
                type => 'VkDebugUtilsMessengerEXT *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'DestroyDebugUtilsMessengerEXT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'instance',
                type => 'VkInstance'
              },
              {
                declaration_name => 'debugMessenger',
                type => 'VkDebugUtilsMessengerEXT'
              },
              {
                declaration_name => 'pAllocator',
                type => 'const VkAllocationCallbacks *'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'device.hpp',
      includes => [
        {
          name => 'vulkan/vulkan.h'
        },
        {
          name => '../window/window.hpp',
          ref => 'window_8hpp'
        },
        {
          name => 'string'
        },
        {
          name => 'vector'
        }
      ],
      included_by => [
        {
          name => 'device.cpp',
          ref => 'device_8cpp'
        },
        {
          name => 'first_test.hpp',
          ref => 'first__test_8hpp'
        },
        {
          name => 'model.hpp',
          ref => 'model_8hpp'
        },
        {
          name => 'pipeline.cpp',
          ref => 'pipeline_8cpp'
        },
        {
          name => 'pipeline.hpp',
          ref => 'pipeline_8hpp'
        },
        {
          name => 'swap_chain.hpp',
          ref => 'swap__chain_8hpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'game_object.cpp',
      includes => [
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'game_object.hpp',
      includes => [
        {
          name => 'glm/glm.hpp'
        },
        {
          name => '../model/model.hpp',
          ref => 'model_8hpp'
        },
        {
          name => 'memory'
        }
      ],
      included_by => [
        {
          name => 'first_test.hpp',
          ref => 'first__test_8hpp'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'GLM_FORCE_RADIANS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          },
          {
            kind => 'define',
            name => 'GLM_FORCE_DEPTH_ZERO_TO_ONE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'model.cpp',
      includes => [
        {
          name => 'model.hpp',
          ref => 'model_8hpp'
        },
        {
          name => 'cassert'
        },
        {
          name => 'cstring'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'model.hpp',
      includes => [
        {
          name => '../device/device.hpp',
          ref => 'device_8hpp'
        },
        {
          name => 'vulkan/vulkan.h'
        },
        {
          name => 'glm/glm.hpp'
        },
        {
          name => 'vector'
        }
      ],
      included_by => [
        {
          name => 'first_test.hpp',
          ref => 'first__test_8hpp'
        },
        {
          name => 'game_object.hpp',
          ref => 'game__object_8hpp'
        },
        {
          name => 'model.cpp',
          ref => 'model_8cpp'
        },
        {
          name => 'pipeline.cpp',
          ref => 'pipeline_8cpp'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'GLM_FORCE_RADIANS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          },
          {
            kind => 'define',
            name => 'GLM_FORCE_DEPTH_ZERO_TO_ONE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'pipeline.cpp',
      includes => [
        {
          name => 'pipeline.hpp',
          ref => 'pipeline_8hpp'
        },
        {
          name => 'cassert'
        },
        {
          name => 'fstream'
        },
        {
          name => 'iosfwd'
        },
        {
          name => 'iostream'
        },
        {
          name => 'stdexcept'
        },
        {
          name => '../model/model.hpp',
          ref => 'model_8hpp'
        },
        {
          name => '../device/device.hpp',
          ref => 'device_8hpp'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'pipeline.hpp',
      includes => [
        {
          name => '../device/device.hpp',
          ref => 'device_8hpp'
        },
        {
          name => 'string'
        },
        {
          name => 'vector'
        }
      ],
      included_by => [
        {
          name => 'first_test.hpp',
          ref => 'first__test_8hpp'
        },
        {
          name => 'pipeline.cpp',
          ref => 'pipeline_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'swap_chain.cpp',
      includes => [
        {
          name => 'swap_chain.hpp',
          ref => 'swap__chain_8hpp'
        },
        {
          name => 'array'
        },
        {
          name => 'cstdlib'
        },
        {
          name => 'cstring'
        },
        {
          name => 'iostream'
        },
        {
          name => 'limits'
        },
        {
          name => 'set'
        },
        {
          name => 'stdexcept'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'swap_chain.hpp',
      includes => [
        {
          name => '../device/device.hpp',
          ref => 'device_8hpp'
        },
        {
          name => 'vulkan/vulkan.h'
        },
        {
          name => 'memory'
        },
        {
          name => 'string'
        },
        {
          name => 'vector'
        }
      ],
      included_by => [
        {
          name => 'first_test.hpp',
          ref => 'first__test_8hpp'
        },
        {
          name => 'swap_chain.cpp',
          ref => 'swap__chain_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'first_test.cpp',
      includes => [
        {
          name => 'first_test.hpp',
          ref => 'first__test_8hpp'
        },
        {
          name => 'glm/glm.hpp'
        },
        {
          name => 'array'
        },
        {
          name => 'iostream'
        },
        {
          name => 'stdexcept'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'GLM_FORCE_RADIANS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          },
          {
            kind => 'define',
            name => 'GLM_FORCE_DEPTH_ZERO_TO_ONE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'first_test.hpp',
      includes => [
        {
          name => '../device/device.hpp',
          ref => 'device_8hpp'
        },
        {
          name => '../game_object/game_object.hpp',
          ref => 'game__object_8hpp'
        },
        {
          name => '../model/model.hpp',
          ref => 'model_8hpp'
        },
        {
          name => '../pipeline/pipeline.hpp',
          ref => 'pipeline_8hpp'
        },
        {
          name => '../swapchain/swap_chain.hpp',
          ref => 'swap__chain_8hpp'
        },
        {
          name => '../window/window.hpp',
          ref => 'window_8hpp'
        },
        {
          name => 'memory'
        },
        {
          name => 'vector'
        }
      ],
      included_by => [
        {
          name => 'first_test.cpp',
          ref => 'first__test_8cpp'
        },
        {
          name => 'main.cpp',
          ref => 'main_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'window.cpp',
      includes => [
        {
          name => 'window.hpp',
          ref => 'window_8hpp'
        },
        {
          name => 'stdexcept'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'window.hpp',
      includes => [
        {
          name => 'vulkan/vulkan.h'
        },
        {
          name => 'GLFW/glfw3.h'
        },
        {
          name => 'string'
        }
      ],
      included_by => [
        {
          name => 'device.hpp',
          ref => 'device_8hpp'
        },
        {
          name => 'first_test.hpp',
          ref => 'first__test_8hpp'
        },
        {
          name => 'window.cpp',
          ref => 'window_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    }
  ],
  groups => [
  ],
  pages => [
  ]
};
1;
