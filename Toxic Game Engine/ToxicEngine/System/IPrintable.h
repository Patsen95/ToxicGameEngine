#pragma once

#include "../Config.h"

#include "../Utils/String.h"



namespace toxic
{
	class Log;

	class TOXIC_API IPrintable
	{
	public:
		virtual ~IPrintable() { }

	protected:
		friend class Log;

		virtual String ToString() const = 0;
	};
}