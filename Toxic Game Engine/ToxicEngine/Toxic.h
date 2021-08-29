#pragma once

#include "Graphics/AARect.h"
//#include "Graphics/Color.h"

//#include "Graphics/Rendering/VertexArray.h"

//#include "Graphics/UI/Layout.h"

//#include "Management/AssetsManager.h"
//#include "Management/GUIManager.h"

#include "Math/Vec2.h"
#include "Math/Vec3.h"
#include "Math/Vec4.h"
#include "Math/Random.h"
#include "Math/Math.h"
#include "Math/Matrix.h"

#include "Window/Window.h"

#include "System/Convert.h"
//#include "System/Log.h"

#include "Utils/String.h"


#include <Windows.h>
#include <glew.h>
#include <freeglut.h>

//https://stackoverflow.com/questions/42245870/how-to-get-the-graphics-card-model-name-in-opengl-or-win32
//https://www.khronos.org/opengl/wiki/OpenGL_Context#Context_information_queries
//https://www.khronos.org/opengl/wiki/Debug_Output

namespace toxic
{
	enum DisplayMode
	{
		RGB = 0x0000,
		INDEX = 0x0001,
		DOUBLE = 0x0002,
		ACCUM = 0x0004,
		ALPHA = 0x0008,
		DEPTH = 0x0010,
		STENCIL = 0x0020,
		MULTISAMPLE = 0x0080,
		STEREO = 0x0100,
		LUMINANCE = 0x0200
	};

	class TOXIC_API Toxic
	{
	public:
		Toxic();

		void Init(int& _argc, char** _argv);
		void SetDisplayMode(int mode);
		void SetRenderWindow(Window& window);
		//void Loop();

	private:
		Window* mainWindow;
	};
}