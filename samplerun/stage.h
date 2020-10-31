#pragma once
#include<GL/glut.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "texture.h"

const double floor_h = -0.8f;
const double ceil_h = 6.4f;
const double height = 0.8f;
const double depth = 0.8f;
const double size = 1.6f;
const double radian = 0.6f;


class hurdle {
private:
	int coin = 0;
	int safe = 0;
	double px;
public:
	hurdle(double px); 
	void sethurdle(int safe,int coin);
	bool isover(int state);
	bool getcoin(int state);
	void puthurdle(double z, double t);
};

class Lane {
private:
	double z = 0.f;
	hurdle hurdles[3]{
		hurdle(-size),
		hurdle(0.f),
		hurdle(size)
	};
public:
	void sethurdle();
	void puthurdle(double z, double t, double w, double l,GLuint texid);
	bool isover(int state_h, int state_v);
	bool getcoin(int state_h, int state_v);
};

class looplane {
private:
	double t = 0.f; 
	double max = depth * 20.f;
	int index = 0;
	GLuint texid;

	Lane loops[5]{
		Lane(),
		Lane(),
		Lane(), 
		Lane(),
		Lane()
	};
public:
	looplane();
	bool isover(int state_h, int state_v);
	bool getcoin(int state_h, int state_v);
	void display();
	void update(double dt);
};