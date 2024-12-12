#version 450

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec2 uv;

layout(location = 0) out vec3 fragColor;

layout(push_constant) uniform Push {
    mat4 transform; // proj * view * model
    mat4 normalMatrix;
} push;

const vec3 DIR_TO_LIGHT = normalize(vec3(1.0, -3.0, -1.0));
const float AMBIENT = 0.01; // Normalized ambient value

void main() {
    gl_Position = vec4(push.transform * vec4(position, 1.0));

    vec3 normalWorldSpace = normalize(mat3(push.normalMatrix) * normal);
    float lightIntensity = max(dot(normalWorldSpace, DIR_TO_LIGHT), 0.0);

    // Combine diffuse and ambient light
    vec3 diffuse = lightIntensity * color;
    vec3 ambient = AMBIENT * color;
    
    fragColor = diffuse + ambient; // Final color
}
