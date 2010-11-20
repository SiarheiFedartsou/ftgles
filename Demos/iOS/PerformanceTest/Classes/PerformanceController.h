/*
 
 Copyright (c) 2010 David Petrie david@davidpetrie.com
 
 This software is provided 'as-is', without any express or implied warranty.
 In no event will the authors be held liable for any damages arising from the 
 use of this software. Permission is granted to anyone to use this software for
 any purpose, including commercial applications, and to alter it and 
 redistribute it freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not claim 
 that you wrote the original software. If you use this software in a product, an 
 acknowledgment in the product documentation would be appreciated but is not 
 required.
 2. Altered source versions must be plainly marked as such, and must not be 
 misrepresented as being the original software.
 3. This notice may not be removed or altered from any source distribution.
 
 */

#ifndef PERFORMANCE_CONTROLLER_H
#define PERFORMANCE_CONTROLLER_H

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include "FTGL/ftgles.h"


/**
 * Goal: full screen of 10pt characters at 30+ fps
 */

class PerformanceController
{		
public:
	PerformanceController(const char* path, float width, float height, float scale);
	
	~PerformanceController();
	
	void Draw();
	
	void DrawNonLayoutText(const float shade, const float yLoc);
};

#endif