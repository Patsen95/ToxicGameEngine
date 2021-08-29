#include "AARect.h"
#include "../Math/Math.h"



namespace toxic
{
	AARect::AARect()
	{
		pos = Vec2f(0, 0);
		size = Vec2f(0, 0);
	}

	AARect::AARect(float x, float y, float w, float h)
	{
		pos = Vec2f(x, y);
		size = Vec2f(w, h);
	}

	AARect::AARect(const Vec2f& pos, const Vec2f& size)
	{
		this->pos = pos;
		this->size = size;
	}

	AARect::AARect(const AARect& rect)
	{
		this->pos = rect.pos;
		this->size = rect.size;
	}

	bool AARect::Contains(float x, float y) const
	{
		float minX = Math::Min(pos.x, pos.x + size.x);
		float maxX = Math::Max(pos.x, pos.x + size.x);
		float minY = Math::Min(pos.y, pos.y + size.y);
		float maxY = Math::Max(pos.y, pos.y + size.y);
		return ((x >= minX) && (x < maxX) && (y >= minY) && (y < maxY));
	}

	bool AARect::Contains(const Vec2f& point) const
	{
		return this->Contains(point.x, point.y);
	}

	bool AARect::Intersects(const AARect& rect) const
	{
		AARect _rect;
		return this->Intersects(rect, _rect);
	}

	bool AARect::Intersects(const AARect& rect, AARect& intersection) const
	{
		float r1MinX = Math::Min(pos.x, pos.x + size.x);
		float r1MaxX = Math::Max(pos.x, pos.x + size.x);
		float r1MinY = Math::Min(pos.y, pos.y + size.y);
		float r1MaxY = Math::Max(pos.y, pos.y + size.y);

		float r2MinX = Math::Min(rect.pos.x, rect.pos.x + rect.size.x);
		float r2MaxX = Math::Max(rect.pos.x, rect.pos.x + rect.size.x);
		float r2MinY = Math::Min(rect.pos.y, rect.pos.y + rect.size.y);
		float r2MaxY = Math::Max(rect.pos.y, rect.pos.y + rect.size.y);

		float interX = Math::Max(r1MinX, r2MinX);
		float interY = Math::Max(r1MinY, r2MinY);
		float interW = Math::Min(r1MaxX, r2MaxX);
		float interH = Math::Min(r1MaxY, r2MaxY);
		
		if((interX < interW) && (interY < interH))
		{
			intersection = AARect(interX, interY, interW - interX, interH - interY);
			return true;
		}
		else
		{
			intersection = AARect();
			return false;
		}
	}

	Vec2f AARect::GetPosition() const
	{
		return this->pos;
	}

	Vec2f AARect::GetSize() const
	{
		return this->size;
	}

	float AARect::GetX() const
	{
		return this->pos.x;
	}

	float AARect::GetY() const
	{
		return this->pos.y;
	}

	float AARect::GetWidth() const
	{
		return this->size.x;
	}

	float AARect::GetHeight() const
	{
		return this->size.y;
	}

	bool operator ==(const AARect& left, const AARect& right)
	{
		return ((left.GetPosition() == right.GetPosition()) && (left.GetSize() == right.GetSize()));
	}

	bool operator !=(const AARect& left, const AARect& right)
	{
		return !((left.GetPosition() == right.GetPosition()) || (left.GetSize() == right.GetSize()));
	}
}