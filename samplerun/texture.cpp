#include "texture.h"

GLuint loadTexture(const char* filename)
{
	GLuint texID;
	GLubyte* texture_image;
	int texture_width, texture_height;
	texture_image = loadBMPFile(filename, &texture_width, &texture_height);
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_width, texture_height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image);
	delete[] texture_image;
	return texID;
}

unsigned char* loadBMPFile(const char* filename, int* width, int* height)
{
	const int HEADERSIZE = 54;
	int i, j;
	int real_width;
	unsigned int color;
	FILE* fp;
	unsigned char header_buf[HEADERSIZE];
	unsigned char* tmp;
	unsigned char* pixel;
	errno_t err = fopen_s(&fp, filename, "rb");
	if (err != 0) {
		fprintf(stderr, "Cannot open file [ %s ].\n", filename);
		exit(-1);
	}

	fread(header_buf, sizeof(unsigned char), HEADERSIZE, fp);

	if (strncmp((char*)header_buf, "BM", 2)) {
		fprintf(stderr, "Error : [ %s ] is not bitmap file.\n", filename);
		exit(-1);
	}
	memcpy(width, header_buf + 18, sizeof(int));
	memcpy(height, header_buf + 22, sizeof(int));
	memcpy(&color, header_buf + 28, sizeof(unsigned int));

	if (color != 24) {
		fprintf(stderr, "Error : [ %s ] is not 24bit color image.\n", filename);
		exit(-1);
	}

	if (*height < 0) {
		*height *= -1;
		real_width = *width * 3 + *width % 4;
		tmp = new unsigned char[real_width];
		pixel = new unsigned char[3 * (*width) * (*height)];

		for (i = 0; i < *height; i++) {
			fread(tmp, 1, real_width, fp);
			for (j = 0; j < *width; j++) {
				pixel[3 * ((*height - i - 1) * (*width) + j)] = tmp[3 * j + 2];
				pixel[3 * ((*height - i - 1) * (*width) + j) + 1] = tmp[3 * j + 1];
				pixel[3 * ((*height - i - 1) * (*width) + j) + 2] = tmp[3 * j];
			}
		}
	}
	else {
		real_width = *width * 3 + *width % 4;
		tmp = new unsigned char[real_width];
		pixel = new unsigned char[3 * (*width) * (*height)];

		for (i = 0; i < *height; i++) {
			fread(tmp, 1, real_width, fp);
			for (j = 0; j < *width; j++) {
				pixel[3 * (i * (*width) + j)] = tmp[3 * j + 2];
				pixel[3 * (i * (*width) + j) + 1] = tmp[3 * j + 1];
				pixel[3 * (i * (*width) + j) + 2] = tmp[3 * j];
			}
		}
	}
	delete[] tmp;
	return pixel;
}