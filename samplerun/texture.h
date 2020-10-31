#pragma once
#include <GL/glut.h>
#include <iostream>

GLuint loadTexture(const char* filename);

unsigned char* loadBMPFile(const char* filename, int* width, int* height);