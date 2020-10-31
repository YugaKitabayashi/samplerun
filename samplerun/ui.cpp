#include "ui.h"

void digit::print(int n, double px, double py) {
	glColor3d(0.5f,1.f, 0.5f);
	glBegin(GL_QUADS);
	switch (n)
	{
	case 0:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2, py + s * 3);
		glVertex2d(px + s * 2, py - s * 3);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 3);
		glVertex2d(px - s * 3, py - s * 3);
		glVertex2d(px - s * 2, py - s * 4);
		break;
	case 1:
		glVertex2d(px, py + s * 4);
		glVertex2d(px - s, py + s * 4);
		glVertex2d(px - s, py - s * 4);
		glVertex2d(px, py - s * 4);
		break;
	case 2:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2, py + s * 3);
		glVertex2d(px + s * 2, py + s);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 3);
		glVertex2d(px - s * 3, py + s * 2);
		glVertex2d(px - s * 2, py + s * 2);
		glVertex2d(px - s * 2, py);
		glVertex2d(px - s * 3, py - s);
		glVertex2d(px - s * 3, py - s * 4);
		glVertex2d(px - s * 2, py - s * 4);
		break;
	case 3:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2, py + s * 3);
		glVertex2d(px + s * 2, py + s);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 3);
		glVertex2d(px - s * 3, py + s * 2);
		glVertex2d(px - s * 2, py + s * 2);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 2, py - s * 3);
		glVertex2d(px + s * 2, py - s);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py - s * 4);
		glVertex2d(px - s * 3, py - s * 3);
		glVertex2d(px - s * 3, py - s * 2);
		glVertex2d(px - s * 2, py - s * 2);
		break;
	case 4:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px, py + s * 4);
		glVertex2d(px, py - s * 4);
		glVertex2d(px + s, py - s * 4);
		break;
	case 5:
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 4);
		glVertex2d(px - s * 3, py);
		glVertex2d(px - s * 2, py);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 2, py - s * 3);
		glVertex2d(px + s * 2, py - s);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py - s * 4);
		glVertex2d(px - s * 3, py - s * 3);
		glVertex2d(px - s * 3, py - s * 2);
		glVertex2d(px - s * 2, py - s * 2);
		break;
	case 6:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2, py + s * 3);
		glVertex2d(px + s * 2, py + s * 2);
		glVertex2d(px + s, py + s * 2);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 2, py - s * 3);
		glVertex2d(px + s * 2, py - s);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 3);
		glVertex2d(px - s * 3, py - s * 3);
		glVertex2d(px - s * 2, py - s * 4);
		break;
	case 7:
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 4);
		glVertex2d(px - s * 3, py + s * 2);
		glVertex2d(px - s * 2, py + s * 2);
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2, py + s * 4);
		glVertex2d(px, py - s * 4);
		glVertex2d(px - s, py - s * 4);
		break;
	case 8:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2, py + s * 3);
		glVertex2d(px + s * 2, py + s);
		glVertex2d(px + s, py);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 2, py - s * 3);
		glVertex2d(px + s * 2, py - s);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 3);
		glVertex2d(px - s * 3, py + s);
		glVertex2d(px - s * 2, py);
		glVertex2d(px - s * 2, py - s * 4);
		glVertex2d(px - s * 3, py - s * 3);
		glVertex2d(px - s * 3, py - s);
		glVertex2d(px - s * 2, py);
		break;
	case 9:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2, py + s * 3);
		glVertex2d(px + s * 2, py - s * 3);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 3);
		glVertex2d(px - s * 3, py + s);
		glVertex2d(px - s * 2, py);
		glVertex2d(px - s * 2, py - s * 4);
		glVertex2d(px - s * 3, py - s * 3);
		glVertex2d(px - s * 3, py - s * 2);
		glVertex2d(px - s * 2, py - s * 2);
	default:break;
	}
	glEnd();
	glBegin(GL_LINES);
	switch (n) {
	case 0:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px - s * 2, py - s * 4);
		break;
	case 2:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py);
		glVertex2d(px + s * 2, py - s * 4);
		glVertex2d(px - s * 3, py - s * 4);
		break;
	case 3:
	case 6:
	case 8:
	case 9:
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px - s * 2, py + s * 4);
		glVertex2d(px + s, py);
		glVertex2d(px - s * 2, py);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px - s * 2, py - s * 4);
		break;
	case 4:
		glVertex2d(px, py + s * 4);
		glVertex2d(px - s * 3, py - s * 2);
		glVertex2d(px + s * 2, py - s * 2);
		glVertex2d(px - s * 3, py - s * 2);
		break;
	case 5:
		glVertex2d(px + s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 4);
		glVertex2d(px + s , py);
		glVertex2d(px - s * 3, py);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px - s * 2, py - s * 4);
		break;
	case 7:
		glVertex2d(px + s * 2, py + s * 4);
		glVertex2d(px - s * 3, py + s * 4);
	}
	glEnd();
}

