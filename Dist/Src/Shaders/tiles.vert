#version 330 core

layout(location = 0) in vec4 position;

void main()
{
    vec4 pos = position;
    pos.y = pos.y * -1.0f;
    pos.xy = pos.xy - 320.0f;

    pos.xy = pos.xy/320.0f;
    gl_Position = pos; 
};