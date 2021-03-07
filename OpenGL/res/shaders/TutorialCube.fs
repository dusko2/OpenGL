#version 460 core

out vec4 fragColor;

in vec3 position;
in vec3 normal;

uniform vec3 u_objectColor;
uniform vec3 u_lightColor;
uniform vec3 u_lightPosition;
uniform vec3 u_cameraPosition;

void main() {
    // Ambient light
    float ambientStrength = 0.1;
    vec3 ambient = u_lightColor * ambientStrength;

    // Diffuse light
    vec3 normalized = normalize(normal);
    vec3 lightDirection = normalize(u_lightPosition - position);
    float diff = max(dot(normalized, lightDirection), 0.0);
    vec3 diffuse = diff * u_lightColor;

    // Specular light
    float specularStrength = 0.5;
    vec3 cameraDirection = normalize(u_cameraPosition - position);
    vec3 reflectDirection = reflect(-lightDirection, normalized);
    float spec = pow(max(dot(cameraDirection, reflectDirection), 0.0), 32);
    vec3 specular = specularStrength * spec * u_lightColor;

    fragColor = vec4((ambient + diffuse + specular) * u_objectColor, 1.0);
}