digit::digit(double s) {
	this->s = s;
}

void number::print(long score) {
	for (int i = 0; i < 16; i++) {
		digits[i].print(score % 10, 0.11f * (8.f - (double)i), 0.8f);
		score /= 10;
	}
}

void number::printresult(long score) {
	int l = 0;
	long t = 1;
	while (t < score) {
		t *= 10;
		l++;
	}
	double len = (double)l / 2.f;
	for (int i = 0; i < l; i++) {
		digits[i].print(score % 10, 0.11f * (len - (double)i), -0.2f);
		score /= 10;
	}
}

void message::printcharacter(char character,double px, double py, double s) {
	glBegin(GL_QUADS);
	switch (character) {
	case 'A':
		glVertex2d(px + s * 2, py + s * 4);
		glVertex2d(px + s * 3, py + s * 4);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px, py - s * 4);
		break;
	case 'C':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px, py + s * 3);
		glVertex2d(px, py - s * 3);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 5, py + s * 3);
		glVertex2d(px + s * 5, py + s * 2);
		glVertex2d(px + s * 4, py + s * 2);
		glVertex2d(px + s * 4, py - s * 4);
		glVertex2d(px + s * 5, py - s * 3);
		glVertex2d(px + s * 5, py - s * 2);
		glVertex2d(px + s * 4, py - s * 2); 
		break;
	case 'G':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px, py + s * 3);
		glVertex2d(px, py - s * 3);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 5, py + s * 3);
		glVertex2d(px + s * 5, py + s * 2);
		glVertex2d(px + s * 4, py + s * 2);
		glVertex2d(px + s * 4, py - s * 4);
		glVertex2d(px + s * 5, py - s * 3);
		glVertex2d(px + s * 5, py);
		glVertex2d(px + s * 4, py);
		break;
	case 'M':
	case 'N':
		glVertex2d(px, py + s * 4);
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px, py - s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 5, py + s * 4);
		glVertex2d(px + s * 5, py - s * 4);
		glVertex2d(px + s * 4, py - s * 4);
		break;
	case 'O':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px, py + s * 3);
		glVertex2d(px, py - s * 3);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 5, py + s * 3);
		glVertex2d(px + s * 5, py - s * 3);
		glVertex2d(px + s * 4, py - s * 4); 
		break;
	case 'R':
		glVertex2d(px + s * 3, py);
		glVertex2d(px + s * 4, py);
		glVertex2d(px + s * 5, py - s * 4);
		glVertex2d(px + s * 4, py - s * 4); 
	case 'P':
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 5, py + s * 3);
		glVertex2d(px + s * 5, py + s);
		glVertex2d(px + s * 4, py);
	case 'E':
	case 'L':
		glVertex2d(px, py + s * 4);
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px, py - s * 4); 
		break;
	case 'S':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px, py + s * 3);
		glVertex2d(px, py + s);
		glVertex2d(px + s, py);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px, py - s * 3);
		glVertex2d(px, py - s * 2);
		glVertex2d(px + s, py - s * 2);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 5, py + s * 3);
		glVertex2d(px + s * 5, py + s * 2);
		glVertex2d(px + s * 4, py + s * 2);
		glVertex2d(px + s * 4, py);
		glVertex2d(px + s * 5, py - s);
		glVertex2d(px + s * 5, py - s * 3);
		glVertex2d(px + s * 4, py - s * 4); 
		break;
	case 'T':
		glVertex2d(px + s * 2, py + s * 4);
		glVertex2d(px + s * 3, py + s * 4);
		glVertex2d(px + s * 3, py - s * 4);
		glVertex2d(px + s * 2, py - s * 4); 
		break;
	case 'U':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px, py + s * 4);
		glVertex2d(px, py - s * 3);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 5, py + s * 4);
		glVertex2d(px + s * 5, py - s * 3);
		glVertex2d(px + s * 4, py - s * 4); 
		break;
	case 'V':
		glVertex2d(px, py + s * 4);
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 3, py - s * 4);
		glVertex2d(px + s * 2, py - s * 4); 
		break;
	}
	glEnd();
	glBegin(GL_LINES);
	switch (character) {
	case 'A':
		glVertex2d(px + s * 3, py + s * 4);
		glVertex2d(px + s * 5, py - s * 4);
		glVertex2d(px + s * 2, py);
		glVertex2d(px + s * 4, py); 
		break;
	case 'E':
		glVertex2d(px, py);
		glVertex2d(px + s * 5, py);
		glVertex2d(px, py - s * 4);
		glVertex2d(px + s * 5, py - s * 4);
	case 'T':
		glVertex2d(px, py + s * 4);
		glVertex2d(px + s * 5, py + s * 4);
		break;
	case 'G':
		glVertex2d(px + s * 3, py);
		glVertex2d(px + s * 5, py); 
	case 'C':
	case 'O':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 4, py - s * 4);
		break;
	case 'L':
		glVertex2d(px, py - s * 4);
		glVertex2d(px + s * 5, py - s * 4); 
		break;
	case 'M':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 2.5f, py);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s * 2.5f, py); 
		break;
	case 'N':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 4, py - s * 4); 
		break;
	case 'P':
	case 'R':
		glVertex2d(px  , py + s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s, py);
		glVertex2d(px + s * 4, py); 
		break;
	case 'S':
		glVertex2d(px + s, py + s * 4);
		glVertex2d(px + s * 4, py + s * 4);
		glVertex2d(px + s, py);
		glVertex2d(px + s * 4, py);
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 4, py - s * 4);
		break;
	case 'U':
		glVertex2d(px + s, py - s * 4);
		glVertex2d(px + s * 4, py - s * 4); 
		break;
	case 'V':
		glVertex2d(px + s * 5, py + s * 4);
		glVertex2d(px + s * 3, py - s * 4); 
		break;
	}
	glEnd();
}

