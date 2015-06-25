#version 130
in vec4 vertuv;

uniform mat3 transformMatrix;

out vec2 uv;

void main()
{
    gl_Position = vec4((transformMatrix * vec3(vertuv.x, vertuv.y, 1)).xy, 0, 1);
    
    uv = vec2(vertuv.z, vertuv.w);
}
