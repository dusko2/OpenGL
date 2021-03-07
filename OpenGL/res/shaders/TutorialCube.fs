#version 460 core

out vec4 fragColor;

in vec3 position;
in vec3 normal;
in vec2 textureCoords;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
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
    vec3 textureDiffuse = texture(material.diffuse, textureCoords).rgb;
    vec3 textureSpecular = texture(material.specular, textureCoords).rgb;

    // Ambient light
    vec3 ambient = light.ambient * textureDiffuse;

    // Diffuse light
    vec3 normalized = normalize(normal);
    vec3 lightDirection = normalize(light.position - position);
    float diff = max(dot(normalized, lightDirection), 0.0);
    vec3 diffuse = light.diffuse * diff * textureDiffuse;

    // Specular light
    vec3 cameraDirection = normalize(u_cameraPosition - position);
    vec3 reflectDirection = reflect(-lightDirection, normalized);
    float spec = pow(max(dot(cameraDirection, reflectDirection), 0.0), material.shininess);
    vec3 specular = light.specular * spec * textureSpecular;

    fragColor = vec4(ambient + diffuse + specular, 1.0);
}
