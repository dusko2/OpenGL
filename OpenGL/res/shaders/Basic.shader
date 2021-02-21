#shader-name:VertexShader
#version 460 core

// layout (location = 0) in vec3 l_position;
// layout (location = 1) in vec3 l_color;
// layout (location = 2) in vec2 l_texture;

layout (location = 0) in vec3 l_position;
layout (location = 1) in vec2 l_texture;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

// out vec4 color;
out vec2 textureCoordinates;

void main() {
    gl_Position = u_projection * u_view * u_model * vec4(l_position, 1.0);
    // color = vec4(l_color, 1.0);
    textureCoordinates = l_texture;
}

#shader-name:FragmentShader
#version 460 core

out vec4 FragColor;

// in vec4 color;
in vec2 textureCoordinates;

uniform sampler2D u_texture_1;
uniform sampler2D u_texture_2;

void main() {
    FragColor = mix(texture(u_texture_1, textureCoordinates), texture(u_texture_2, textureCoordinates * vec2(-1.0, 1.0)), 0.2);
}

#shader-name:CubeVertexShader
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

#shader-name:CubeFragmentShader
#version 460 core

out vec4 FragColor;

in vec2 textureCoordinates;

uniform sampler2D u_texture;

void main() {
    FragColor = texture(u_texture, textureCoordinates);
}
