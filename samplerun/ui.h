#pragma once
#include<GL/glut.h>
#include<iostream>

class digit {
private:
	double s;
public:
	digit(double s);
	void print(int n, double px, double py);

};

class number {
private:
	digit digits[16]{
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02),
		digit(0.02)
	};
public:
	void print(long score);
	void printresult(long score);
};

class message {
private:
	void printcharacter(char character,double px, double py, double s);
public:
	void printtips();
	void printgameover();
	void printtitle();
};