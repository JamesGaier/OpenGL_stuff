#version 330 core

layout (location = 0) in vec3 aPos;

out vec3 Pos;

uniform float offset;

void main()
{
    Pos = aPos;
    gl_Position = vec4(aPos.x + offset, -aPos.y, aPos.z, 1.0);
}