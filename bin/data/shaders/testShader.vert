// My test vertex shader

# version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

// The vertex shader program
void main()
{
    gl_Position = modelViewProjectionMatrix * position;
}