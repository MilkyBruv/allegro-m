// vertex shader
varying vec2 uv;
void main(void)
{

    gl_Position = ftransform();
    uv = gl_MultiTexCoord0.xy;

}