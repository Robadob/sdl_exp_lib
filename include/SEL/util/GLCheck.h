#ifndef __GLcheck_h__
#define __GLcheck_h__

#include <glew.h>
#include <cstdio>
#include <cstdlib>
/**
 * This header is inspired by the commonly used CUDA error checking define
 * You can wrap any code in GL_CALL(<your code>) and it will automatically attach a GL error check when in debug mode
 * This outputs the error string, file and line number which the error was caught
 * By using it eveyrwhere, it should improve your ability to detect GL errors
 * GL_CHECK() can also be used if you require this error checking away from a GL call
 * 
 * If you define EXIT_ON_ERROR, the program will wait for user input and exit if this detects any error
 * By default this behaviour is disabled
 */

#ifdef _DEBUG //VS standard debug flag

inline static void HandleGLError(const char *file, int line) {
    GLuint error = glGetError();
    if (error != GL_NO_ERROR)
    {
		printf("%s(%i) GL Error Occurred;\n%s\n", file, line, reinterpret_cast<const char*>(gluErrorString(error)));
#if EXIT_ON_ERROR
        getchar();
		exit(EXIT_FAILURE);
#endif
    }
}

#define GL_CALL( err ) err ;HandleGLError(__FILE__, __LINE__)
#define GL_CHECK() (HandleGLError(__FILE__, __LINE__))

#else //ifdef _DEBUG
//Remove the checks when running release mode.
#define GL_CALL( err ) err
#define GL_CHECK() 

#endif //ifdef  _DEBUG

inline static void InitGlew() {
    //https://www.opengl.org/wiki/OpenGL_Loading_Library#GLEW_.28OpenGL_Extension_Wrangler.29
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stderr, "Error: %s\n", reinterpret_cast<const char*>(glewGetErrorString(err)));
        getchar();
		exit(EXIT_FAILURE);
    }
}
#define GLEW_INIT() (InitGlew())

#endif //ifndef __GLcheck_h__
