//
//  Shader.vsh
//  OpenGLTest3
//
//  Created by David Petrie on 18/05/10.
//  Copyright n/a 2010. All rights reserved.
//

attribute vec4 position;
attribute vec4 color;
attribute vec2 texCoord;
varying vec2 texture_coordinate;
varying lowp vec4 colorVarying;

uniform mat4 camera;

void main()
{
	gl_Position = (camera * position);
    colorVarying = color;
    texture_coordinate = texCoord;
}
