#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec3 fragPosWorld;
layout(location = 2) in vec3 fragNormalWorld;

layout(location = 0) out vec4 outColor;


struct PointLight {
    vec4 position; // ignore w
    vec4 color; // w is power
};

layout(set = 0, binding = 0) uniform GlobalUbo {
    mat4 projection;
    mat4 view;
    vec4 ambientLight;
    PointLight pointLights[32];
    int numLights;
} ubo;

layout(push_constant) uniform Push {
    mat4 modelMatrix;
    mat4 normalMatrix;
} push;

void main() {
    
    vec3 diffuseLight = ubo.ambientLight.xyz * ubo.ambientLight.w;
    vec3 surfaceNormal = normalize(fragNormalWorld);

    for (int i = 0; i < ubo.numLights; i++) {
        PointLight light = ubo.pointLights[i];
        vec3 dirToLight = light.position.xyz - fragPosWorld;
        float attenuation = 1.0 / dot(dirToLight, dirToLight) /* distance squared */;
        float cosAngleOfIncidence = max(dot(surfaceNormal, normalize(dirToLight)), 0.0);
        vec3 power = light.color.xyz * light.color.w * attenuation;
    
        diffuseLight += power * cosAngleOfIncidence;
    }

    outColor = vec4( (diffuseLight * fragColor), 1.0);
}