#include "Icon.h"

#include <fstream>



namespace toxic
{
	Icon::Icon()
	{
		_width = 0;
		_height = 0;
		_icon = NULL;
	}

	Icon::~Icon()
	{
		if(_icon)
			DestroyIcon(_icon);
	}

	bool Icon::Load(const String& filename)
	{
		return false;
	}

	HICON Icon::GetRaw()
	{
		return _icon;
	}

	void Icon::Destroy()
	{
		if(_icon)
			DestroyIcon(_icon);
	}

}