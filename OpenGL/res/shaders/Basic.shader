// -----------------------------------------------

#shader-name:TutorialCubeVertexShader
#version 460 core

layout (location = 0) in vec3 l_position;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
    gl_Position = u_projection * u_view * u_model * vec4(l_position, 1.0);
}

// -----------------------------------------------

#shader-name:TutorialCubeFragmentShader
#version 460 core

out vec4 FragColor;

uniform vec3 u_objectColor;
uniform vec3 u_lightColor;

void main() {
    FragColor = vec4(u_objectColor * u_lightColor, 1.0f);
}

// -----------------------------------------------

#shader-name:LightSourceVertexShader
#version 460 core

layout (location = 0) in vec3 l_position;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

void main() {
    gl_Position = u_projection * u_view * u_model * vec4(l_position, 1.0);
}

// -----------------------------------------------

#shader-name:LightSourceFragmentShader
#version 460 core

out vec4 FragColor;

void main() {
    FragColor = vec4(1.0f);
}

// -----------------------------------------------

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

// -----------------------------------------------

#shader-name:CubeFragmentShader
#version 460 core

out vec4 FragColor;

in vec2 textureCoordinates;

uniform sampler2D u_texture;

void main() {
    FragColor = texture(u_texture, textureCoordinates);
}
