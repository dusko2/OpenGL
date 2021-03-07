#version 460 core

out vec4 fragColor;

in vec3 position;
in vec3 normal;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 position;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform vec3 u_cameraPosition;
uniform Material material;
uniform Light light; 

void main() {
    // Ambient light
    vec3 ambient = light.ambient * material.ambient;

    // Diffuse light
    vec3 normalized = normalize(normal);
    vec3 lightDirection = normalize(light.position - position);
    float diff = max(dot(normalized, lightDirection), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);

    // Specular light
    vec3 cameraDirection = normalize(u_cameraPosition - position);
    vec3 reflectDirection = reflect(-lightDirection, normalized);
    float spec = pow(max(dot(cameraDirection, reflectDirection), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);

    fragColor = vec4(ambient + diffuse + specular, 1.0);
}
