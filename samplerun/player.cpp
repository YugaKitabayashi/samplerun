#include "player.h"

joint::joint(int sum, int trapezoid, int animation, double px, double py, double pz) {
		this->sum = sum;
		this->position[0] = px; this->position[1] = py; this->position[2] = pz;
		this->trapezoid = trapezoid;
		this->animation = animation;
	}

trapezoid::trapezoid(double top, double bottom, double top_w, double top_h, double bottom_w, double bottom_h) {
		this->top[0] = top_w / 2;
		this->top[1] = top;
		this->top[2] = top_h / 2;
		this->bottom[0] = bottom_w / 2;
		this->bottom[1] = bottom;
		this->bottom[2] = bottom_h / 2;
		double n0 = top - bottom;
		double n1 = bottom_w - top_w;
		double r = sqrt(n0 * n0 + n1 * n1);
		normal[0] = n0 / r;
		normal[1] = n1 / r;
		n1 = bottom_h - top_h;
		r = sqrt(n0 * n0 + n1 * n1);
		normal[2] = n0 / r;
		normal[3] = n1 / r;
	}

void trapezoid::puttrapezoid() {
		glNormal3d(0.f, 1.f, 0.f);
		glBegin(GL_QUADS);
		glVertex3d(top[0], top[1], top[2]);
		glVertex3d(top[0], top[1], -top[2]);
		glVertex3d(-top[0], top[1], -top[2]);
		glVertex3d(-top[0], top[1], top[2]);
		glEnd();
		glNormal3d(0.f, -1.f, 0.f);
		glBegin(GL_QUADS);
		glVertex3d(bottom[0], bottom[1], bottom[2]);
		glVertex3d(bottom[0], bottom[1], -bottom[2]);
		glVertex3d(-bottom[0], bottom[1], -bottom[2]);
		glVertex3d(-bottom[0], bottom[1], bottom[2]);
		glEnd();
		glNormal3d(normal[0], normal[1], 0.f);
		glBegin(GL_QUADS);
		glVertex3d(top[0], top[1], top[2]);
		glVertex3d(top[0], top[1], -top[2]);
		glVertex3d(bottom[0], bottom[1], -bottom[2]);
		glVertex3d(bottom[0], bottom[1], bottom[2]);
		glEnd();
		glNormal3d(-normal[0], normal[1], 0.f);
		glBegin(GL_QUADS);
		glVertex3d(-top[0], top[1], -top[2]);
		glVertex3d(-top[0], top[1], top[2]);
		glVertex3d(-bottom[0], bottom[1], bottom[2]);
		glVertex3d(-bottom[0], bottom[1], -bottom[2]);
		glEnd();
		glNormal3d(0.f, normal[3], -normal[2]);
		glBegin(GL_QUADS);
		glVertex3d(top[0], top[1], -top[2]);
		glVertex3d(-top[0], top[1], -top[2]);
		glVertex3d(-bottom[0], bottom[1], -bottom[2]);
		glVertex3d(bottom[0], bottom[1], -bottom[2]);
		glEnd();
		glNormal3d(0.f, normal[3], normal[2]);
		glBegin(GL_QUADS);
		glVertex3d(-top[0], top[1], top[2]);
		glVertex3d(top[0], top[1], top[2]);
		glVertex3d(bottom[0], bottom[1], bottom[2]);
		glVertex3d(-bottom[0], bottom[1], bottom[2]);
		glEnd();
	}

animation::animation(double t0, double t1, double t2, double t3) {
		this->v[0] = t0;
		this->v[1] = t1;
		this->v[2] = t2;
		this->v[3] = t3;
	}

double animation::run(double  t) {
	t *= 4;
	if (t > 3) {
		t -= 3.f;
		return run(v[2], v[3], v[0], v[1], t);
	}
	else if (t > 2) {
		t -= 2.f;
		return run(v[1], v[2], v[3], v[0], t);
	}
	else if (t > 1) {
		t -= 1.f;
		return run(v[0], v[1], v[2], v[3], t);
	}
	else if (t > 0) {
		return run(v[3], v[0], v[1], v[2], t);
	}
	else {
		return 0;
	}
}

double animation::motion(double t,double state,double s){
		return (1 - s) * run(t) + s * state;
	}

double animation::run(double v0, double v1, double v2, double v3, double t) {
		double a = (v0 - v1) * 1.5 - (v2 - v3) * 0.5;
		v3 = -v0 * 2.5 + v1 * 2 + v2 - v3 * 0.5;
		v1 = (v1 - v2) * 0.5;
		return ((((a * t) + v3) * t + v1) * t) + v0;
	}

void Player::display() {
	float diffuse[4] = { 0.4f, 0.4f, 0.4f, 1.f };
	float specular[4] = { 0.4f, 0.4f, 0.4f, 1.f };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.5f);
	if (state_v == 3) {
		glPushMatrix();
		glTranslated(h * 1.6f, 0, 0);
		move(0);
		glPopMatrix();
	}
	else {
		double s_ = 4 * s * (1 - s);
		glPushMatrix();
		glTranslated(h * 1.6f, s_ *(0.8f - 1.6f * (double)state_vi), 0);
		move(0, s_);
		glPopMatrix();
	}
}

void Player::move(int index) {
		glPushMatrix();
		glTranslated(body[index].position[0], body[index].position[1], body[index].position[2]);
		if (body[index].animation != -1) {
			glRotated(anims[body[index].animation].run(t), 1.f, 0, 0);
		}
		if (body[index].trapezoid != -1)parts[body[index].trapezoid].puttrapezoid();
		if (index == 0) {
			for (int i = 1; i < body[0].sum; i++) {
				move(i);
			}
		}
		else {
			for (int i = body[index - 1].sum; i < body[index].sum; i++) {
				move(i);
			}
		}
		glPopMatrix();
	}

void Player::move(int index, double s) {
	glPushMatrix();
	glTranslated(body[index].position[0], body[index].position[1], body[index].position[2]);
	if (body[index].animation != -1) {
		glRotated(anims[body[index].animation].motion(t, motionx[state_vi][body[index].animation], s), 1.f, 0, 0);
		glRotated(motionz[state_vi][body[index].animation] * s, 0, 0, 1.f);
	}
	if (body[index].trapezoid != -1)parts[body[index].trapezoid].puttrapezoid();
	if (index == 0) {
		for (int i = 1; i < body[0].sum; i++) {
			move(i,s);
		}
	}
	else {
		for (int i = body[index - 1].sum; i < body[index].sum; i++) {
			move(i,s);
		}
	}
	glPopMatrix();
}

void Player::update(double dt) {
	t = t > 1.f ? t - 1.f : t + dt * 2.f;
	if (state_v != 3) {
		s += dt;
	}
	if (s > 1) {
		s = 0;
		state_v = 3;
		state_vi = -1;
	}
	switch (state_hi)
	{
	case 0:
		if (h > -1.f) {
			h -= dt * 4.8f;
			if(h < -0.3f)state_h = 0;
		}
		else {
			h = -1.f;
		}
		break;
	case 2:
		if (h < 1.f) {
			h += dt * 4.8f;
			if (h > 0.3f) {
				state_h = 2;
			}
		}
		else {
			h = 1.f;
		}
		break;
	default:
		if (h < -0.01f) {
			h += dt * 4.8f;
			if (h > -0.7f)state_h = 1;
		}
		else if (h > 0.01f) {
			h -= dt * 4.8f;
			if(h < 0.7f) state_h = 1;
		}
		else h = 0.f;
		break;
	}
}