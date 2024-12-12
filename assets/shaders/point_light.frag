#version 450

layout(location = 0) in vec2 fragOffset;
layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 0) uniform GlobalUbo {
    mat4 projection;
    mat4 view;
    vec4 ambientLight;
    vec3 lightPos;
    vec4 light;
} ubo;

void main() {
    float dist = sqrt(dot(fragOffset, fragOffset));
    if(dist >= 1.0) discard;
    outColor = vec4(ubo.light.xyz, 1.0);
}