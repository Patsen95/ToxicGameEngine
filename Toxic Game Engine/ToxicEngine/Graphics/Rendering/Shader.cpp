#include "Shader.h"

#include <iostream>
#include <fstream>


//namespace toxic
//{
//	Shader::Shader(const std::string path, const unsigned int type)
//	{
//		filename = path;
//		// Wczytanie kodu shadera z pliku do bufora
//		std::ifstream file;
//		file.open(filename, std::ios::binary);
//
//		// Sprawdzanie b³êdów
//		if(file.bad())
//		{
//			std::cout << "[ERROR] Cannot load up shader: " << filename << std::endl;
//			std::cin.get();
//			exit(0);
//		}
//
//		file.seekg(0, std::ios::end);
//		int len = static_cast<int>(file.tellg());
//		if(len <= 0)
//		{
//			std::cout << "[ERROR] Cannot load up shader: " << filename << std::endl;
//			std::cin.get();
//			exit(0);
//		}
//
//		// W³aœciwy odczyt shadera
//		file.seekg(0, std::ios::beg);
//		char *srcBuff = new char[(len + 1) * sizeof(char)];
//		file.read(srcBuff, len);
//		srcBuff[len] = '\0';
//		file.close();
//
//		// Utworzenie obiektu shadera
//		shaderId = glCreateShader(type);
//
//		// Za³adowanie kodu do obiektu shadera
//		glShaderSource(shaderId, 1, const_cast<const char**>(&srcBuff), NULL);
//
//		// Sprz¹tamy
//		delete[] srcBuff;
//
//		Compile();
//	}
//
//	void Shader::Delete()
//	{
//		glDeleteShader(shaderId);
//	}
//
//	unsigned int Shader::GetID() const
//	{
//		return shaderId;
//	}
//	///////////////////////////////////////////
//	void Shader::Compile()
//	{
//		// Kompilacja shadera
//		glCompileShader(shaderId);
//
//		// Sprawdzenie statusu kompilacji
//		int status;
//		glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);
//		if(!status)
//		{
//			std::cout << "[ERROR] Cannot compile shader: " << filename << std::endl;
//
//			//Pobranie i wyœwietlanie komunikatu b³êdu
//			int logLength;
//			glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);
//			char* log = new char[logLength];
//			glGetShaderInfoLog(shaderId, logLength, NULL, log);
//			std::cout << log << std::endl;
//			delete[] log;
//			std::cin.get();
//			exit(0);
//		}
//	}
//}
