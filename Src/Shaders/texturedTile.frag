#version 330 core

uniform sampler2D u_Texture;

layout(location = 0) out vec4 color;

void main()
{
    vec4 tex = texture(u_Texture, vec2(0.5f,0.5f));
    //color = vec4(1,0,0,1);
    color = tex;
};