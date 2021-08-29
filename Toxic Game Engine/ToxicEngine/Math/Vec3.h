#pragma once

#include "../Config.h"
#include "../System/Convert.h"
//#include "../System/IPrintable.h"
#include "Matrix.h"



namespace toxic
{
	template<class T>
	class Vec3 //: public IPrintable
	{
	public:
		Vec3();
		Vec3(T x, T y, T z);
		Vec3(const Vec3& vec);

		void Set(T x, T y, T z);
		void Scale(T scale);
		void Scale(T sx, T sy, T sz);
		void Translate(T dx, T dy, T dz);
		void Negate();
		void Normalise();
		void SwapXY();
		void SwapYZ();
		void SwapXZ();
		float Length();

		template<class Y>
		void Add(Vec3<Y>& other);

		template<class Y>
		void Sub(Vec3<Y>& other);

		template<class Y>
		static T Dot(Vec3<Y>& a, Vec3<Y>& b);

		template<class Y>
		static Vec3<T> Cross(Vec3<Y>& a, Vec3<Y> b);

		template<class Y>
		static T Angle(Vec3<Y>& a, Vec3<Y>& b);

		Matrix<T> GetMatrix() const;

		T x, y, z;
	private:
		float lengthSquared();
		//virtual String ToString() const;
	};

	template<class T>
	bool operator ==(const Vec3<T>& left, const Vec3<T>& right);

	template<class T>
	bool operator !=(const Vec3<T>& left, const Vec3<T>& right);

	typedef Vec3<int> Vec3i;
	typedef Vec3<unsigned int> Vec3u;
	typedef Vec3<float> Vec3f;
	typedef Vec3<double> Vec3d;
}
#include "Vec3.inl"
