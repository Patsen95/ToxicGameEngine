#include "Color.h"
#include "../Math/Math.h"
#include "../System/Convert.h"



namespace toxic
{
	/////////////////////////////////////////////////
	const Color Color::Black((uint8)0, 0, 0);
	const Color Color::Gray((uint8)128, 128, 128);
	const Color Color::White((uint8)255, 255, 255);
	const Color Color::Red((uint8)255, 0, 0);
	const Color Color::Green((uint8)0, 255, 0);
	const Color Color::Blue((uint8)0, 0, 255);
	const Color Color::Yellow((uint8)255, 255, 0);
	const Color Color::Magenta((uint8)255, 0, 255);
	const Color Color::Cyan((uint8)0, 255, 255);
	const Color Color::Transparent(0, 0, 0, 0);
	/////////////////////////////////////////////////
	Color::Color()
	{
		this->r = 0;
		this->g = 0;
		this->b = 0;
		this->a = 255;
		this->h = 0;
		this->s = 0.0f;
		this->v = 0.0f;
	}

	Color::Color(uint32 color)
	{
		this->r = ((color & 0xff000000) >> 24);
		this->g = ((color & 0x00ff0000) >> 16);
		this->b = ((color & 0x0000ff00) >> 8);
		this->a = (color & 0x000000ff);
		this->ToHSV();
	}

	Color::Color(unsigned short temp)
	{
		this->ToHSV();
	}

	Color::Color(const std::string hex)
	{
		uint32 cval = std::strtoul(hex.c_str(), NULL, 0);
		this->r = ((cval & 0xff000000) >> 24);
		this->g = ((cval & 0x00ff0000) >> 16);
		this->b = ((cval & 0x0000ff00) >> 8);
		this->a = (cval & 0x000000ff);
		this->ToHSV();
	}

	Color::Color(uint8 r, uint8 g, uint8 b, uint8 a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
		this->ToHSV();
	}

	Color::Color(uint16 hue, float sat, float val)
	{
		this->h = (uint16)Math::Clamp(hue, 0, 360);
		this->s = Math::Clamp(sat, 0.0f, 1.0f);
		this->v = Math::Clamp(val, 0.0f, 1.0f);
		this->ToRGB();
	}

	Color::Color(const Color& color)
	{
		this->r = color.r;
		this->g = color.g;
		this->b = color.b;
		this->a = color.a;
		this->h = color.h;
		this->s = color.s;
		this->v = color.v;
	}

	Color::~Color() { }

	Color Color::Random()
	{
		uint8 r = (uint8)Random::NextInt(0, 255);
		uint8 g = (uint8)Random::NextInt(0, 255);
		uint8 b = (uint8)Random::NextInt(0, 255);
		uint8 a = (uint8)Random::NextInt(0, 255);
		return Color(r, g, b, a);
	}

	Color Color::FromHSV(uint16 h, float s, float v)
	{
		h = (uint16)Math::Clamp(h, 0, 360);
		s = Math::Clamp(s, 0.0f, 1.0f);
		v = Math::Clamp(v, 0.0f, 1.0f);
		return Color(h, s, v);
	}

	Color Color::FromRGB(uint8 r, uint8 g, uint8 b, uint8 a)
	{
		return Color(r, g, b, a);
	}

	Color Color::FromInteger(uint32 color)
	{
		return Color(color);
	}

	Color Color::FromHex(const std::string hex)
	{
		uint32 cval = std::strtoul(hex.c_str(), NULL, 0);
		return Color(cval);
	}
	/////////////////////////////////////////////////
	void Color::Add(const Color& other)
	{
		this->r += other.r;
		this->g += other.g;
		this->b += other.b;
		this->a += other.a;
		this->h += other.h;
		this->s += other.s;
		this->v += other.v;
	}

	void Color::Substract(const Color& other)
	{
		this->r -= other.r;
		this->g -= other.g;
		this->b -= other.b;
		this->a -= other.a;
		this->h -= other.h;
		this->s -= other.s;
		this->v -= other.v;
	}

	void Color::Multiply(const Color& other)
	{
		this->r *= other.r;
		this->g *= other.g;
		this->b *= other.b;
		this->a *= other.a;
		this->h *= other.h;
		this->s *= other.s;
		this->v *= other.v;
	}

	uint32 Color::ToInteger() const
	{
		return ((this->r << 24) | (this->g << 16) | (this->b << 8) | this->a);
	}

	unsigned short Color::ToKelvin() const
	{
		return 0;
	}

	uint8 Color::R() const
	{
		return this->r;
	}

	uint8 Color::G() const
	{
		return this->g;
	}

	uint8 Color::B() const
	{
		return this->b;
	}

	uint8 Color::A() const
	{
		return this->a;
	}

