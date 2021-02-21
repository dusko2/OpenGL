#include <fstream>
#include <sstream>
#include <iostream>

#include "../../Utils/IntTypes.h"

#include "ShaderLoader.h"

ShaderLoader::ShaderLoader(const char* filepath) : filepath(filepath) {}

ShaderLoader::~ShaderLoader() {
    shaderSources.clear();
}

void ShaderLoader::Load() {
    shaderSources.clear();

    std::ifstream input(filepath);

    std::string line;
    std::unordered_map<std::string, std::stringstream> sourcesBuilder;

    std::string currentSourceName;

    while (getline(input, line)) {
        if (line.find("#shader-name") != std::string::npos) {
            currentSourceName = line;
            sourcesBuilder[line] = std::stringstream();
            continue;
        }

        sourcesBuilder[currentSourceName] << line << "\n";
    }

    for (auto& sourceBuilder : sourcesBuilder) {
        const std::string& shaderHeader = sourceBuilder.first;
        std::string shaderName = shaderHeader.substr(shaderHeader.find(":") + 1, shaderHeader.size());

        shaderSources[shaderName] = sourceBuilder.second.str();
    }
}
