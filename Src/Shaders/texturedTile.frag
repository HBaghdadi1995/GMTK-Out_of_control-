//Copywright (C) 2020 Hasan Al-Baghdadi
#version 330 core

uniform sampler2D u_Texture;

layout(location = 0) out vec4 color;

in vec2 texCoords;

void main()
{
    vec4 tex = texture(u_Texture, texCoords);
    //color = vec4(1,0,0,1);
    color = tex;
};