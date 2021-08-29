#include "Random.h"


namespace toxic
{
	char Random::NextChar()
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_int_distribution<short> _distr(std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
		return static_cast<char>(_distr(_gen));
	}

	long Random::NextInt()
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_int_distribution<long> _distr(std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
		return _distr(_gen);
	}

	long Random::NextInt(long max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_int_distribution<long> _distr(std::numeric_limits<long>::min(), max);
		return _distr(_gen);
	}

	long Random::NextInt(long min, long max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_int_distribution<long> _distr(min, max);
		return _distr(_gen);
	}

	long long Random::NextLongLong()
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_int_distribution<long long> _distr(std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
		return _distr(_gen);
	}

	long long Random::NextLongLong(long long max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_int_distribution<long long> _distr(std::numeric_limits<long long>::min(), max);
		return _distr(_gen);
	}

	long long Random::NextLongLong(long long min, long long max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_int_distribution<long long> _distr(min, max);
		return _distr(_gen);
	}

	float Random::NextFloat()
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_real_distribution<float> _distr(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
		return _distr(_gen);
	}

	float Random::NextFloat(float max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_real_distribution<float> _distr(std::numeric_limits<float>::min(), max);
		return _distr(_gen);
	}

	float Random::NextFloat(float min, float max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_real_distribution<float> _distr(min, max);
		return _distr(_gen);
	}

	double Random::NextDouble()
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_real_distribution<double> _distr(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
		return _distr(_gen);
	}

	double Random::NextDouble(double max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_real_distribution<double> _distr(std::numeric_limits<double>::min(), max);
		return _distr(_gen);
	}

	double Random::NextDouble(double min, double max)
	{
		std::random_device _device;
		std::mt19937_64 _gen(_device());
		std::uniform_real_distribution<double> _distr(min, max);
		return _distr(_gen);
	}

	double Random::NextGaussian()
	{
		std::random_device _device;
		std::default_random_engine _gen(_device());
		std::normal_distribution<double> _dist(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
		return _dist(_gen);
	}

	double Random::NextGaussian(double max)
	{
		std::random_device _device;
		std::default_random_engine _gen(_device());
		std::normal_distribution<double> _dist(std::numeric_limits<double>::min(), max);
		return _dist(_gen);
	}

	double Random::NextGaussian(double min, double max)
	{
		std::random_device _device;
		std::default_random_engine _gen(_device());
		std::normal_distribution<double> _dist(min, max);
		return _dist(_gen);
	}
}