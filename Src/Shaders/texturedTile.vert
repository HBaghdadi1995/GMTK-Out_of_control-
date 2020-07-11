#version 330 core

layout(location = 0) in vec4 position;

void main()
{
    vec4 pos = position;
    pos.xy = pos.xy - vec2(320.0f,240.0f);
    pos.y = pos.y * -1.0f;

    pos.x = pos.x/320.0f;
    pos.y = pos.y/240.0f;
    gl_Position = pos; 
};