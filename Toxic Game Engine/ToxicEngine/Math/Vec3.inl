#include "Vec3.h"

#include <cmath>



template<class T>
inline toxic::Vec3<T>::Vec3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

template<class T>
inline toxic::Vec3<T>::Vec3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<class T>
inline toxic::Vec3<T>::Vec3(const Vec3& vec)
{
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
}

template<class T>
inline void toxic::Vec3<T>::Set(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<class T>
inline void toxic::Vec3<T>::Scale(T scale)
{
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;
}

template<class T>
inline void toxic::Vec3<T>::Scale(T sx, T sy, T sz)
{
	this->x *= sx;
	this->y *= sy;
	this->z *= sz;
}

template<class T>
inline void toxic::Vec3<T>::Translate(T dx, T dy, T dz)
{
	this->x += dx;
	this->y += dy;
	this->z += dz;
}

template<class T>
inline void toxic::Vec3<T>::Negate()
{
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
}

template<class T>
inline void toxic::Vec3<T>::Normalise()
{
	float len = this->Length();
	this->x /= len;
	this->y /= len;
	this->z /= len;
}

template<class T>
inline void toxic::Vec3<T>::SwapXY()
{
	T _x = this->x;
	this->x = this->y;
	this->y = _x;
}

template<class T>
inline void toxic::Vec3<T>::SwapYZ()
{
	T _y = this->y;
	this->y = this->z;
	this->z = _y;
}

template<class T>
inline void toxic::Vec3<T>::SwapXZ()
{
	T _x = this->x;
	this->x = this->z;
	this->z = _x;
}

template<class T>
inline float toxic::Vec3<T>::Length()
{
	return sqrtf(lengthSquared());
}

template<class T>
template<class Y>
inline void toxic::Vec3<T>::Add(Vec3<Y>& other)
{
	this->x += static_cast<T>(other.x);
	this->y += static_cast<T>(other.y);
	this->z -= static_cast<T>(other.z);
}

template<class T>
template<class Y>
inline void toxic::Vec3<T>::Sub(Vec3<Y>& other)
{
	this->x -= static_cast<T>(other.x);
	this->y -= static_cast<T>(other.y);
	this->z -= static_cast<T>(other.z);
}

template<class T>
template<class Y>
inline T toxic::Vec3<T>::Dot(Vec3<Y>& a, Vec3<Y>& b)
{
	return (static_cast<T>(a.x) * static_cast<T>(b.x)) + (static_cast<T>(a.y) * static_cast<T>(b.y) + (static_cast<T>(a.z) * static_cast<T>(b.z)));
}

template<class T>
template<class Y>
inline toxic::Vec3<T> toxic::Vec3<T>::Cross(Vec3<Y>& a, Vec3<Y> b)
{
	T _x = (a.y * b.z) - (b.y * a.z);
	T _y = (a.z * b.x) - (b.z * a.x);
	T _z = (a.x * b.y) - (b.x * a.y);
	return Vec3<T>(_x, _y, _z);
}

template<class T>
template<class Y>
inline T toxic::Vec3<T>::Angle(Vec3<Y>& a, Vec3<Y>& b)
{
	float dls = this->Dot(static_cast<T>(a), static_cast<T>(b)) / (static_cast<T>(a.Length()) * static_cast<T>(b.Length()));
	if(dls < -1.0f)
		dls = -1.0f;
	else if(dls > 1.0f)
		dls = 1.0f;
	return (float)acosf(dls);
}

template<class T>
inline toxic::Matrix<T> toxic::Vec3<T>::GetMatrix() const
{
	Matrix<T> _mat(3, 1);
	_mat(0, 0) = this->x;
	_mat(1, 0) = this->y;
	_mat(2, 0) = this->z;
	return _mat;
}

//template<class T>
//inline toxic::String toxic::Vec3<T>::ToString() const
//{
//	String str = "Vec3<";
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
inline float toxic::Vec3<T>::lengthSquared()
{
	return ((float)this->x * (float)this->x) + ((float)this->y * (float)this->y) + ((float)this->z * (float)this->z);
}

template<class T>
bool toxic::operator ==(const Vec3<T>& left, const Vec3<T>& right)
{
	return ((left.x == right.x) && (left.y == right.y) && (left.z == right.z));
}

template<class T>
bool toxic::operator !=(const Vec3<T>& left, const Vec3<T>& right)
{
	return !((left.x == right.x) || (left.y == right.y) || (left.z == right.z));
}
