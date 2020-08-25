#include "qaqpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace QAQ {

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case QAQ::ShaderDataType::Float:    return GL_FLOAT;
		case QAQ::ShaderDataType::Float2:   return GL_FLOAT;
		case QAQ::ShaderDataType::Float3:   return GL_FLOAT;
		case QAQ::ShaderDataType::Float4:   return GL_FLOAT;
		case QAQ::ShaderDataType::Mat3:     return GL_FLOAT;
		case QAQ::ShaderDataType::Mat4:     return GL_FLOAT;
		case QAQ::ShaderDataType::Int:      return GL_INT;
		case QAQ::ShaderDataType::Int2:     return GL_INT;
		case QAQ::ShaderDataType::Int3:     return GL_INT;
		case QAQ::ShaderDataType::Int4:     return GL_INT;
		case QAQ::ShaderDataType::Bool:     return GL_BOOL;
		}

		QAQ_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
	{
		QAQ_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)(intptr_t)element.Offset);
			m_VertexBufferIndex++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}