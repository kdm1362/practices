#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int flag;
	char *point;
	while(1){
		printf("input dynamic memory size (byte) : ");
		fflush(stdout);
		scanf("%d", &flag);

		if(flag<=0)
			break;

		point = (char*)malloc(flag);
		printf("\n%p assigned %dbyte\n", point, flag);
		fflush(stdout);

		free(point);
		printf("free success\n\n");

	}

	return 0;
}
