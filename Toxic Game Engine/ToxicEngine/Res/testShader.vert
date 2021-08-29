#version 330


// Numery indeksów poszczególnych wierzchołków
#define POSITION 0

// Wspórzędne wierzchołka
layout(location = POSITION) in vec4 inPos;


void main()
{
	vec4 pos = inPos;
	//pos.x = 1;
	gl_Position = pos;
}
