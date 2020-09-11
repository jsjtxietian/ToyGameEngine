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

        void OnUpdate(Timestep ts) override {};
        virtual void OnImGuiRender() override {};
        void OnEvent(Event &e) override {};

    private:
		void RawLuaTest();

        bool CheckLua(lua_State *L, int r);// Little error checking utility function
        void LuaBindTest();

        lua_State *L;
    };
} // namespace QAQ
