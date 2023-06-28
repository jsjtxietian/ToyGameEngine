#pragma once

#include "QAQ/Core/Buffer.h"
#include <filesystem>

namespace QAQ
{

	class FileSystem
	{
	public:
		static Buffer ReadFileBinary(const std::filesystem::path &filepath);
	};

}