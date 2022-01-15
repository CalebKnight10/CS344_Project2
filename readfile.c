#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	if(argc !=2)
	{
		perror("Error: ");
	}
	char *file = argv[1];
	char buf[2048];

	int fileDescriptor = open(file, O_RDONLY);
	size_t ct = read(fileDescriptor, buf, 2048);
	write(1, buf, ct);
	close(fileDescriptor);
}