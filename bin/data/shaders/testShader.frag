// My testFragment shader

#version 150

out vec4 outputColor;

// The Pixel Shader
void main()
{
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
    float r = gl_FragCoord.x / windowWidth;
    float g = gl_FragCoord.y / windowHeight;
    float b = 1.0;
    float a = 1.0;
    
    // Set the pixel color:
    outputColor = vec4(r,g,b,a);
}