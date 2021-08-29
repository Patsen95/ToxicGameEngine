#include "Vec4.h"

#include <cmath>



template<class T>
inline toxic::Vec4<T>::Vec4()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

template<class T>
inline toxic::Vec4<T>::Vec4(T x, T y, T z, T w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

template<class T>
inline toxic::Vec4<T>::Vec4(const Vec4& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
	this->w = vec.w;
}

template<class T>
inline void toxic::Vec4<T>::Set(T x, T y, T z, T w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

template<class T>
inline void toxic::Vec4<T>::Scale(T scale)
{
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
	this->w *= scale;
}

template<class T>
inline void toxic::Vec4<T>::Scale(T sx, T sy, T sz, T sw)
{
	this->x *= sx;
	this->y *= sy;
	this->z *= sz;
	this->w *= sw;
}

template<class T>
inline void toxic::Vec4<T>::Translate(T dx, T dy, T dz, T dw)
{
	this->x += dx;
	this->y += dy;
	this->z += dz;
	this->w += dw;
}

template<class T>
inline void toxic::Vec4<T>::Negate()
{
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
	this->w = -this->w;
}

template<class T>
inline void toxic::Vec4<T>::Normalise()
{
	float len = this->Length();
	this->x /= len;
	this->y /= len;
	this->z /= len;
	this->w /= len;
}

template<class T>
inline void toxic::Vec4<T>::SwapXY()
{
	T _x = this->x;
	this->x = this->y;
	this->y = _x;
}

template<class T>
inline void toxic::Vec4<T>::SwapYZ()
{
	T _y = this->y;
	this->y = this->z;
	this->z = _y;
}

template<class T>
inline void toxic::Vec4<T>::SwapXZ()
{
	T _x = this->x;
	this->x = this->z;
	this->z = _x;
}

template<class T>
inline float toxic::Vec4<T>::Length()
{
	return sqrtf(lengthSquared());
}

template<class T>
template<class Y>
inline void toxic::Vec4<T>::Add(Vec4<Y>& other)
{
	this->x += static_cast<T>(other.x);
	this->y += static_cast<T>(other.y);
	this->z += static_cast<T>(other.z);
	this->w += static_cast<T>(other.w);
}

template<class T>
template<class Y>
inline void toxic::Vec4<T>::Sub(Vec4<Y>& other)
{
	this->x -= static_cast<T>(other.x);
	this->y -= static_cast<T>(other.y);
	this->z -= static_cast<T>(other.z);
	this->w -= static_cast<T>(other.w);
}

template<class T>
template<class Y>
inline T toxic::Vec4<T>::Dot(Vec4<Y>& a, Vec4<Y>& b)
{
	return (static_cast<T>(a.x) * static_cast<T>(b.x)) + (static_cast<T>(a.y) * static_cast<T>(b.y) + 
		(static_cast<T>(a.z) * static_cast<T>(b.z)) + (static_cast<T>(a.w) * static_cast<T>(b.w)));
}

template<class T>
template<class Y>
inline toxic::Vec4<T> toxic::Vec4<T>::Cross(Vec4<Y>& a, Vec4<Y> b)
{
	T _x = (a.y * b.z) - (b.y * a.z);
	T _y = (a.z * b.x) - (b.z * a.x);
	T _z = (a.x * b.y) - (b.x * a.y);
	T _w = 0;
	return Vec4<T>(_x, _y, _z, _w);
}

template<class T>
template<class Y>
inline T toxic::Vec4<T>::Angle(Vec4<Y>& a, Vec4<Y>& b)
{
	float dls = this->Dot(static_cast<T>(a), static_cast<T>(b)) / (static_cast<T>(a.Length()) * static_cast<T>(b.Length()));
	if(dls < -1.0f)
		dls = -1.0f;
	else if(dls > 1.0f)
		dls = 1.0f;
	return (float)acosf(dls);
}

template<class T>
inline toxic::Matrix<T> toxic::Vec4<T>::GetMatrix() const
{
	Matrix<T> _mat(4, 1);
	_mat(0, 0) = this->x;
	_mat(1, 0) = this->y;
	_mat(2, 0) = this->z;
	_mat(3, 0) = this->w;
	return _mat;
}

//template<class T>
//inline toxic::String toxic::Vec4<T>::ToString() const
//{
//	String str = "Vec4<";
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
inline float toxic::Vec4<T>::lengthSquared()
{
	return ((float)this->x * (float)this->x) + ((float)this->y * (float)this->y) + ((float)this->z * (float)this->z) + ((float)this->w * (float)this->w);
}

template<class T>
bool toxic::operator ==(const Vec4<T>& left, const Vec4<T>& right)
{
	return ((left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w));
}

template<class T>
bool toxic::operator !=(const Vec4<T>& left, const Vec4<T>& right)
{
	return !((left.x == right.x) || (left.y == right.y) || (left.z == right.z) || (left.w == right.w));
}

