#pragma once

#include "../Config.h"

#include <random>


namespace toxic
{
	class TOXIC_API Random
	{
	public:
		static char NextChar();
		static long NextInt();
		static long NextInt(long max);
		static long NextInt(long min, long max);
		static long long NextLongLong();
		static long long NextLongLong(long long max);
		static long long NextLongLong(long long min, long long max);
		static float NextFloat();
		static float NextFloat(float max);
		static float NextFloat(float min, float max);
		static double NextDouble();
		static double NextDouble(double max);
		static double NextDouble(double min, double max);
		static double NextGaussian();
		static double NextGaussian(double max);
		static double NextGaussian(double min, double max);
	};
}