#pragma once

#include "../Config.h"
#include "../System/Convert.h"
//#include "../System/IPrintable.h"
#include "Matrix.h"



namespace toxic
{
	template<class T>
	class Vec4 //: public IPrintable
	{
	public:
		Vec4();
		Vec4(T x, T y, T z, T w);
		Vec4(const Vec4& vec);

		void Set(T x, T y, T z, T w);
		void Scale(T scale);
		void Scale(T sx, T sy, T sz, T sw);
		void Translate(T dx, T dy, T dz, T dw);
		void Negate();
		void Normalise();
		void SwapXY();
		void SwapYZ();
		void SwapXZ();
		float Length();

		template<class Y>
		void Add(Vec4<Y>& other);

		template<class Y>
		void Sub(Vec4<Y>& other);

		template<class Y>
		static T Dot(Vec4<Y>& a, Vec4<Y>& b);

		template<class Y>
		static Vec4<T> Cross(Vec4<Y>& a, Vec4<Y> b);

		template<class Y>
		static T Angle(Vec4<Y>& a, Vec4<Y>& b);

		Matrix<T> GetMatrix() const;

		T x, y, z, w;
	private:
		float lengthSquared();
		//virtual String ToString() const;
	};

	template<class T>
	bool operator ==(const Vec4<T>& left, const Vec4<T>& right);

	template<class T>
	bool operator !=(const Vec4<T>& left, const Vec4<T>& right);

	typedef Vec4<int> Vec4i;
	typedef Vec4<unsigned int> Vec4u;
	typedef Vec4<float> Vec4f;
	typedef Vec4<double> Vec4d;
}
#include "Vec4.inl"
