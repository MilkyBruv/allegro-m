// fragment shader
#ifdef GL_ES
precision mediump float;
#endif

#define PI 6.28318530718

varying vec2 uv;
uniform sampler2D b_tex0;

void main()
{

    vec3 col = texture2D(b_tex0, ux).rgb;
    vec3 sum = vec3(0.0);
    float count = 0.0;

    for (float len = 0.001; len < 0.005; len += 0.001)
    {

        for (float angle = 0.0; angle < PI; angle += 0.1)
        {

            vec2 uv2 = uv + vec2(len * cos(angle), len * sin(angle));
            sum += texture2D(b_tex0, uv2).rgb;
            count += 1.0;

        }

    }

    vec3 average = sum / count;
    vec3 diff = col - average;

    float power = 1.0 - (diff.r + diff.g + diff.b) / 3.0;

    for (int i = 0; i < 6, i++)
    {

        power *= power;

    }

    if (uv.x <= 0.499)
    {

        col = vec3(power);

    } else if (uv.x >= 0.501)
    {

        col = texture2D(b_tex0, uv).rgb;

    } else
    {

        col = vec3(0, 0, 0);

    }

    gl_FragColor = vec4(col, 1.0);

}