#pragma once

#include "../Config.h"


namespace toxic
{
	class TOXIC_API Math
	{
	public:
		static float ToDegrees(float rads);
		static float ToRadians(float degs);
		static float Sin(float angle);
		static float Cos(float angle);
		static float Tan(float angle);
		static float Cot(float angle);
		static float Asin(float angle);
		static float Acos(float angle);
		static float Atan(float angle);
		static float Atan2(float y, float x);
		static float Acot(float angle);
		static float Sinh(float angle);
		static float Cosh(float angle);
		static float Tanh(float angle);
		static float Coth(float angle);
		static float Asinh(float angle);
		static float Acosh(float angle);
		static float Atanh(float angle);
		static float Acoth(float angle);

		static float Exp(float x);
		static float Ln(float x);
		static float Log10(float x);
		static float Pow(float base, float x);
		static float Square(float val);
		static float Sqrt(float val);
		static float Root(float val, float rank);
		static float Hypot(float a, float b);
		static unsigned long Factorial(unsigned long n);

		static float Min(float a, float b);
		static float Max(float a, float b);
		static float Clamp(float val, float min, float max);
		static float Abs(float val);
		static float Norm(float min, float max, float val);
		static long Ceil(float val);
		static long Floor(float val);
		static float Round(float val);
		static float RoundToPlaces(float val, int places);
		static float Lerp(float min, float max, float t);
		static float LerpUnclamped(float min, float max, float t);
		static float Map(float val, float inMin, float inMax, float outMin, float outMax);
		static short Sign(float val);
		static long GCD(int a, int b);

		static const double PI;
		static const double HALF_PI;
		static const double EULER;
		static const double GRAVITY_CONST;
	};
}
