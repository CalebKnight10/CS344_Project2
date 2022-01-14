#include <stdio.h>


int main(int argc, char *argv[])
{
	printf("0: %s\n", argv[0]);
	for(int i = 1; i < argc; i ++) 
	{
		printf("%d: %s\n", i, argv[i]);
	}
}