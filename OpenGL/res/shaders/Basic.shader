// -----------------------------------------------

#shader-name:TutorialCubeVertexShader
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

// -----------------------------------------------

#shader-name:TutorialCubeFragmentShader
#version 460 core

out vec4 fragColor;

in vec3 position;
in vec3 normal;

uniform vec3 u_objectColor;
uniform vec3 u_lightColor;
uniform vec3 u_lightPosition;

void main() {
    float ambientStrength = 0.1f;
    vec3 ambient = u_lightColor * ambientStrength;

    vec3 normalized = normalize(normal);
    vec3 lightDirection = normalize(u_lightPosition - position);
    float diff = max(dot(normalized, lightDirection), 0.0f);
    vec3 diffuse = diff * u_lightColor;

    fragColor = vec4((ambient + diffuse) * u_objectColor, 1.0f);
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
