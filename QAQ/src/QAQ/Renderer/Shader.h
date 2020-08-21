#pragma once
#include <string.h>
#include <glm/glm.hpp>

namespace QAQ
{
	class Shader
	{
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);

		void Bind() const;
		void UnBind() const;

	private:
		uint32_t m_RendererID;
	};
}