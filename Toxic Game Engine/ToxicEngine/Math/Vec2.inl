#include "Vec2.h"

#include <cmath>



template<class T>
inline toxic::Vec2<T>::Vec2()
{
	this->x = 0;
	this->y = 0;
}

template<class T>
inline toxic::Vec2<T>::Vec2(T x, T y)
{
	this->x = x;
	this->y = y;
}

template<class T>
inline toxic::Vec2<T>::Vec2(const Vec2& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

template<class T>
inline void toxic::Vec2<T>::Set(T x, T y)
{
	this->x = x;
	this->y = y;
}

template<class T>
inline void toxic::Vec2<T>::Scale(T scale)
{
	this->x *= scale;
	this->y *= scale;
}

template<class T>
inline void toxic::Vec2<T>::Scale(T sx, T sy)
{
	this->x *= sx;
	this->y *= sy;
}

template<class T>
inline void toxic::Vec2<T>::Translate(T dx, T dy)
{
	this->x += dx;
	this->y += dy;
}

template<class T>
inline void toxic::Vec2<T>::Negate()
{
	this->x = -this->x;
	this->y = -this->y;
}

template<class T>
inline void toxic::Vec2<T>::Normalise()
{
	float len = this->Length();
	this->x /= len;
	this->y /= len;
}

template<class T>
inline void toxic::Vec2<T>::Swap()
{
	T _x = this->x;
	this->x = this->y;
	this->y = _x;
}

template<class T>
inline float toxic::Vec2<T>::Length()
{
	return sqrtf(lengthSquared());
}

template<class T>
template<class Y>
inline void toxic::Vec2<T>::Add(Vec2<Y>& other)
{
	this->x += static_cast<T>(other.x);
	this->y += static_cast<T>(other.y);
}

template<class T>
template<class Y>
inline void toxic::Vec2<T>::Sub(Vec2<Y>& other)
{
	this->x -= static_cast<T>(other.x);
	this->y -= static_cast<T>(other.y);
}

template<class T>
template<class Y>
inline T toxic::Vec2<T>::Dot(Vec2<Y>& a, Vec2<Y>& b)
{
	return (static_cast<T>(a.x) * static_cast<T>(b.x)) + (static_cast<T>(a.y) * static_cast<T>(b.y));
}

template<class T>
template<class Y>
inline T toxic::Vec2<T>::Angle(Vec2<Y>& a, Vec2<Y>& b)
{
	float dls = Dot(static_cast<T>(a), static_cast<T>(b)) / (static_cast<T>(a.Length()) * static_cast<T>(b.Length()));
	if(dls < -1.0f)
		dls = -1.0f;
	else if(dls > 1.0f)
		dls = 1.0f;
	return (float)acosf(dls);
}

template<class T>
inline toxic::Matrix<T> toxic::Vec2<T>::GetMatrix() const
{
	Matrix<T> _mat(2, 1);
	_mat(0, 0) = this->x;
	_mat(1, 0) = this->y;
	return _mat;
}

//template<class T>
//inline toxic::String toxic::Vec2<T>::ToString() const
//{
//	String str = "Vec2<";
//	//str.Append(typeid(T).name());
//	//str.Append(">(");
//	//str.Append(Convert::ToString(this->x));
//	//str.Append(", ");
//	//str.Append(Convert::ToString(this->y));
//	//str.Append(")");
//	return str;
//}
///////////////////////////////////////////////////////
template<class T>
inline float toxic::Vec2<T>::lengthSquared()
{
	return ((float)this->x * (float)this->x) + ((float)this->y * (float)this->y);
}

template<class T>
bool toxic::operator ==(const Vec2<T>& left, const Vec2<T>& right)
{
	return ((left.x == right.x) && (left.y == right.y));
}

template<class T>
bool toxic::operator !=(const Vec2<T>& left, const Vec2<T>& right)
{
	return !((left.x == right.x) || (left.y == right.y));
}