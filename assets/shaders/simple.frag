#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec3 fragPosWorld;
layout(location = 2) in vec3 fragNormalWorld;

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 0) uniform GlobalUbo {
    mat4 projectionView;
    vec4 ambientLight;
    vec3 lightPos;
    vec4 light;
} ubo;

layout(push_constant) uniform Push {
    mat4 modelMatrix;
    mat4 normalMatrix;
} push;

void main() {
    vec3 dirToLight = ubo.lightPos - fragPosWorld;
    float attenuation = 1.0 / dot(dirToLight, dirToLight) /* distance squared */;

    vec3 lightColor = ubo.light.xyz * ubo.light.w * attenuation;
    vec3 ambientLight = ubo.ambientLight.xyz * ubo.ambientLight.w;
    vec3 diffuseLighting = lightColor * max(dot(normalize(fragNormalWorld), normalize(dirToLight)), 0.0);

    outColor = vec4( (diffuseLighting + ambientLight) * fragColor, 1.0);
}