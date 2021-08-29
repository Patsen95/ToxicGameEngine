#pragma once

#include "../Config.h"
#include "../Math/Vec2.h"
#include "../Utils/String.h"

#include <Windows.h>
#include <glew.h>
#include <freeglut.h>
#include <iostream>


// https://msdn.microsoft.com/pl-pl/library/14h5k7ff.aspx


namespace toxic
{

	class TOXIC_API Window
	{
	public:
		Window();
		Window(const String& title, uint w, uint h);
		Window(const Window& window);
		~Window();

		void SetTitle(const String& title);
		void SetSize(uint dw, uint dh);
		void SetFullscreen(bool fullscreen);
		void SetPosition(int x, int y);
		void PollWindowEvents();
		bool IsClosing();
		void Close();
		void Update();

		uint GetID() const;
		Vec2u GetSize() const;
		Vec2i GetPosition() const;
		String GetTitle();

	private:
		friend class Toxic;
		
		uint winId;
		String title;
		Vec2u size;
		Vec2i position;
		bool isFullscreen;
	};
}
