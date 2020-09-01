#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{

}

void Sandbox2D::OnAttach()
{
	QAQ_PROFILE_FUNCTION();

	m_CheckerboardTexture = QAQ::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	QAQ_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(QAQ::TimeStep ts)
{
	QAQ_PROFILE_FUNCTION();
	// Update
	m_CameraController.OnUpdate(ts);

	{
		QAQ_PROFILE_SCOPE("Renderer Prep");
		QAQ::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		QAQ::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 5.0f;

		QAQ_PROFILE_SCOPE("Renderer Draw");
		QAQ::Renderer2D::BeginScene(m_CameraController.GetCamera());
		
		QAQ::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		QAQ::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		QAQ::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		QAQ::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		QAQ::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		
		QAQ::Renderer2D::EndScene();
	}

}

void Sandbox2D::OnImGuiRender()
{
	QAQ_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(QAQ::Event& e)
{
	m_CameraController.OnEvent(e);
}