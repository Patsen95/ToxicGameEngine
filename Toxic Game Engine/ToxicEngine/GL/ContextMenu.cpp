#include "ContextMenu.h"

#include <glew.h>
#include <freeglut.h>


namespace toxic
{
	int ContextMenu::entryId = 0;


	ContextMenu::ContextMenu(void(*func)(int))
	{
		menuFunc = func;
		menuId = glutCreateMenu(func);
		entryId = 0;
	}

	int ContextMenu::GetID() const
	{
		return menuId;
	}

	void ContextMenu::AddEntry(String& name)
	{
		glutAddMenuEntry(name.C_Str(), entryId);
		entryId++;
	}

	void ContextMenu::AddEntry(String& name, const int id)
	{
		glutAddMenuEntry(name.C_Str(), id);
	}

	void ContextMenu::AddSubMenu(String& name, const ContextMenu& submenu)
	{
		glutAddSubMenu(name.C_Str(), submenu.GetID());
	}

	void ContextMenu::Register(int button)
	{
		glutAttachMenu(button);
	}

	void ContextMenu::DetachMenu(int button)
	{
		glutDetachMenu(button);
	}
}
