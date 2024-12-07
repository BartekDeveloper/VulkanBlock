#pragma once

#include "../device/device.hpp"


// std
#include <string>
#include <vector>

namespace BlockyVulkan {

struct PipelineConfigInfo {
    VkViewport viewport;
    VkRect2D scissor;
                                                                                    
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
   
    VkPipelineColorBlendAttachmentState colorBlendAttachment;

    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
};

class Pipeline {
 public:
  Pipeline(Device &device, const std::string &vertFilePath,
           const std::string &fragFilePath,
           const PipelineConfigInfo configInfo);
  ~Pipeline();

  Pipeline( const Pipeline & ) = delete;
  Pipeline &operator=( const Pipeline & ) = delete;
  Pipeline() = default;

  void Bind( VkCommandBuffer commandBuffer );

  static PipelineConfigInfo DefaultPipelineConfigInfo( uint32_t width, uint32_t height );

 private:
  static std::vector<char> ReadFile(const std::string &filePath);

  void CreateGraphicsPipeline(const std::string &vertFilePath,
                              const std::string &fragFilePath,
                              const PipelineConfigInfo &configInfo);

  void CreateShaderModule( const std::vector<char> &code, VkShaderModule *shaderModule );

  Device &Device;
  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;

};
}  // namespace BlockyVulkan