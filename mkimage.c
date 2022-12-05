https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 8
#define NUM_PIXELS 64

int main() {
	FILE *fp;
	int num_images = 1;

	unsigned char label = 2;

	unsigned char pixels[WIDTH][WIDTH] = {
		{0,   0,   0,   0,   0,   0,   0,   0},
		{0,   0, 255, 255, 255, 255, 255,   0},
		{0,   0,   0,   0,   0,   0, 255,   0}, 
		{0,   0, 255, 255, 255, 255, 255,   0},
		{0,   0, 255,   0,   0,   0,   0,   0}, 
		{0,   0, 255, 255, 255, 255, 255,   0},
		{0,   0,   0,   0,   0,   0,   0,   0}};

	if((fp = fopen("number2", "wb")) == NULL) {
		perror("fopen");
		exit(1);
	}

	fwrite(&num_images, sizeof(int), 1, fp);
	fwrite(&label, sizeof(char), 1, fp);
	fwrite(pixels,sizeof(unsigned char), NUM_PIXELS, fp);

	fclose(fp);
	return 0;
}
