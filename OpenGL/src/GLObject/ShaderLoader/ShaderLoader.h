#pragma once

#include <unordered_map>
#include <string>

class ShaderLoader {

	public:
		static ShaderLoader& GetInstance() {
			static ShaderLoader instance("res/shaders/Basic.shader");
			return instance;
		}

	private:
		const char* filepath;
		std::unordered_map<std::string, std::string> shaderSources;

	private:
		ShaderLoader(const char* filepath);

	public:
		~ShaderLoader();

		void Load();

		inline const char* GetSource(std::string shaderName) {
			return shaderSources[shaderName].c_str();
		}
};
