#version 330


out vec4 outColor;

uniform bool demo = false;
uniform float sinVal = 0.0f;
uniform float red = 1.0f;
uniform float green = 0.0f;
uniform float blue = 0.0f;

void main()
{
	float color;
	if(demo)
	{	color = sin(sinVal);
		outColor = vec4(color, green, blue, 1);
	}
	else
		outColor = vec4(red, green, blue, 1);
}
