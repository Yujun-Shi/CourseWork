#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;
in vec3 Color;

uniform sampler2D texture_diffuse1;

uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

uniform vec3 m_diffuse;
uniform vec3 m_specular;
uniform vec3 m_ambient;
uniform vec3 m_emissive;
uniform vec3 m_transparent;
uniform float m_ref;



void main() {
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(lightPos - FragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor * m_diffuse;

	// float specularStrength = 0.5;
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = spec * lightColor * m_specular;

	// float ambientStrength = 0.1;
    vec3 ambient = lightColor * m_ambient;
    vec3 ratio = ambient + diffuse + specular;
    FragColor = vec4(ratio * Color, 1.0);

    FragColor = texture(texture_diffuse1, TexCoords) * FragColor;
}