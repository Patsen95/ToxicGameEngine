#pragma once

#include "../Config.h"
#include "../System/Convert.h"
//#include "../System/IPrintable.h"
#include "Matrix.h"



namespace toxic
{
	template<class T>
	class Vec2 //: public IPrintable
	{
	public:
		Vec2();
		Vec2(T x, T y);
		Vec2(const Vec2& vec);

		void Set(T x, T y);
		void Scale(T scale);
		void Scale(T sx, T sy);
		void Translate(T dx, T dy);
		void Negate();
		void Normalise();
		void Swap();
		float Length();

		template<class Y>
		void Add(Vec2<Y>& other);

		template<class Y>
		void Sub(Vec2<Y>& other);

		template<class Y>
		static T Dot(Vec2<Y>& a, Vec2<Y>& b);

		template<class Y>
		static T Angle(Vec2<Y>& a, Vec2<Y>& b);

		Matrix<T> GetMatrix() const;

		T x, y;
	private:
		float lengthSquared();
		//virtual String ToString() const;
	};

	template<class T>
	bool operator ==(const Vec2<T>& left, const Vec2<T>& right);

	template<class T>
	bool operator !=(const Vec2<T>& left, const Vec2<T>& right);

	typedef Vec2<int> Vec2i;
	typedef Vec2<unsigned int> Vec2u;
	typedef Vec2<float> Vec2f;
	typedef Vec2<double> Vec2d;
}
#include "Vec2.inl"
