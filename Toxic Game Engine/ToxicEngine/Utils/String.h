#pragma once

#include "../Config.h"

#include <iostream>


namespace toxic
{
	class TOXIC_API String
	{
	public:
		String();
		String(const char* str);
		String(const std::string& str);
		String(const String& other);
		~String();

		String& operator=(const String& other);
		String operator+(const String& other);
		String& operator+=(const String& other);
		bool operator==(const String& other);
		bool operator!=(const String& other);
		char operator[](size_t offset);
		friend std::ostream& operator<<(std::ostream& os, const String& str);

		void Clear();

		String& ToUpper();
		String& ToLower();
		String& Append(const char ch);
		String& Append(const char* str);
		String& Append(const String& str);
		size_t Find(const char ch, size_t pos = 0) const;
		size_t Find(const char* str, size_t pos = 0) const;
		size_t Find(const String& str, size_t pos = 0) const;
		//String& Insert(const size_t idx, const char ch);
		String& Insert(const size_t idx, const char* str);
		String& Insert(const size_t idx, const String& str);
		//String& Replace(size_t start, size_t end, const char ch);
		String& Replace(size_t start, size_t end, const char* str);
		String& Replace(size_t start, size_t end, const String& str);
		String Substring(size_t start, size_t end);

		bool Compare(const String& other) const;
		bool Compare(bool(*cmpFuncPtr)(const String& original)) const;
		bool Contains(const char ch) const;
		bool Contains(const char* str) const;
		bool Contains(const String& str) const;
		bool IsEmpty() const;
		const char At(size_t idx) const;
		const char Back() const;
		const char Front() const;
		const size_t Length();
		const char* C_Str();


	private:
		std::string _str;
		uint _strLength;
	};

	inline std::ostream& operator<<(std::ostream& os, const String& str)
	{
		return os << str._str.c_str();
	}
}
