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
        GLenum err;\
        while ((err = glGetError()) != GL_NO_ERROR)\
        {\
            std::cerr << "Execution stopped because of OpenGL error: " << err; \
            assert(false);\
        }\
    }

#endif //NDEBUG
