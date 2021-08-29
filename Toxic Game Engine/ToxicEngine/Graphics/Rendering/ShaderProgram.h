#pragma once

#include "Shader.h"


namespace toxic
{
	class ShaderProgram
	{
	public:
		ShaderProgram();

		void AttachShader(const Shader* shader);
		void DetachShader(const Shader* shader);
		void Run();
		void Stop();
		void Delete();

		void SetBool(const std::string varName, bool val);
		void SetUint(const std::string varName, unsigned int val);
		void SetInt(const std::string varName, int val);
		void SetFloat(const std::string varName, float val);
		void SetDouble(const std::string varName, double val);

		unsigned int ReadUint(const std::string varName);
		int ReadInt(const std::string varName);
		float ReadFloat(const std::string varName);
		double ReadDouble(const std::string varName);

		unsigned int GetID() const;

	private:
		unsigned int programId;
		unsigned short shadersAttached;

		void LinkAndValidate();
	};
}
