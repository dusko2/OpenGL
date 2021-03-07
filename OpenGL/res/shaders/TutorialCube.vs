#version 460 core

layout (location = 0) in vec3 l_position;
layout (location = 1) in vec3 l_normal;

out vec3 position;
out vec3 normal;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
    gl_Position = u_projection * u_view * u_model * vec4(l_position, 1.0f);
    position = vec3(u_model * vec4(l_position, 1.0f));
    normal = mat3(transpose(inverse(u_model))) * l_normal;
}
