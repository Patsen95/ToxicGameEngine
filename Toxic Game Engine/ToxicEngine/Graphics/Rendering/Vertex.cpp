#include "Vertex.h"


namespace toxic
{
	Vertex::Vertex()
	{
		this->position = Vec2f(0, 0);
		this->textureCoords = Vec2f(0, 0);
		this->color = Color::White;
	}

	Vertex::Vertex(const Vec2f& pos)
	{
		this->position = pos;
		this->textureCoords = Vec2f(0, 0);
		this->color = Color::White;
	}

	Vertex::Vertex(const Vec2f& pos, const Vec2f& texCoords)
	{
		this->position = pos;
		this->textureCoords = texCoords;
		this->color = Color::White;
	}

	Vertex::Vertex(const Vec2f& pos, const Color& color)
	{
		this->position = pos;
		this->textureCoords = Vec2f(0, 0);
		this->color = color;
	}

	Vertex::Vertex(const Vec2f& pos, const Vec2f& texCoords, const Color& color)
	{
		this->position = pos;
		this->textureCoords = texCoords;
		this->color = color;
	}

	void Vertex::SetPosition(float x, float y)
	{
		position = Vec2f(x, y);
	}

	void Vertex::SetPosition(const Vec2f& pos)
	{
		position = pos;
	}

	Vec2f Vertex::GetPosition() const
	{
		return this->position;
	}

	Vec2f Vertex::GetTextureCoords() const
	{
		return this->textureCoords;
	}

	Color Vertex::GetColor() const
	{
		return color;
	}
}
