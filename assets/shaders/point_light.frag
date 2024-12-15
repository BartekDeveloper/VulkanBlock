#version 450

layout(location = 0) in vec2 fragOffset;
layout(location = 0) out vec4 outColor;


struct PointLight {
    vec4 position; // ignore w
    vec4 color; // w is power
};

layout(set = 0, binding = 0) uniform GlobalUbo {
    mat4 projection;
    mat4 view;
    mat4 invView;
    vec4 ambientLight;
    PointLight pointLights[32];
    int numLights;
} ubo;

layout(push_constant) uniform Push {
    vec4 position;
    vec4 color;
    float radius;
} push;

const float PI = 3.1415926538;
void main() {
    float dist = sqrt(dot(fragOffset, fragOffset));
    if(dist >= 1.0) discard;

    float cosDist =  0.5 * (cos(dist * PI) + 1.0); // 1 -> 0
    
    outColor = vec4(push.color.xyz + (cosDist * 0.75) , cosDist);
}