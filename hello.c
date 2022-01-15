#include <stdio.h>


int main() 
{
	int x = 12;
	float y = 3.14;
	char* s = "Hello, World!";

	printf("x is %d, y is %f\n", x, y);
	printf("%s\n", s);

	for(int i = 0; i < 5; i++) 
	{
		printf("%d x %d = %d\n", i, 5, i*5);
	}
}