	uint16 Color::H() const
	{
		return this->h;
	}

	float Color::S() const
	{
		return this->s;
	}

	float Color::V() const
	{
		return this->v;
	}

	/*String Color::ToString() const
	{
		String str("Color(r=");
		str.Append(Convert::ToString(this->r));
		str.Append(", g=").Append(Convert::ToString(this->g));
		str.Append(", b=").Append(Convert::ToString(this->b));
		str.Append(", a=").Append(Convert::ToString(this->a));
		str.Append(" | h=").Append(Convert::ToString(this->h));
		str.Append(", s=").Append(Convert::ToString(this->s));
		str.Append(", v=").Append(Convert::ToString(this->v));
		str.Append(" | temp=").Append(Convert::ToString(this->temperature));
		str.Append(" K)");
		return str;
	}*/
	/////////////////////////////////////////////////
	void Color::ToHSV()
	{
		//https://www.rapidtables.com/convert/color/rgb-to-hsv.html

		float _r = this->r / 255.0f;
		float _g = this->g / 255.0f;
		float _b = this->b / 255.0f;

		float cmax = Math::Max(Math::Max(_r, _g), _b);
		float cmin = Math::Min(Math::Min(_r, _g), _b);
		float delta = cmax - cmin;

		this->v = cmax;
		this->s = cmax == 0 ? 0 : (delta / cmax);

		if(!delta)
			this->h = 0;	

		if(cmax == _r)
			this->h = 60 * ((uint16)((_g - _b) / delta) % 6);
		else if(cmax == _g)
			this->h = 60 * ((uint16)((_b - _r) / delta) + 2);
		else if(cmax == _b)
			this->h = 60 * ((uint16)((_r - _g) / delta) + 4);
	}

	void Color::ToRGB()
	{
		// https://www.rapidtables.com/convert/color/hsv-to-rgb.html

		float _c = this->v * this->s;
		float _x = _c * (1 - Math::Abs((float)((this->h / 60) % 2) - 1));
		float _m = this->v - _c;

		float _r, _g, _b;

		if(this->h >= 0 && this->h < 60)
		{
			_r = _c;
			_g = _x;
			_b = 0;
		}
		else if(this->h >= 60 && this->h < 120)
		{
			_r = _x;
			_g = _c;
			_b = 0;
		}
		else if(this->h >= 120 && this->h < 180)
		{
			_r = 0;
			_g = _c;
			_b = _x;
		}
		else if(this->h >= 180 && this->h < 240)
		{
			_r = 0;
			_g = _x;
			_b = _c;
		}
		else if(this->h >= 240 && this->h < 300)
		{
			_r = _x;
			_g = 0;
			_b = _c;
		}
		else if(this->h >= 300 && this->h < 360)
		{
			_r = _c;
			_g = 0;
			_b = _x;
		}
		this->r = (uint8)((_r + _m) * 255);
		this->g = (uint8)((_g + _m) * 255);
		this->b = (uint8)((_b + _m) * 255);
	}
	/////////////////////////////////////////////////
	bool operator==(const Color& left, const Color& right)
	{
		return ((left.r == right.r) &&
			(left.g == right.g) &&
			(left.b == right.b) &&
			(left.a == right.a) &&
			(left.h == right.h) &&
			(left.s == right.s) &&
			(left.v == right.v));
	}

	bool operator!=(const Color& left, const Color& right)
	{
		return !(left == right);
	}
	
	Color operator+(Color& left, Color& right)
	{
		return Color((uint8)(Math::Min((float)left.r + (float)right.r, 255)),
			(uint8)(Math::Min((float)left.g + (float)right.g, 255)),
			(uint8)(Math::Min((float)left.b + (float)right.b, 255)),
			(uint8)(Math::Min((float)left.a + (float)right.a, 255)));
	}

	Color operator-(Color& left, Color& right)
	{
		return Color((uint8)(Math::Max((float)left.r - (float)right.r, 0)),
			(uint8)(Math::Max((float)left.g - (float)right.g, 0)),
			(uint8)(Math::Max((float)left.b - (float)right.b, 0)),
			(uint8)(Math::Max((float)left.a - (float)right.a, 0)));
	}

	Color operator*(Color& left, Color& right)
	{
		return Color((uint8)(left.r * right.r / 255),
			(uint8)(left.g * right.g / 255),
			(uint8)(left.b * right.b / 255),
			(uint8)(left.a * right.a / 255));
	}

	Color operator+=(Color& left, Color& right)
	{
		return left =  left + right;
	}
	
	Color operator-=(Color& left, Color& right)
	{
		return left = left - right;
	}
	
	Color operator*=(Color& left, Color& right)
	{
		return left = left * right;
	}
}
