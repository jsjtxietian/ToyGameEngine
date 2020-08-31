#pragma once

namespace QAQ
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

#define QAQ_KEY_SPACE           ::QAQ::Key::Space
#define QAQ_KEY_APOSTROPHE      ::QAQ::Key::Apostrophe    /* ' */
#define QAQ_KEY_COMMA           ::QAQ::Key::Comma         /* , */
#define QAQ_KEY_MINUS           ::QAQ::Key::Minus         /* - */
#define QAQ_KEY_PERIOD          ::QAQ::Key::Period        /* . */
#define QAQ_KEY_SLASH           ::QAQ::Key::Slash         /* / */
#define QAQ_KEY_0               ::QAQ::Key::D0
#define QAQ_KEY_1               ::QAQ::Key::D1
#define QAQ_KEY_2               ::QAQ::Key::D2
#define QAQ_KEY_3               ::QAQ::Key::D3
#define QAQ_KEY_4               ::QAQ::Key::D4
#define QAQ_KEY_5               ::QAQ::Key::D5
#define QAQ_KEY_6               ::QAQ::Key::D6
#define QAQ_KEY_7               ::QAQ::Key::D7
#define QAQ_KEY_8               ::QAQ::Key::D8
#define QAQ_KEY_9               ::QAQ::Key::D9
#define QAQ_KEY_SEMICOLON       ::QAQ::Key::Semicolon     /* ; */
#define QAQ_KEY_EQUAL           ::QAQ::Key::Equal         /* = */
#define QAQ_KEY_A               ::QAQ::Key::A
#define QAQ_KEY_B               ::QAQ::Key::B
#define QAQ_KEY_C               ::QAQ::Key::C
#define QAQ_KEY_D               ::QAQ::Key::D
#define QAQ_KEY_E               ::QAQ::Key::E
#define QAQ_KEY_F               ::QAQ::Key::F
#define QAQ_KEY_G               ::QAQ::Key::G
#define QAQ_KEY_H               ::QAQ::Key::H
#define QAQ_KEY_I               ::QAQ::Key::I
#define QAQ_KEY_J               ::QAQ::Key::J
#define QAQ_KEY_K               ::QAQ::Key::K
#define QAQ_KEY_L               ::QAQ::Key::L
#define QAQ_KEY_M               ::QAQ::Key::M
#define QAQ_KEY_N               ::QAQ::Key::N
#define QAQ_KEY_O               ::QAQ::Key::O
#define QAQ_KEY_P               ::QAQ::Key::P
#define QAQ_KEY_Q               ::QAQ::Key::Q
#define QAQ_KEY_R               ::QAQ::Key::R
#define QAQ_KEY_S               ::QAQ::Key::S
#define QAQ_KEY_T               ::QAQ::Key::T
#define QAQ_KEY_U               ::QAQ::Key::U
#define QAQ_KEY_V               ::QAQ::Key::V
#define QAQ_KEY_W               ::QAQ::Key::W
#define QAQ_KEY_X               ::QAQ::Key::X
#define QAQ_KEY_Y               ::QAQ::Key::Y
#define QAQ_KEY_Z               ::QAQ::Key::Z
#define QAQ_KEY_LEFT_BRACKET    ::QAQ::Key::LeftBracket   /* [ */
#define QAQ_KEY_BACKSLASH       ::QAQ::Key::Backslash     /* \ */
#define QAQ_KEY_RIGHT_BRACKET   ::QAQ::Key::RightBracket  /* ] */
#define QAQ_KEY_GRAVE_ACCENT    ::QAQ::Key::GraveAccent   /* ` */
#define QAQ_KEY_WORLD_1         ::QAQ::Key::World1        /* non-US #1 */
#define QAQ_KEY_WORLD_2         ::QAQ::Key::World2        /* non-US #2 */
#define QAQ_KEY_ESCAPE          ::QAQ::Key::Escape
#define QAQ_KEY_ENTER           ::QAQ::Key::Enter
#define QAQ_KEY_TAB             ::QAQ::Key::Tab
#define QAQ_KEY_BACKSPACE       ::QAQ::Key::Backspace
#define QAQ_KEY_INSERT          ::QAQ::Key::Insert
#define QAQ_KEY_DELETE          ::QAQ::Key::Delete
#define QAQ_KEY_RIGHT           ::QAQ::Key::Right
#define QAQ_KEY_LEFT            ::QAQ::Key::Left
#define QAQ_KEY_DOWN            ::QAQ::Key::Down
#define QAQ_KEY_UP              ::QAQ::Key::Up
#define QAQ_KEY_PAGE_UP         ::QAQ::Key::PageUp
#define QAQ_KEY_PAGE_DOWN       ::QAQ::Key::PageDown
#define QAQ_KEY_HOME            ::QAQ::Key::Home
#define QAQ_KEY_END             ::QAQ::Key::End
#define QAQ_KEY_CAPS_LOCK       ::QAQ::Key::CapsLock
#define QAQ_KEY_SCROLL_LOCK     ::QAQ::Key::ScrollLock
#define QAQ_KEY_NUM_LOCK        ::QAQ::Key::NumLock
#define QAQ_KEY_PRINT_SCREEN    ::QAQ::Key::PrintScreen
#define QAQ_KEY_PAUSE           ::QAQ::Key::Pause
#define QAQ_KEY_F1              ::QAQ::Key::F1
#define QAQ_KEY_F2              ::QAQ::Key::F2
#define QAQ_KEY_F3              ::QAQ::Key::F3
#define QAQ_KEY_F4              ::QAQ::Key::F4
#define QAQ_KEY_F5              ::QAQ::Key::F5
#define QAQ_KEY_F6              ::QAQ::Key::F6
#define QAQ_KEY_F7              ::QAQ::Key::F7
#define QAQ_KEY_F8              ::QAQ::Key::F8
#define QAQ_KEY_F9              ::QAQ::Key::F9
#define QAQ_KEY_F10             ::QAQ::Key::F10
#define QAQ_KEY_F11             ::QAQ::Key::F11
#define QAQ_KEY_F12             ::QAQ::Key::F12
#define QAQ_KEY_F13             ::QAQ::Key::F13
#define QAQ_KEY_F14             ::QAQ::Key::F14
#define QAQ_KEY_F15             ::QAQ::Key::F15
#define QAQ_KEY_F16             ::QAQ::Key::F16
#define QAQ_KEY_F17             ::QAQ::Key::F17
#define QAQ_KEY_F18             ::QAQ::Key::F18
#define QAQ_KEY_F19             ::QAQ::Key::F19
#define QAQ_KEY_F20             ::QAQ::Key::F20
#define QAQ_KEY_F21             ::QAQ::Key::F21
#define QAQ_KEY_F22             ::QAQ::Key::F22
#define QAQ_KEY_F23             ::QAQ::Key::F23
#define QAQ_KEY_F24             ::QAQ::Key::F24
#define QAQ_KEY_F25             ::QAQ::Key::F25

