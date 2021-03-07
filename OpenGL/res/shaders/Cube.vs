#version 460 core

layout(location = 0) in vec3 l_position;
layout(location = 1) in vec2 l_texture;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec2 textureCoordinates;

void main() {
    gl_Position = u_projection * u_view * u_model * vec4(l_position, 1.0);
    textureCoordinates = l_texture;
}