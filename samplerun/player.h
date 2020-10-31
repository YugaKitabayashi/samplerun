#pragma once
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<time.h>

class joint {
public:
	int sum;
	int trapezoid;
	int animation;
	double position[3];
	joint(int sum, int trapezoid, int animation, double px, double py, double pz);
};

class trapezoid {
private:
	double normal[4];
	double top[3];
	double bottom[3];
public:
	trapezoid(double top, double bottom, double top_w, double top_h, double bottom_w, double bottom_h);
	void puttrapezoid();
};

class animation {
private:
	double v[4];
public:
	animation(double t0, double t1, double t2, double t3);
	double run(double t);
	double motion(double t,double state, double s);
	double run(double v0, double v1, double v2, double v3, double t);
};

class Player {
private:
	void move(int index);
	void move(int index, double s);
	joint body[20]{
		joint(4,0,0, 0.0, 1.0, 0.0),
		joint(5,1,1, -0.1, 0.0, 0.0),
		joint(6,1,2, 0.1, 0.0, 0.0),
		joint(7,2, -1,0.0, 0.4, 0.0),
		joint(8,3, 3, 0.0, -0.6, 0.0),
		joint(9,3, 4, 0.0, -0.6, 0.0),
		joint(12,4,11, 0.0, 0.4, 0.0),
		joint(13,5, 5,0.0, -0.6, 0.0),
		joint(14,5,6, 0.0, -0.6, 0.0),
		joint(15,6,7, -0.3, 0.0, 0.0),
		joint(16,6,8, 0.3, 0.0, 0.0),
		joint(16,-1,-1, 0.0, 0.2, 0.0),
		joint(16,-1,-1, 0.0, -0.3, 0.0),
		joint(16,-1,-1, 0.0, -0.3, 0.0),
		joint(17,7,9, 0.0, -0.4, 0.0),
		joint(18,7,10, 0.0, -0.4, 0.0),
		joint(19,8,-1, 0.0, -0.4, 0.0),
		joint(20,8,-1, 0.0, -0.4, 0.0),
		joint(20,-1,-1, 0.0, -0.2, 0.0),
		joint(20,-1,-1, 0.0, -0.2, 0.0)
	};

	trapezoid parts[9]{
		trapezoid(0.35,0.05,0.3,0.1,0.4,0.2),
		trapezoid(-0.05,-0.55,0.2,0.2,0.15,0.15),
		trapezoid(0.35,0.05,0.4,0.2,0.3,0.1),
		trapezoid(-0.05,-0.55,0.15,0.15,0.1,0.1),
		trapezoid(0.25,0.05,0.2,0.2,0.2,0.2),
		trapezoid(-0.05,-0.25,0.1,0.1,0.05,0.05),
		trapezoid(-0.05,-0.35,0.15,0.15,0.1,0.1),
		trapezoid(-0.05,-0.3,0.1,0.1,0.05,0.05),
		trapezoid(0.1,-0.1,0.05,0.1,0.05,0.1)
	};

	animation anims[12]{
		animation(0.f,-15.f,0.1f,-15.f),
		animation(30.f,-30.f,30.f,90.f),
		animation(30.f,90.f,30.f,-30.f),
		animation(-15.f,-15.f,-120.f,-90.f),
		animation(-120.f,-90.f,-15.f,-15.f),
		animation(90.f,90.f,60.f,60.f),
		animation(60.f,60.f,90.f,90.f),
		animation(0.f,45.f,-15.f,-75.f),
		animation(-15.f,-75.f,0.f,45.f),
		animation(30.f,90.f,30.f,90.f),
		animation(30.f,90.f,30.f,90.f),
		animation(0.f,-15.f,0.1f,-15.f)
	};

	double motionx[2][12]{
		{0.f,90.f,90.f,-150.f,-150.f,90.f,90.f,180.f,180.f,120.f,120.f,-45.f},
		{90.f,0.f,15.f,-165.f,-15.f,15.f,15.f,0.f,0.f,15.f,15.f,-30.f},
	};
	double motionz[2][12]{
		{0.f,0.f,0.f,0.f,0.f,0.f,0.f,-15.f,15.f,0.f,0.f,0.f},
		{0.f,-45.f,15.f,0.f,0.f,0.f,0.f,-180.f,180.f,0.f,0.f,0.f},
	};

public:
	int state_v = 3;
	int state_vi = -1;
	int state_h = 1;
	int state_hi = 1;
	double t = 0.f;
	double s = 0.f;
	double h = 0.f;
	void display();
	void update(double dt);
};