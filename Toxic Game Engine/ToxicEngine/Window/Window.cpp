#include "Window.h"



namespace toxic
{
	Window::Window()
	{
		this->size = Vec2u(600, 400);
		this->title = "Toxic Window";
	}

	Window::Window(const String& title, uint w, uint h)
	{
		this->title = title;
		this->size = Vec2u(w, h);
	}

	Window::Window(const Window& window)
	{
		this->winId = window.winId;
		this->title = window.title;
		this->size = window.size;
		this->position = window.position;
		this->isFullscreen = window.isFullscreen;
	}

	Window::~Window()
	{
		glutDestroyWindow(this->winId);
	}

	void Window::SetTitle(const String& title)
	{
		this->title = title;
		glutSetWindowTitle(this->title.C_Str());
	}

	void Window::SetSize(uint dw, uint dh)
	{
		this->size.x = dw;
		this->size.y = dh;
		glViewport(0, 0, this->size.x, this->size.y);
	}

	void Window::SetFullscreen(bool fullscreen)
	{
		if(fullscreen)
			glutFullScreen();
		else
			glutReshapeWindow(this->size.x, this->size.y);
	}

	void Window::SetPosition(int x, int y)
	{
		this->position.x = x;
		this->position.y = y;
		glutPositionWindow(this->position.x, this->position.y);
	}

	uint Window::GetID() const
	{
		return this->winId;
	}

	Vec2u Window::GetSize() const
	{
		return this->size;
	}

	Vec2i Window::GetPosition() const
	{
		return this->position;
	}

	String Window::GetTitle()
	{
		return title;
	}
}
