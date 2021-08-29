#pragma once

#include "../Config.h"
#include "../Math/Vec2.h"



namespace toxic
{
	class TOXIC_API AARect
	{
	public:
		AARect();
		AARect(float x, float y, float w, float h);
		AARect(const Vec2f& pos, const Vec2f& size);
		AARect(const AARect& rect);

		bool Contains(float x, float y) const;
		bool Contains(const Vec2f& point) const;
		bool Intersects(const AARect& rect) const;
		bool Intersects(const AARect& rect, AARect& intersection) const;
		Vec2f GetPosition() const;
		Vec2f GetSize() const;
		float GetX() const;
		float GetY() const;
		float GetWidth() const;
		float GetHeight() const;

	private:
		Vec2f pos;
		Vec2f size;
	};

	TOXIC_API bool operator ==(const AARect& left, const AARect& right);
	TOXIC_API bool operator !=(const AARect& left, const AARect& right);
}
