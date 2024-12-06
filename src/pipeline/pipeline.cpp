#include "pipeline.hpp"

#include <iostream>
#include <fstream>
#include <iosfwd>
#include <stdexcept>

namespace BlockyVulkan {
    Pipeline::Pipeline( const std::string &vertFilePath, const std::string &fragFilePath ) {
        CreateGraphicsPipeline( vertFilePath, fragFilePath );
    }

    std::vector<char> Pipeline::ReadFile( const std::string &filePath ) {
        std::ifstream file{ filePath, std::ios::ate | std::ios::binary };
    
        if( !file.is_open() ) {
            throw std::runtime_error( "Failed to open file: " + filePath );
        }

        size_t fileSize = static_cast<size_t>( file.tellg() );
        std::vector<char> buffer( fileSize );

        file.seekg( 0 );
        file.read( buffer.data(), fileSize );

        file.close();
        return buffer;
    }

    void Pipeline::CreateGraphicsPipeline( const std::string &vertFilePath, const std::string &fragFilePath ) {
        auto vertCode = ReadFile( vertFilePath );
        auto fragCode = ReadFile( fragFilePath );

        std::cout << "Vert Shader Code Size: " << vertCode.size() << "\n";
        std::cout << "Frag Shader Code Size: " << fragCode.size() << "\n";
    }
}