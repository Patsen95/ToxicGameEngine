#pragma once

//#include <glew.h>
//#include <freeglut.h>
#include <string>


namespace toxic
{
	class Shader
	{
	public:
		enum
		{
			VERTEX, //= GL_VERTEX_SHADER,
			FRAGMENT //= //GL_FRAGMENT_SHADER
		};

		Shader(const std::string path, const unsigned int type);

		void Delete();

		unsigned int GetID() const;

	private:
		std::string filename;
		unsigned int shaderId;
		unsigned int programId;

		void Compile();
	};
}
