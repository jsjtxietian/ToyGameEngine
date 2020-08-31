#pragma once

#include "QAQ.h"

class ExampleLayer : public QAQ::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(QAQ::TimeStep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(QAQ::Event& e) override;
private:
	QAQ::ShaderLibrary m_ShaderLibrary;
	QAQ::Ref<QAQ::Shader> m_Shader;
	QAQ::Ref<QAQ::VertexArray> m_VertexArray;

	QAQ::Ref<QAQ::Shader> m_FlatColorShader;
	QAQ::Ref<QAQ::VertexArray> m_SquareVA;

	QAQ::Ref<QAQ::Texture2D> m_Texture, m_ChernoLogoTexture;

	QAQ::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
}; 