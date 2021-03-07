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
