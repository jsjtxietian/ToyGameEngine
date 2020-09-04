#pragma once

#include "QAQ.h"

namespace QAQ {
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(TimeStep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;

	private:
		OrthographicCameraController m_CameraController;

		// Temp
		Ref<Shader> m_FlatColorShader;
		Ref<Texture2D> m_CheckerboardTexture;

		Ref<Framebuffer> m_Framebuffer;

		bool m_ViewportFocused = false;
		bool m_ViewportHovered = false;

		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
		glm::vec2 m_viewportSize = { 0,0 };

		std::unordered_map<char, Ref<SubTexture2D>> s_TextureMap;
	};
}

