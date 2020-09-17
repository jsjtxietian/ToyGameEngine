#include "qaqpch.h"

#define SOL_ALL_SAFETIES_ON 1

#include "LuaTestLayer.h"

namespace QAQ
{
	void LuaTestLayer::OnAttach()
	{
		LuaBindTest();
	}

	void LuaTestLayer::OnDetach()
	{
	}

	//https://sol2.readthedocs.io/en/latest/tutorial/all-the-things.html
	void LuaTestLayer::LuaBindTest()
	{
		lua.open_libraries();

		sol::usertype<Timestep> ts = lua.new_usertype<Timestep>("timestep",
			sol::constructors<Timestep(),Timestep(float)>());
		ts["get"] = &Timestep::GetSeconds;

		lua.script_file("src/scripts/testSol.lua");

		sol::function fx = lua["OnUpdate"];
		ScriptOnUpdate = fx;

		
	}

} // namespace QAQ
