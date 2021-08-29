#pragma once

#include "IPrintable.h"
#include "Convert.h"
#include "../Config.h"

#include <iostream>


namespace toxic
{
	class TOXIC_API Log
	{
	public:
		static void Debug(const IPrintable& printable);
		static void Info(const String msg);
		static void Error(const String msg);
		static void Warning(const String msg);

	private:

	};
}
