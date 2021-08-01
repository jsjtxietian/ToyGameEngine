#include "TestingLayer.h"
#include <imgui/imgui.h>
#include <d3d11.h>

TestingLayer::TestingLayer()
	: Layer("TestingLayer")
{
	TestDynamicConstant();
}

void TestingLayer::TestDynamicConstant()
{
	using namespace std::string_literals;
	namespace dx = DirectX;
	// data roundtrip tests
	{
		QAQ::Dcb::RawLayout s;
		s.Add<QAQ::Dcb::Struct>("butts"s);
		s["butts"s].Add<QAQ::Dcb::Float3>("pubes"s);
		s["butts"s].Add<QAQ::Dcb::Float>("dank"s);
		s.Add<QAQ::Dcb::Float>("woot"s);
		s.Add<QAQ::Dcb::Array>("arr"s);
		s["arr"s].Set<QAQ::Dcb::Struct>(4);
		s["arr"s].T().Add<QAQ::Dcb::Float3>("twerk"s);
		s["arr"s].T().Add<QAQ::Dcb::Array>("werk"s);
		s["arr"s].T()["werk"s].Set<QAQ::Dcb::Float>(6);
		s["arr"s].T().Add<QAQ::Dcb::Array>("meta"s);
		s["arr"s].T()["meta"s].Set<QAQ::Dcb::Array>(6);
		s["arr"s].T()["meta"s].T().Set<QAQ::Dcb::Matrix>(4);
		s["arr"s].T().Add<QAQ::Dcb::Bool>("booler");

		// fails: duplicate symbol name
		// s.Add<QAQ::Dcb::Bool>( "arr"s );

		// fails: bad symbol name
		//s.Add<QAQ::Dcb::Bool>( "69man" );

		auto b = QAQ::Dcb::Buffer(std::move(s));

		// fails to compile: conversion not in type map
		//b["woot"s] = "#"s;

		const auto sig = b.GetRootLayoutElement().GetSignature();

		{
			auto exp = 42.0f;
			b["woot"s] = exp;
			float act = b["woot"s];
			QAQ_ASSERT(act == exp);
		}
		{
			auto exp = 420.0f;
			b["butts"s]["dank"s] = exp;
			float act = b["butts"s]["dank"s];
			QAQ_ASSERT(act == exp);
		}
		{
			auto exp = 111.0f;
			b["arr"s][2]["werk"s][5] = exp;
			float act = b["arr"s][2]["werk"s][5];
			QAQ_ASSERT(act == exp);
		}
		{
			auto exp = DirectX::XMFLOAT3{69.0f, 0.0f, 0.0f};
			b["butts"s]["pubes"s] = exp;
			dx::XMFLOAT3 act = b["butts"s]["pubes"s];
			QAQ_ASSERT(!std::memcmp(&exp, &act, sizeof(DirectX::XMFLOAT3)));
		}
		{
			DirectX::XMFLOAT4X4 exp;
			dx::XMStoreFloat4x4(
				&exp,
				dx::XMMatrixIdentity());
			b["arr"s][2]["meta"s][5][3] = exp;
			dx::XMFLOAT4X4 act = b["arr"s][2]["meta"s][5][3];
			QAQ_ASSERT(!std::memcmp(&exp, &act, sizeof(DirectX::XMFLOAT4X4)));
		}
		{
			auto exp = true;
			b["arr"s][2]["booler"s] = exp;
			bool act = b["arr"s][2]["booler"s];
			QAQ_ASSERT(act == exp);
		}
		{
			auto exp = false;
			b["arr"s][2]["booler"s] = exp;
			bool act = b["arr"s][2]["booler"s];
			QAQ_ASSERT(act == exp);
		}
		// exists
		{
			QAQ_ASSERT(b["butts"s]["pubes"s].Exists());
			QAQ_ASSERT(!b["butts"s]["fubar"s].Exists());
			if (auto ref = b["butts"s]["pubes"s]; ref.Exists())
			{
				dx::XMFLOAT3 f = ref;
				QAQ_ASSERT(f.x == 69.0f);
			}
		}
		// set if exists
		{
			QAQ_ASSERT(b["butts"s]["pubes"s].SetIfExists(dx::XMFLOAT3{1.0f, 2.0f, 3.0f}));
			auto &f3 = static_cast<const dx::XMFLOAT3 &>(b["butts"s]["pubes"s]);
			QAQ_ASSERT(f3.x == 1.0f && f3.y == 2.0f && f3.z == 3.0f);
			QAQ_ASSERT(!b["butts"s]["phubar"s].SetIfExists(dx::XMFLOAT3{2.0f, 2.0f, 7.0f}));
		}

		// this fails assertion: array out of bounds
		// cb["arr"s][200];
	}
	// size test array of arrays
	{
		QAQ::Dcb::RawLayout s;
		s.Add<QAQ::Dcb::Array>("arr");
		s["arr"].Set<QAQ::Dcb::Array>(6);
		s["arr"].T().Set<QAQ::Dcb::Matrix>(4);
		auto b = QAQ::Dcb::Buffer(std::move(s));

		auto act = b.GetSizeInBytes();
		QAQ_ASSERT(act == 16u * 4u * 4u * 6u);
	}
	// size test array of floats
	{
		QAQ::Dcb::RawLayout s;
		s.Add<QAQ::Dcb::Array>("arr");
		s["arr"].Set<QAQ::Dcb::Float>(16);
		auto b = QAQ::Dcb::Buffer(std::move(s));

		auto act = b.GetSizeInBytes();
		QAQ_ASSERT(act == 256u);
	}
	// size test array of structs with padding
	{
		QAQ::Dcb::RawLayout s;
		s.Add<QAQ::Dcb::Array>("arr");
		s["arr"].Set<QAQ::Dcb::Struct>(6);
		s["arr"s].T().Add<QAQ::Dcb::Float2>("a");
		s["arr"].T().Add<QAQ::Dcb::Float3>("b"s);
		auto b = QAQ::Dcb::Buffer(std::move(s));

		auto act = b.GetSizeInBytes();
		QAQ_ASSERT(act == 16u * 2u * 6u);
	}
	// size test array of primitive that needs padding
	{
		QAQ::Dcb::RawLayout s;
		s.Add<QAQ::Dcb::Array>("arr");
		s["arr"].Set<QAQ::Dcb::Float3>(6);
		auto b = QAQ::Dcb::Buffer(std::move(s));

		auto act = b.GetSizeInBytes();
		QAQ_ASSERT(act == 16u * 6u);
	}
	// testing CookedLayout
	{
		QAQ::Dcb::RawLayout s;
		s.Add<QAQ::Dcb::Array>("arr");
		s["arr"].Set<QAQ::Dcb::Float3>(6);
		auto cooked = QAQ::Dcb::LayoutCodex::Resolve(std::move(s));
		// raw is cleared after donating
		s.Add<QAQ::Dcb::Float>("arr");
		// fails to compile, cooked returns const&
		// cooked["arr"].Add<QAQ::Dcb::Float>("buttman");
		auto b1 = QAQ::Dcb::Buffer(cooked);
		b1["arr"][0] = dx::XMFLOAT3{69.0f, 0.0f, 0.0f};
		auto b2 = QAQ::Dcb::Buffer(cooked);
		b2["arr"][0] = dx::XMFLOAT3{420.0f, 0.0f, 0.0f};
		QAQ_ASSERT(static_cast<dx::XMFLOAT3>(b1["arr"][0]).x == 69.0f);
		QAQ_ASSERT(static_cast<dx::XMFLOAT3>(b2["arr"][0]).x == 420.0f);
	}
	// specific testing scenario (packing error)
	{
		QAQ::Dcb::RawLayout pscLayout;
		pscLayout.Add<QAQ::Dcb::Float3>("materialColor");
		pscLayout.Add<QAQ::Dcb::Float3>("specularColor");
		pscLayout.Add<QAQ::Dcb::Float>("specularWeight");
		pscLayout.Add<QAQ::Dcb::Float>("specularGloss");
		auto cooked = QAQ::Dcb::LayoutCodex::Resolve(std::move(pscLayout));
		QAQ_ASSERT(cooked.GetSizeInBytes() == 48u);
	}
	// array non-packing
	{
		QAQ::Dcb::RawLayout pscLayout;
		pscLayout.Add<QAQ::Dcb::Array>("arr");
		pscLayout["arr"].Set<QAQ::Dcb::Float>(10);
		auto cooked = QAQ::Dcb::LayoutCodex::Resolve(std::move(pscLayout));
		QAQ_ASSERT(cooked.GetSizeInBytes() == 160u);
	}
	// array of struct w/ padding
	{
		QAQ::Dcb::RawLayout pscLayout;
		pscLayout.Add<QAQ::Dcb::Array>("arr");
		pscLayout["arr"].Set<QAQ::Dcb::Struct>(10);
		pscLayout["arr"].T().Add<QAQ::Dcb::Float3>("x");
		pscLayout["arr"].T().Add<QAQ::Dcb::Float2>("y");
		auto cooked = QAQ::Dcb::LayoutCodex::Resolve(std::move(pscLayout));
		QAQ_ASSERT(cooked.GetSizeInBytes() == 320u);
	}
	// testing pointer stuff
	{
		QAQ::Dcb::RawLayout s;
		s.Add<QAQ::Dcb::Struct>("butts"s);
		s["butts"s].Add<QAQ::Dcb::Float3>("pubes"s);
		s["butts"s].Add<QAQ::Dcb::Float>("dank"s);

		auto b = QAQ::Dcb::Buffer(std::move(s));
		const auto exp = 696969.6969f;
		b["butts"s]["dank"s] = 696969.6969f;
		QAQ_ASSERT((float &)b["butts"s]["dank"s] == exp);
		QAQ_ASSERT(*(float *)&b["butts"s]["dank"s] == exp);
		const auto exp2 = 42.424242f;
		*(float *)&b["butts"s]["dank"s] = exp2;
		QAQ_ASSERT((float &)b["butts"s]["dank"s] == exp2);
	}
	// specific testing scenario (packing error)
	{
		QAQ::Dcb::RawLayout lay;
		lay.Add<QAQ::Dcb::Bool>("normalMapEnabled");
		lay.Add<QAQ::Dcb::Bool>("specularMapEnabled");
		lay.Add<QAQ::Dcb::Bool>("hasGlossMap");
		lay.Add<QAQ::Dcb::Float>("specularPower");
		lay.Add<QAQ::Dcb::Float3>("specularColor");
		lay.Add<QAQ::Dcb::Float>("specularMapWeight");

		auto buf = QAQ::Dcb::Buffer(std::move(lay));
		QAQ_ASSERT(buf.GetSizeInBytes() == 32u);
	}
	// specific testing scenario (array packing issues gimme a tissue)
	{
		const int maxRadius = 7;
		const int nCoef = maxRadius * 2 + 1;
		QAQ::Dcb::RawLayout l;
		l.Add<QAQ::Dcb::Integer>("nTaps");
		l.Add<QAQ::Dcb::Array>("coefficients");
		l["coefficients"].Set<QAQ::Dcb::Float>(nCoef);
		QAQ::Dcb::Buffer buf{std::move(l)};
		// assert proper amount of memory allocated
		QAQ_ASSERT(buf.GetSizeInBytes() == (nCoef + 1) * 4 * 4);
		// assert array empty
		{
			const char *begin = reinterpret_cast<char *>((int *)&buf["nTaps"]);
			QAQ_ASSERT(std::all_of(begin, begin + buf.GetSizeInBytes(), [](char c)
							   { return c == 0; }));
		}
		// assert sparse float storage
		{
			for (int i = 0; i < nCoef; i++)
			{
				buf["coefficients"][i] = 6.9f;
			}
			const auto begin = reinterpret_cast<std::array<float, 4> *>((float *)&buf["coefficients"][0]);
			const auto end = begin + nCoef;
			QAQ_ASSERT(std::all_of(begin, end, [](const auto &arr)
							   { return arr[0] == 6.9f && arr[1] == 0.0f && arr[2] == 0.0f && arr[3] == 0.0f; }));
		}
	}
}

void TestingLayer::OnUpdate(QAQ::Timestep ts)
{
}

void TestingLayer::OnImGuiRender()
{
}

void TestingLayer::OnEvent(QAQ::Event &e)
{
}
