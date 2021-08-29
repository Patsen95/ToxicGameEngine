#pragma once

#include "../Config.h"
#include "../Utils/String.h"



namespace toxic
{
	class TOXIC_API ContextMenu
	{
	public:
		ContextMenu(void(*func)(int));

		void AddEntry(String& name);
		void AddEntry(String& name, const int id);
		void AddSubMenu(String& name, const ContextMenu& submenu);
		static void Register(int button);
		static void DetachMenu(int button);

		int GetID() const;

	private:
		void(*menuFunc)(int);
		int menuId;
		static int entryId;
	};
}
