// written by muon @ 2020/08/29
// prectice elementry c language and english by write a simple poem :)
//
// triangle stars
//
	// each 1 stars are needs 2 spaces
	//
	// the buffer size is following this formula :
	// spaces = n(n-1)/2
	// stars (with spaces) = n(n+1)
	// control character = n+1
	//
	//    *		5
	//   * *	6
	//  * * *	7
	// * * * *	8
	// full size of triangle = 4*3/2 + 4*5 + 5 = 31

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SEP 10

// put star to buffer
void star(char** point);
// put space to buffer
void space(char** point);
// print seperator
void seperate(int size);

int main(int argc, char** argv){
	int lines, size;
	char *buffer, *niddle;

	// initialize variables
	lines = 0;
	size = 0;
	buffer = NULL;
	niddle = NULL;
	
	
	// keyboard input or commend argument
	if(argc==1){
		printf("\nplease input stars rows : ");
		fflush(stdout);
		scanf("%d", &lines);
	} else {
		lines = atoi(*(argv+1));
	}

	// initialize message
	seperate(SEP);

	// determine buffer size plus null character
	size = lines*(lines-1)/2 + lines*(lines+1) + lines+1;
	// actually char type is usually 1byte so useless code
	size = size*sizeof(char);

	buffer = (char*)malloc(size);
	// pointer test
	printf("%p\n", buffer);

	// allocation buffer
	if(buffer==NULL){
		fprintf(stderr, "leck of memory\n");
		return -1;
	}

	// initialize buffer
	//for(int i=0; i<size; i++)
	//	*(buffer+i) = 0;

	// triangle logic
	niddle = buffer;

	for(int i=0; i<lines; i++){
		// '   ' + ' *' + '\n'
		for(int j=1; j<lines-i; j++)
			space(&niddle);
		for(int j=0; j<=i; j++)
			star(&niddle);

		*niddle++ = '\n';
	}

	// put null charactor for c string
	*niddle = '\0';
	niddle = NULL;
	
	// print triangle
	puts(buffer);

	seperate(SEP);
	printf("%d\n", size);
	fflush(stdout);
	free(buffer);
	buffer = NULL;

	return 0;
}


void star(char** point){
	*(*point)++ = ' ';
	*(*point)++ = '*';
}

void space(char** point){
	*(*point)++ = ' ';
}

void seperate(int size){
	for(int i=0; i<size; i++)
		putc('-', stdout);
	putc('\n', stdout);
}
