#pragma once

#include "../Config.h"
#include "../Math/Random.h"
//#include "../System/IPrintable.h"



namespace toxic
{
	class TOXIC_API Color //: public IPrintable
	{
	public:
		Color();
		Color(uint32 color);
		Color(unsigned short temp);
		Color(const std::string hex);
		Color(uint8 r, uint8 g, uint8 b, uint8 a = 255);
		Color(uint16 hue, float sat, float val);
		Color(const Color& color);
		~Color();

		void Add(const Color& other);
		void Substract(const Color& other);
		void Multiply(const Color& other);

		static Color Random();
		static Color FromHSV(uint16 h, float s, float v);
		static Color FromRGB(uint8 r, uint8 g, uint8 b, uint8 a = 255);
		static Color FromInteger(uint32 color);
		static Color FromHex(const std::string hex);
		
		uint32 ToInteger() const;
		unsigned short ToKelvin() const;

		uint8 R() const;
		uint8 G() const;
		uint8 B() const;
		uint8 A() const;
		uint16 H() const;
		float S() const;
		float V() const;

		///////////////////////////////////////////////
		uint8 a;
		uint8 r;
		uint8 g;
		uint8 b;
		uint16 h;
		float s;
		float v;

		///////////////////////////////////////////////
		static const Color Black;
		static const Color Gray;
		static const Color White;
		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color Yellow;
		static const Color Magenta;
		static const Color Cyan;
		static const Color Transparent;
	
	private:
		void ToHSV();
		void ToRGB();

		//virtual String ToString() const;
	};

	TOXIC_API bool operator ==(const Color& left, const Color& right);
	TOXIC_API bool operator !=(const Color& left, const Color& right);
	TOXIC_API Color operator +(const Color& left, const Color& right);
	TOXIC_API Color operator -(Color& left, Color& right);
	TOXIC_API Color operator *(Color& left, Color& right);
	TOXIC_API Color operator +=(Color& left, Color& right);
	TOXIC_API Color operator -=(Color& left, Color& right);
	TOXIC_API Color operator *=(Color& left, Color& right);
}
