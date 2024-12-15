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
    mat4 invView;
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
    vec3 specularLight = vec3(0.0);
    vec3 surfaceNormal = normalize(fragNormalWorld);

    vec3 cameraPosInWorld = ubo.invView[3].xyz;
    vec3 viewDir = normalize(cameraPosInWorld - fragPosWorld);

    for (int i = 0; i < ubo.numLights; i++) {
        PointLight light = ubo.pointLights[i];

        vec3 dirToLight = light.position.xyz - fragPosWorld;
        float attenuation = 1.0 / dot(dirToLight, dirToLight) /* distance squared */;

        dirToLight = normalize(dirToLight);
        float cosAngleOfIncidence = max(dot(surfaceNormal, dirToLight), 0.0);
        vec3 power = light.color.xyz * light.color.w * attenuation;
    
        diffuseLight += power * cosAngleOfIncidence;
    
        // Specular Lighting
        vec3 halfAngle = normalize(dirToLight + viewDir);
        float blinnTerm = dot(surfaceNormal, halfAngle);
        blinnTerm = clamp(blinnTerm, 0, 1);
        blinnTerm = pow(blinnTerm, 128.0); // higher values -> sharper highlight

        specularLight += power * blinnTerm;
    }

    outColor = vec4( (diffuseLight * fragColor + specularLight * fragColor), 1.0);
}