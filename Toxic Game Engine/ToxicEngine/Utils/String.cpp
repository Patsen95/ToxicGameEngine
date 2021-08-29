#include "String.h"




namespace toxic
{
	String::String()
	{
		this->_str = std::string();
		this->_strLength = 0;
	}

	String::String(const char* str)
	{
		this->_str = std::string(str);
		this->_strLength = _str.size();
	}

	String::String(const std::string& str)
	{
		this->_str = str;
		this->_strLength = str.size();
	}

	String::String(const String& other)
	{
		this->_str = other._str;
		this->_strLength = other._strLength;
	}

	String::~String()
	{
	}

	String& String::operator=(const String& other)
	{
		if(&other == this)
			return (*this);
		this->_str = other._str;
		this->_strLength = other._strLength;
		return (*this);
	}

	String String::operator+(const String& other)
	{
		String str((*this));
		str._str.append(other._str);
		return str;
	}

	String& String::operator+=(const String& other)
	{
		this->_str += other._str;
		return (*this);
	}

	bool String::operator==(const String& other)
	{
		return !strcmp(this->_str.c_str(), other._str.c_str());
	}

	bool String::operator!=(const String& other)
	{
		return strcmp(this->_str.c_str(), other._str.c_str());
	}

	char String::operator[](size_t offset)
	{
		return this->_str[offset];
	}

	void String::Clear()
	{
		this->_str.clear();
		this->_strLength = 0;
	}

	String& String::ToUpper()
	{
		for(uint i = 0; i < this->_strLength; i++)
			this->_str[i] -= (char)32;
		return (*this);
	}

	String& String::ToLower()
	{
		for(uint i = 0; i < this->_strLength; i++)
			this->_str[i] += (char)32;
		return (*this);
	}

	String& String::Append(const char ch)
	{
		this->_str += ch;
		return (*this);
	}

	String& String::Append(const char* str)
	{
		this->_str += str;
		return (*this);
	}

	String& String::Append(const String& str)
	{
		this->_str += str._str;
		return (*this);
	}

	size_t String::Find(const char ch, size_t pos) const
	{
		return this->_str.find(ch, pos);
	}

	size_t String::Find(const char* str, size_t pos) const
	{
		return this->_str.find(str, pos);
	}

	size_t String::Find(const String& str, size_t pos) const
	{
		return this->_str.find(str._str, pos);
	}

	String& String::Insert(const size_t idx, const char* str)
	{
		this->_str.insert(idx, str);
		return (*this);
	}

	String& String::Insert(const size_t idx, const String& str)
	{
		this->_str.insert(idx, str._str);
		return (*this);
	}

	String& String::Replace(size_t start, size_t end, const char* str)
	{
		this->_str.replace(start, end, str);
		return (*this);
	}

	String& String::Replace(size_t start, size_t end, const String& str)
	{
		this->_str.replace(start, end, str._str);
		return (*this);
	}

	String String::Substring(size_t start, size_t end)
	{
		return String(this->_str.substr(start, end));
	}

	bool String::Compare(const String& other) const
	{
		return this->_str.compare(other._str);
	}

	bool String::Compare(bool(*cmpFuncPtr)(const String& original)) const
	{
		return cmpFuncPtr((*this));
	}

	bool String::Contains(const char ch) const
	{
		return (Find(ch) != std::string::npos);
	}

	bool String::Contains(const char* str) const
	{
		return (Find(str) != std::string::npos);
	}

	bool String::Contains(const String& str) const
	{
		return (Find(str) != std::string::npos);
	}

	bool String::IsEmpty() const
	{
		return this->_str.empty();
	}

	const char String::At(size_t idx) const
	{
		return this->_str.at(idx);
	}

	const char String::Back() const
	{
		return this->_str[_strLength - 1];
	}

	const char String::Front() const
	{
		return this->_str[0];
	}

	const size_t String::Length()
	{
		this->_strLength = this->_str.length();
		return _strLength;
	}

	const char* String::C_Str()
	{
		return this->_str.c_str();
	}
}
