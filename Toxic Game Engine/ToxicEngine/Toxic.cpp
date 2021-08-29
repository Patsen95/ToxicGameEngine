#include "Toxic.h"


namespace toxic
{
	Toxic::Toxic() { }

	void Toxic::Init(int& _argc, char** _argv)
	{
		glutInit(&_argc, _argv);
		glutInitContextVersion(3, 2);
		glutInitContextProfile(GLUT_CORE_PROFILE);

		// Inicjalizacja glew
		glewExperimental = true;

		glGetError();
	}

	void Toxic::SetDisplayMode(int mode)
	{
		glutInitDisplayMode(mode);
	}

	void Toxic::SetRenderWindow(Window& window)
	{
		window.winId = glutCreateWindow(window.title.C_Str());
		window.position.x = glutGet((uint)GLUT_WINDOW_X);
		window.position.y = glutGet((uint)GLUT_WINDOW_Y);
	}
}