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

layout(set = 0, binding = 0) uniform GlobalUbo {
    mat4 projection;
    mat4 view;
    vec4 ambientLight;
    vec3 lightPos;
    vec4 light;
} ubo;

const float LIGHT_RADIUS_DEFAULT = 0.1;

void main() {
    fragOffset = OFFSETS[gl_VertexIndex];

    float lightRadius = LIGHT_RADIUS_DEFAULT * ubo.light.w;

    vec3 camRightWorld = {ubo.view[0][0], ubo.view[1][0], ubo.view[2][0]};
    vec3 camUpWorld = {ubo.view[0][1], ubo.view[1][1], ubo.view[2][1]};

    vec3 posWorld = ubo.lightPos.xyz
        + lightRadius * fragOffset.x * camRightWorld
        + lightRadius * fragOffset.y * camUpWorld;
    
    gl_Position = ubo.projection * ubo.view * vec4(posWorld, 1.0);
}