#pragma once 

#include "../Config.h"

#include <Windows.h>



namespace toxic
{
	class TOXIC_API Cursor
	{
	public:
		enum Type
		{
			ARROW,
			IBEAM,
			WAIT,
			CROSS,
			UPARROW,
			SIZE,
			ICON,
			SIZENWSE,
			SIZENESW,
			SIZEWE,
			SIZENS,
			SIZEALL,
			NO
		};
		
		Cursor();
		Cursor(Type type);

		void SetType(Type type);
		HCURSOR GetRaw();
		
	private:
		HCURSOR _rawCursor;
	};
}