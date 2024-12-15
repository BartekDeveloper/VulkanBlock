#version 450

const vec2 OFFSETS[6] = vec2[](
  vec2(-1.0, -1.0),
  vec2(-1.0, 1.0),
  vec2(1.0, -1.0),
  vec2(1.0, -1.0),
  vec2(-1.0, 1.0),
  vec2(1.0, 1.0)
);

layout(location = 0) out vec2 fragOffset;

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
    vec4 position;
    vec4 color;
    float radius;
} push;

void main() {
    fragOffset = OFFSETS[gl_VertexIndex];

    vec3 camRightWorld = {ubo.view[0][0], ubo.view[1][0], ubo.view[2][0]};
    vec3 camUpWorld = {ubo.view[0][1], ubo.view[1][1], ubo.view[2][1]};

    vec3 posWorld = push.position.xyz
        + push.radius * fragOffset.x * camRightWorld
        + push.radius * fragOffset.y * camUpWorld;
    
    gl_Position = ubo.projection * ubo.view * vec4(posWorld, 1);
}