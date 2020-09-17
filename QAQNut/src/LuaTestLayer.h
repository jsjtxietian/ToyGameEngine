#pragma once

#include "QAQ.h"

namespace QAQ
{
    class LuaTestLayer : public Layer
    {
    public:
        LuaTestLayer() = default;
        virtual ~LuaTestLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void OnUpdate(Timestep ts) override { ScriptOnUpdate(ts); };
        virtual void OnImGuiRender() override{};
        void OnEvent(Event &e) override{};

    private:
        
		void LuaBindTest();
        std::function<void(Timestep)> ScriptOnUpdate = [](Timestep ts) { QAQ_CORE_INFO("Before Init"); };
		sol::state lua;
    };
} // namespace QAQ
