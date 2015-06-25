#version 130
out vec4 colour;
in vec2 uv;
uniform sampler2D diffuse;

void main()
{
    colour = texture(diffuse, uv);
}
