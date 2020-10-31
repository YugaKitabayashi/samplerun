#include "stage.h"

hurdle::hurdle(double px) {
	this->px = px;
}

void hurdle::sethurdle(int safe,int coin) {
	this->safe = safe;
	this->coin = coin;
}

bool hurdle::isover(int state) {
	if ((state & safe) == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool hurdle::getcoin(int state) {
	if ((state & coin) != 0) {
		coin=0;
		return true;
	}
	else {
		return false;
	}
}

void hurdle::puthurdle(double d,double t){
	float diffuse[4] = { d, d, d, 1.f };
	float specular[4] = { d, d, d, 1.f };
	switch (this->safe)
	{
	case 1:
		glPushMatrix();
		glTranslated(this->px, height - size/2.f, -depth);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, d);
		glutSolidCube(size);
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glTranslated(this->px, height + size / 2.f, -depth);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, d);
		glutSolidCube(size);
		glPopMatrix();
		break;
	case 3:
		glPushMatrix();
		glTranslated(this->px, height - size / 2.f, -depth);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, d);
		glutSolidCube(size);
		glTranslated(0.f, size, 0.f);
		glutSolidCube(size);
		glPopMatrix();
		break;
	default:
		break;
	}

	d *= 4.f;
	diffuse[0] = d;diffuse[1] = d;diffuse[2] = 0.f;
	specular[0] = d;specular[1] = d;specular[2] = 0.f;

	switch (this->coin)
	{
	case 1:
		glPushMatrix();
		glTranslated(this->px, height - size / 2, -depth);
		glRotated(t * 180.f, 0.f, 1.f, 0.f);
		glScaled(radian, radian, radian);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, d);
		glutSolidOctahedron();
		glPopMatrix();
		break;
	case 2:
		glPushMatrix();
		glTranslated(this->px, height + size / 2, -depth);
		glRotated(t * 180.f, 0.f, 1.f, 0.f);
		glScaled(radian, radian, radian);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, d);
		glutSolidOctahedron();
		glPopMatrix();
		break;
	default:
		break;
	}  
}

void Lane::sethurdle() {
	srand((unsigned)time(NULL));
	int r = rand() % 62 + 1;
	int c = rand() % 6;
	for (int i = 0; i < 3; i++) {
		int safe = (r >> (i << 1)) & 3;
		int coin = (i == (c >> 1) && ((c & 1) + 1 & safe) == 0) ? (c & 1) + 1 : 0;
		hurdles[i].sethurdle(safe, coin);
	}
}

void Lane::puthurdle(double z,double t,double w,double l,GLuint texid){
	this->z = z;
	
	float diffuse[4] = { 0.3f, 0.3f, 0.3f, 1.f };
	float specular[4] = { 0.3f, 0.3f, 0.3f, 1.f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.2f);

	glPushMatrix();
	glTranslated(0, 0, z);
	glBindTexture(GL_TEXTURE_2D, texid);

	glNormal3d(0.f, 1.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 0.f);
	glVertex3d(w, floor_h, l);
	glTexCoord2f(3.f, 0.f);
	glVertex3d(-w, floor_h, l);
	glTexCoord2f(3.f,10.f);
	glVertex3d(-w, floor_h, -l);
	glTexCoord2f(0.f, 10.f);
	glVertex3d(w, floor_h, -l);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(w, floor_h, l);
	glTexCoord2f(4.f, 0.f);
	glVertex3d(w, ceil_h, l);
	glTexCoord2f(4.f, 10.f);
	glVertex3d(w, ceil_h, -l);
	glTexCoord2f(0.f, 10.f);
	glVertex3d(w, floor_h, -l);

	glTexCoord2f(0.f, 0.f);
	glVertex3d(-w, floor_h, l);
	glTexCoord2f(4.f, 0.f);
	glVertex3d(-w, ceil_h, l);
	glTexCoord2f(4.f, 10.f);
	glVertex3d(-w, ceil_h, -l);
	glTexCoord2f(0.f, 10.f);
	glVertex3d(-w, floor_h, -l);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	double d = exp(z / 16.f)*0.4f;
	for (int i = 0; i < 3; i++) {
		hurdles[i].puthurdle(d, t);
	}
	glPopMatrix();
}

bool Lane::isover(int state_h, int state_v) {
	if ( z < 0.2f) {
		return hurdles[state_h].isover(state_v);
	}
	else
	{
		return false;
	}
}

bool Lane::getcoin(int state_h, int state_v) {
	if (z < 0.2f) {
		return hurdles[state_h].getcoin(state_v);
	}
	else
	{
		return false;
	}
}

looplane::looplane() {
	this->texid = loadTexture("mosaic.bmp");
}

bool looplane::isover(int state_h, int state_v) {
	return loops[index].isover(state_h, state_v);
}

bool looplane::getcoin(int state_h, int state_v) {
	return loops[index].getcoin(state_h, state_v);
}

void looplane::display() {
	int i = index;
	double z = t* max;
	do {
		loops[i].puthurdle(z, t, size * 1.5f, max / 2,this->texid);
		z -= max;
		i = (++i) % 5;
	}while (i != index);
}

void looplane::update(double dt) {
	t += dt * 0.6f;
	if (t > 1.f) {
		loops[index].sethurdle();
		index = (++index) % 5;
		t -= 1.f;
	}
}