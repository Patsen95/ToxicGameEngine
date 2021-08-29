#pragma once

#include "../../Config.h"
#include "../../Math/Vec2.h"
#include "../../Graphics/Color.h"



namespace toxic
{
	class TOXIC_API Vertex
	{
	public:
		Vertex();
		Vertex(const Vec2f& pos);
		Vertex(const Vec2f& pos, const Vec2f& texCoords);
		Vertex(const Vec2f& pos, const Color& color);
		Vertex(const Vec2f& pos, const Vec2f& texCoords, const Color& color);

		void SetPosition(float x, float y);
		void SetPosition(const Vec2f& pos);

		Vec2f GetPosition() const;
		Vec2f GetTextureCoords() const;
		Color GetColor() const;

	private:
		Vec2f position;
		Vec2f textureCoords;
		Color color;
	};
}
