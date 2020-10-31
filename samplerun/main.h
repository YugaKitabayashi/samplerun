#pragma once
#include "player.h"
#include "stage.h"
#include "ui.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glut.h>
#include <time.h>

const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 512;

Player player;
looplane lane;
number num;
message msg;
int scene = 0;
long score;
clock_t u,t = clock();
double dt;

#pragma once

void setCamera(void);

void setLight(void);

void display(void);

void update(void);

void keyboard(unsigned char key, int x, int y);

void keyboardup(unsigned char key, int x, int y);
