#ifdef GL_ES
precision mediump float;
#endif
#version 410 core

void main()
{
    gl_Position=vec4(0.,0.,0.,1.);
    gl_FragColor=vec4(1.,.3,.7,.4);
}