/* Keypad */
#define QAQ_KEY_KP_0            ::QAQ::Key::KP0
#define QAQ_KEY_KP_1            ::QAQ::Key::KP1
#define QAQ_KEY_KP_2            ::QAQ::Key::KP2
#define QAQ_KEY_KP_3            ::QAQ::Key::KP3
#define QAQ_KEY_KP_4            ::QAQ::Key::KP4
#define QAQ_KEY_KP_5            ::QAQ::Key::KP5
#define QAQ_KEY_KP_6            ::QAQ::Key::KP6
#define QAQ_KEY_KP_7            ::QAQ::Key::KP7
#define QAQ_KEY_KP_8            ::QAQ::Key::KP8
#define QAQ_KEY_KP_9            ::QAQ::Key::KP9
#define QAQ_KEY_KP_DECIMAL      ::QAQ::Key::KPDecimal
#define QAQ_KEY_KP_DIVIDE       ::QAQ::Key::KPDivide
#define QAQ_KEY_KP_MULTIPLY     ::QAQ::Key::KPMultiply
#define QAQ_KEY_KP_SUBTRACT     ::QAQ::Key::KPSubtract
#define QAQ_KEY_KP_ADD          ::QAQ::Key::KPAdd
#define QAQ_KEY_KP_ENTER        ::QAQ::Key::KPEnter
#define QAQ_KEY_KP_EQUAL        ::QAQ::Key::KPEqual

#define QAQ_KEY_LEFT_SHIFT      ::QAQ::Key::LeftShift
#define QAQ_KEY_LEFT_CONTROL    ::QAQ::Key::LeftControl
#define QAQ_KEY_LEFT_ALT        ::QAQ::Key::LeftAlt
#define QAQ_KEY_LEFT_SUPER      ::QAQ::Key::LeftSuper
#define QAQ_KEY_RIGHT_SHIFT     ::QAQ::Key::RightShift
#define QAQ_KEY_RIGHT_CONTROL   ::QAQ::Key::RightControl
#define QAQ_KEY_RIGHT_ALT       ::QAQ::Key::RightAlt
#define QAQ_KEY_RIGHT_SUPER     ::QAQ::Key::RightSuper
#define QAQ_KEY_MENU            ::QAQ::Key::Menu