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

int main(int argc, char **argv) {

	FILE *fp;
	if((fp = fopen(argv[1], "r")) == NULL) {
		perror("fopen");
		exit(1);
	}

	int num;
	if(fread(&num, sizeof(int), 1, fp) == 0) {
		if(feof(fp)) {
			fprintf(stderr, "End of file\n");
		} else {
			perror("fread");
		}
		exit(1);
	}

	char *str;
	str = malloc(sizeof(char) * 1024);
	if(str == NULL) {
		perror("malloc");
	}

	return 0;
}
