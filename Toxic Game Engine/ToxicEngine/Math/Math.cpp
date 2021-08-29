#include "Math.h"

#include <cmath>
#include <math.h>



namespace toxic
{
	const double Math::PI = 3.14159265358979323846;
	const double Math::HALF_PI = Math::PI / 2.0;
	const double Math::EULER = 2.718281828459;
	const double Math::GRAVITY_CONST = 6.67408E-11;

	////////////////////////////////////////////////////////////
	float Math::ToDegrees(float rads)
	{
		return static_cast<float>((180 / (float)PI) * (float)rads);
	}

	float Math::ToRadians(float degs)
	{
		return static_cast<float>(((float)PI / 180) * (float)degs);
	}

	float Math::Sin(float angle)
	{
		return sin(angle);
	}

	float Math::Cos(float angle)
	{
		return cos(angle);
	}

	float Math::Tan(float angle)
	{
		return tan(angle);
	}

	float Math::Cot(float angle)
	{
		return 1.0f / tan(angle);
	}

	float Math::Asin(float angle)
	{
		return asin(angle);
	}

	float Math::Acos(float angle)
	{
		return acos(angle);
	}

	float Math::Atan(float angle)
	{
		return atan(angle);
	}

	float Math::Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	float Math::Acot(float angle)
	{
		return 1.0f / atan(angle);
	}

	float Math::Sinh(float angle)
	{
		return sinh(angle);
	}

	float Math::Cosh(float angle)
	{
		return cosh(angle);
	}

	float Math::Tanh(float angle)
	{
		return tanh(angle);
	}

	float Math::Coth(float angle)
	{
		return 1.0f / tanh(angle);
	}

	float Math::Asinh(float angle)
	{
		return atan(angle);
	}

	float Math::Acosh(float angle)
	{
		return acosh(angle);
	}

	float Math::Atanh(float angle)
	{
		return atanh(angle);
	}

	float Math::Acoth(float angle)
	{
		return 1.0f / atanh(angle);
	}

	float Math::Exp(float x)
	{
		return exp(x);
	}

	float Math::Ln(float x)
	{
		return log(x);
	}

	float Math::Log10(float x)
	{
		return log10(x);
	}

	float Math::Pow(float base, float x)
	{
		return pow(base, x);
	}

	float Math::Square(float val)
	{
		return (val * val);
	}

	float Math::Sqrt(float val)
	{
		return sqrt(val);
	}

	float Math::Root(float val, float rank)
	{
		return Pow(10, 1 / (float)rank);
	}

	float Math::Hypot(float a, float b)
	{
		float sum = Square(a) + Square(b);
		return Sqrt(sum);
	}

	unsigned long Math::Factorial(unsigned long n)
	{
		unsigned long x = 1;
		for(unsigned long i = 1; i < n + 1; i++)
			x *= i;
		return x;
	}

	float Math::Min(float a, float b)
	{
		return a > b ? b : a;
	}

	float Math::Max(float a, float b)
	{
		return a > b ? a : b;
	}

	float Math::Clamp(float val, float min, float max)
	{
		return Min(Max(val, min), max);
	}

	float Math::Abs(float val)
	{
		return abs(val);
	}

	float Math::Norm(float min, float max, float val)
	{
		return (val - min) / (max - min);
	}

	long Math::Ceil(float val)
	{
		return static_cast<long>(ceil(val));
	}

	long Math::Floor(float val)
	{
		return static_cast<long>(floor(val));
	}

	float Math::Round(float val)
	{
		return (float)(val < 0 ? Ceil(val - 0.5f) : Floor(val + 0.5f));
	}

	float Math::RoundToPlaces(float val, int places)
	{
		int v = (int)Pow(10, (float)places);
		return Round(val * v) / v;
	}

	float Math::Lerp(float min, float max, float t)
	{
		return min + (max - min) * Clamp(t, 0.0f, 1.0f);
	}

	float Math::LerpUnclamped(float min, float max, float t)
	{
		return min + (max - min) * t;
	}

	float Math::Map(float val, float inMin, float inMax, float outMin, float outMax)
	{
		float v = Norm(inMin, inMax, val);
		return (float)Lerp(outMin, outMax, v);
	}

	short Math::Sign(float val)
	{
		return (val < 0 ? -1 : 1);
	}

	long Math::GCD(int a, int b)
	{
		return (b == 0 ? a : GCD(b, a % b));
	}
}
