#include "AssetsManager.h"


namespace toxic
{
	//std::unordered_map<std::string, Texture*> AssetsManager::textures;
	//std::unordered_map<std::string, Font*> AssetsManager::fonts;


	/*void AssetsManager::LoadTexture(const std::string& path, const std::string& name)
	{
		Texture* texture = new Texture();
		texture->loadFromFile(path);
		textures.insert(std::unordered_map<std::string, Texture*>::value_type(name, texture));
	}

	void AssetsManager::LoadFont(const std::string& path, const std::string& name)
	{
		Font* font = new Font();
		font->loadFromFile(path);
		fonts.insert(std::unordered_map<std::string, Font*>::value_type(name, font));
	}*/

	/*Texture* AssetsManager::GetTexture(const std::string& name)
	{
		return textures[name];
	}

	Font* AssetsManager::GetFont(const std::string& name)
	{
		return fonts[name];
	}

	void AssetsManager::Release()
	{
		textures.clear();
		fonts.clear();
	}*/
}
