#include "Cursor.h"


namespace toxic
{
	Cursor::Cursor()
	{
		_rawCursor = LoadCursor(NULL, IDC_ARROW);
	}

	Cursor::Cursor(Type type)
	{
		SetType(type);
	}

	void Cursor::SetType(Type type)
	{
		switch(type)
		{
			case ARROW:
				_rawCursor = LoadCursor(NULL, IDC_ARROW);
				break;

			case IBEAM:
				_rawCursor = LoadCursor(NULL, IDC_IBEAM);
				break;

			case WAIT:
				_rawCursor = LoadCursor(NULL, IDC_WAIT);
				break;

			case CROSS:
				_rawCursor = LoadCursor(NULL, IDC_CROSS);
				break;

			case UPARROW:
				_rawCursor = LoadCursor(NULL, IDC_UPARROW);
				break;

			case SIZE:
				_rawCursor = LoadCursor(NULL, IDC_SIZE);
				break;

			case ICON:
				_rawCursor = LoadCursor(NULL, IDC_ICON);
				break;

			case SIZENWSE:
				_rawCursor = LoadCursor(NULL, IDC_SIZENWSE);
				break;

			case SIZENESW:
				_rawCursor = LoadCursor(NULL, IDC_SIZENESW);
				break;

			case SIZEWE:
				_rawCursor = LoadCursor(NULL, IDC_SIZEWE);
				break;

			case SIZENS:
				_rawCursor = LoadCursor(NULL, IDC_SIZENS);
				break;

			case SIZEALL:
				_rawCursor = LoadCursor(NULL, IDC_SIZEALL);
				break;

			case NO:
				_rawCursor = LoadCursor(NULL, IDC_NO);
				break;

			default:
				_rawCursor = LoadCursor(NULL, IDC_ARROW);
				break;
		}
	}

	HCURSOR Cursor::GetRaw()
	{
		return _rawCursor;
	}
}
