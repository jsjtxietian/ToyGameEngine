#pragma once

#include "QAQ.h"
#include "ParticleSystem.h"

class Sandbox2D : public QAQ::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(QAQ::TimeStep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(QAQ::Event& e) override;

private:
	QAQ::OrthographicCameraController m_CameraController;

	// Temp
	QAQ::Ref<QAQ::VertexArray> m_SquareVA;
	QAQ::Ref<QAQ::Shader> m_FlatColorShader;

	QAQ::Ref<QAQ::Texture2D> m_CheckerboardTexture;
	QAQ::Ref<QAQ::Texture2D> m_SpriteSheet;
	QAQ::Ref<QAQ::SubTexture2D> m_TextureStairs, m_TextureBarriers , m_TextureTree;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

	ParticleProps m_Particle;
	ParticleSystem m_ParticleSystem;
};