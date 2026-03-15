#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

out vec4 finalColor;

void main() {
    vec2 uv = fragTexCoord - vec2(0.5);
    float distance = length(uv);

    if (distance > 0.5)
        discard;
    
    float alpha = smoothstep(0.5, 0.48, distance);
    finalColor = vec4(fragColor.rgb, fragColor.a * alpha);
}