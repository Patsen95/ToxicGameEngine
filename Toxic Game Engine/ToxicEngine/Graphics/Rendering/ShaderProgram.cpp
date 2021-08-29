#include "ShaderProgram.h"

//#include <glew.h>
//#include <freeglut.h>
//#include <iostream>
//
//
//namespace toxic
//{
//	ShaderProgram::ShaderProgram()
//	{
//		programId = glCreateProgram();
//		shadersAttached = 0;
//	}
//
//	void ShaderProgram::AttachShader(const Shader* shader)
//	{
//		if(!programId)
//			return;
//		glAttachShader(programId, shader->GetID());
//		LinkAndValidate();
//		shadersAttached++;
//	}
//
//	void ShaderProgram::DetachShader(const Shader* shader)
//	{
//		glDetachShader(programId, shader->GetID());
//		LinkAndValidate();
//		shadersAttached--;
//	}
//
//	void ShaderProgram::Run()
//	{
//		glUseProgram(programId);
//	}
//
//	void ShaderProgram::Stop()
//	{
//		glUseProgram(0);
//	}
//
//	unsigned int ShaderProgram::ReadUint(const std::string varName)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		unsigned int v = NULL;
//		glGetUniformuiv(programId, loc, &v);
//		return v;
//	}
//
//	int ShaderProgram::ReadInt(const std::string varName)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		int v = NULL;
//		glGetUniformiv(programId, loc, &v);
//		return v;
//	}
//
//	float ShaderProgram::ReadFloat(const std::string varName)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		float v = NULL;
//		glGetUniformfv(programId, loc, &v);
//		return v;
//	}
//
//	double ShaderProgram::ReadDouble(const std::string varName)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		double v = NULL;
//		glGetUniformdv(programId, loc, &v);
//		return v;
//	}
//
//	void ShaderProgram::SetBool(const std::string varName, bool val)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		glProgramUniform1i(programId, loc, (val ? 1 : 0));
//	}
//
//	void ShaderProgram::SetUint(const std::string varName, unsigned int val)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		glProgramUniform1ui(programId, loc, val);
//	}
//
//	void ShaderProgram::SetInt(const std::string varName, int val)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		glProgramUniform1i(programId, loc, val);
//	}
//
//	void ShaderProgram::SetFloat(const std::string varName, float val)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		glProgramUniform1f(programId, loc, val);
//	}
//
//	void ShaderProgram::SetDouble(const std::string varName, double val)
//	{
//		int loc = glGetUniformLocation(programId, varName.c_str());
//		glProgramUniform1d(programId, loc, val);
//	}
//
//	void ShaderProgram::Delete()
//	{
//		if(shadersAttached == 0)
//			glDeleteProgram(programId);
//	}
//
//	unsigned int ShaderProgram::GetID() const
//	{
//		return programId;
//	}
//	///////////////////////////////////////////
//	void ShaderProgram::LinkAndValidate()
//	{
//		// Konsolidacja shaderów
//		glLinkProgram(programId);
//
//		// Sprawdzenie poprawnoœci konsolidacji obiektu programu
//		int status;
//		glGetProgramiv(programId, GL_LINK_STATUS, &status);
//		if(!status)
//		{
//			std::cout << "[ERROR] Can't link program object" << std::endl;
//
//			// Pobranie i wyœwietlenie b³êdu
//			int logLength;
//			glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);
//			char* log = new char[logLength];
//			glGetProgramInfoLog(programId, logLength, NULL, log);
//			std::cout << log << std::endl;
//			delete[] log;
//			std::cin.get();
//			exit(0);
//		}
//		// Walidacja shaderów
//		glValidateProgram(programId);
//
//		// Sprawdzenie poprawnoœci walidacji obiektu programu
//		glGetProgramiv(programId, GL_VALIDATE_STATUS, &status);
//		if(!status)
//		{
//			std::cout << "[ERROR] Can't validate program object" << std::endl;
//
//			// Pobranie i wyœwietlenie b³êdu
//			int logLength;
//			glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &logLength);
//			char* log = new char[logLength];
//			glGetProgramInfoLog(programId, logLength, NULL, log);
//			std::cout << log << std::endl;
//			delete[] log;
//			std::cin.get();
//			exit(0);
//		}
//	}
//}
