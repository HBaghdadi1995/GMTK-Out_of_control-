#pragma once
#include <glad/glad.h>
#include <assert.h>
#include <iostream>

#ifdef NDEBUG

#define GL_CALL(x) x;

#else

#define GL_CALL(x)\
    x;\
    {\
        bool isError = false;\
        GLenum err;\
        while ((err = glGetError()) != GL_NO_ERROR)\
        {\
            std::cerr << "Execution stopped because of OpenGL error: " << err << "\n"; \
            isError = true;\
        }\
    if(isError) __debugbreak();\
    }

#endif //NDEBUG
