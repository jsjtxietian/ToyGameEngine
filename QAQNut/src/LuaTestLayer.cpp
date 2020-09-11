#include "qaqpch.h"
#include "LuaTestLayer.h"

#define SOL_ALL_SAFETIES_ON 1

namespace QAQ
{
	void LuaTestLayer::OnAttach()
	{
		// RawLuaTest();
		LuaBindTest();
	}

	void LuaTestLayer::OnDetach()
	{
		//lua_close(L);
	}

	//https://sol2.readthedocs.io/en/latest/tutorial/all-the-things.html
	void LuaTestLayer::LuaBindTest()
	{
		//sol::state lua;
		//lua.open_libraries();

		//sol::usertype<glm::vec2> vec2_type = lua.new_usertype<glm::vec2>("vec2",
		//	sol::constructors<glm::vec2(),glm::vec2(float,float)>());
		//vec2_type["x"] = &glm::vec2::x;
		//vec2_type["y"] = &glm::vec2::y;
		//glm::vec2 test = glm::vec2{ 1.0f,2.0f };
		//lua["CppVec2"] = &test;

		//typedef struct ts {
		//	float time;
		//	float getTime() { return time; }
		//} ts;

		//sol::usertype<ts> timestep_type = lua.new_usertype<ts>("timestep",
		//	"get", &ts::getTime);

		//lua.script_file("src/scripts/testSol.lua");

		//sol::function fx = lua["OnUpdate"];
		//std::function<void(ts)> stdfx = fx;
		//stdfx(ts{5.0f});

		struct foo {
		private:
			std::string name;
		public:
			foo(std::string name) : name(std::string(name)) {}

			void print() {
				std::cout << name << '\n';
			}

			int test(int x) {
				return static_cast<int>(name.length() + x);
			}
		};

		std::cout << "=== usertype ===" << std::endl;

		sol::state lua;
		lua.open_libraries(sol::lib::base, sol::lib::math);

		// the simplest way to create a class is through
		// sol::state::new_userdata
		// the first template is the class type
		// the rest are the constructor parameters
		// using new_userdata you can only have one constructor


		// you must make sure that the name of the function
		// goes before the member function pointer
		lua.new_usertype<foo>("foo", sol::constructors<foo(std::string)>(),
			"print", &foo::print,
			"test", &foo::test);

		// making the class from lua is simple
		// same with calling member functions
		lua.script("x = foo.new('test')\n"
			"x:print()\n"
			"y = x:test(10)");

		std::cout << std::endl;

	}



	struct Player
	{
		std::string title;
		std::string name;
		std::string family;
		int level;
	} player;

	int lua_HostFunction(lua_State* L)
	{
		float a = (float)lua_tonumber(L, 1);
		float b = (float)lua_tonumber(L, 2);
		std::cout << "[CPP S4] HostFunction(" << a << ", " << b << ") called from Lua" << std::endl;
		float c = a * b;
		lua_pushnumber(L, c);
		return 1;
	}

	void LuaTestLayer::RawLuaTest()
	{
		// Create Lua State
		L = luaL_newstate();

		// Add standard libraries to Lua Virtual Machine
		luaL_openlibs(L);

		// Register our C++ Function in the global Lua space
		lua_register(L, "HostFunction", lua_HostFunction);

		// Load and parse the Lua File
		if (CheckLua(L, luaL_dofile(L, "src/scripts/test.lua")))
		{
			// Stage 1: Just read simple variables
			std::cout << "[CPP] Stage 1 - Read Simple Variables" << std::endl;
			lua_getglobal(L, "a");
			if (lua_isnumber(L, -1))
				std::cout << "[CPP S1] a = " << (int)lua_tointeger(L, -1) << std::endl;
			lua_getglobal(L, "b");
			if (lua_isnumber(L, -1))
				std::cout << "[CPP S1] b = " << (int)lua_tointeger(L, -1) << std::endl;
			lua_getglobal(L, "c");
			if (lua_isnumber(L, -1))
				std::cout << "[CPP S1] c = " << (int)lua_tointeger(L, -1) << std::endl;
			lua_getglobal(L, "d");
			if (lua_isstring(L, -1))
				std::cout << "[CPP S1] d = " << lua_tostring(L, -1) << std::endl
				<< std::endl;

			// Stage 2: Read Table Object
			std::cout << "[CPP] Stage 2 - Read Table (Key/Value pairs)" << std::endl;
			lua_getglobal(L, "player");
			if (lua_istable(L, -1))
			{
				lua_pushstring(L, "Name");
				lua_gettable(L, -2);
				player.name = lua_tostring(L, -1);
				lua_pop(L, 1);

				lua_pushstring(L, "Family");
				lua_gettable(L, -2);
				player.family = lua_tostring(L, -1);
				lua_pop(L, 1);

				lua_pushstring(L, "Title");
				lua_gettable(L, -2);
				player.title = lua_tostring(L, -1);
				lua_pop(L, 1);

				lua_pushstring(L, "Level");
				lua_gettable(L, -2);
				player.level = (int)lua_tointeger(L, -1);
				lua_pop(L, 1);
			}
			std::cout << "[CPP S2] " << player.title << " " << player.name << " of " << player.family << " [Lvl: " << player.level << "]" << std::endl
				<< std::endl;

			// Stage 3: Call Lua Function
			std::cout << "[CPP] Stage 3 - Call Lua Function" << std::endl;
			lua_getglobal(L, "CalledFromCPP1");
			if (lua_isfunction(L, -1))
			{
				lua_pushnumber(L, 5.0f);
				lua_pushnumber(L, 6.0f);
				lua_pushstring(L, "Bwa ha ha!");
				std::cout << "[CPP S3] Calling 'CalledFromCPP1' in lua script" << std::endl;
				if (CheckLua(L, lua_pcall(L, 3, 1, 0)))
				{
					std::cout << "[CPP S3] 'CalledFromCPP1' returned " << (float)lua_tonumber(L, -1) << std::endl
						<< std::endl;
				}
			}

			// Stage 4: Call Lua Function, which calls C++ Function
			std::cout << "[CPP] Stage 4 - Call Lua Function, whcih in turn calls C++ Function" << std::endl;
			lua_getglobal(L, "CalledFromCPP2");
			if (lua_isfunction(L, -1))
			{
				lua_pushnumber(L, 5.0f);
				lua_pushnumber(L, 6.0f);
				std::cout << "[CPP S4] Calling 'CalledFromCPP2' in lua script" << std::endl;
				if (CheckLua(L, lua_pcall(L, 2, 1, 0)))
				{
					std::cout << "[CPP S4] 'CalledFromCPP2' returned " << (float)lua_tonumber(L, -1) << std::endl
						<< std::endl;
				}
			}
		}
	}

	bool LuaTestLayer::CheckLua(lua_State* L, int r)
	{
		if (r != LUA_OK)
		{
			std::string errormsg = lua_tostring(L, -1);
			std::cout << errormsg << std::endl;
			return false;
		}
		return true;
	}

} // namespace QAQ