void message::printtips() {
	glColor3d(0.5f, 1.f, 1.f);
	double s = 0.015, py = -0.6;
	printcharacter('P', -s * 52, py, s);
	printcharacter('R', -s * 46, py, s);
	printcharacter('E', -s * 40, py, s);
	printcharacter('S', -s * 34, py, s);
	printcharacter('S', -s * 28, py, s);

	printcharacter('S', -s * 20, py, s);
	printcharacter('P', -s * 14, py, s);
	printcharacter('A', -s * 9, py, s);
	printcharacter('C', -s * 3, py, s);
	printcharacter('E', s * 3, py, s);

	printcharacter('T', s * 10, py, s);
	printcharacter('O', s * 16, py, s);

	printcharacter('S', s * 24, py, s);
	printcharacter('T', s * 30, py, s);
	printcharacter('A', s * 35, py, s);
	printcharacter('R', s * 41, py, s);
	printcharacter('T', s * 47, py, s);
}

void message::printtitle() {
	glColor3d(0.5f, 1.f, 0.5f);
	double s = 0.03, py = 0.1f;
	printcharacter('S', -s * 27, py, s);
	printcharacter('A', -s * 21, py, s);
	printcharacter('M', -s * 15, py, s);
	printcharacter('P', -s * 9, py, s);
	printcharacter('L', -s * 3, py, s);
	printcharacter('E', s * 3, py, s);

	printcharacter('R', s * 10, py, s);
	printcharacter('U', s * 16, py, s);
	printcharacter('N', s * 22, py, s);

}

void message::printgameover() {
	glColor3d(0.5f, 0.f, 0.f);
	double s = 0.03, py = 0.1f;
	printcharacter('G', -s * 24, py, s);
	printcharacter('A', -s * 18, py, s);
	printcharacter('M', -s * 12, py, s);
	printcharacter('E', -s * 6, py, s);

	printcharacter('O', s, py, s);
	printcharacter('V', s * 7, py, s);
	printcharacter('E', s * 13, py, s);
	printcharacter('R', s * 19, py, s);
}