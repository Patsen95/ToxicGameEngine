#pragma once

#include "../Config.h"
#include "../Utils/String.h"

#include <Windows.h>



namespace toxic
{
	class TOXIC_API Icon
	{
	public:
		Icon();
		~Icon();

		bool Load(const String& filename);

		HICON GetRaw();

		void Destroy();
	private:
		HICON _icon;
		unsigned _width;
		unsigned _height;
	};
}