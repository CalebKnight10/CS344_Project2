#include <stdio.h> //basic library
#include <unistd.h> //size_t
#include <fcntl.h> //O_RDONLY
#include <ctype.h> //touppper

#include <stdlib.h>

void use_command_line();
void use_files(int num_of_files, char *argv[]);

int main(int argc, char *argv[])
{
	int num_of_files = argc - 1;

	if(num_of_files == 0)
	{
		use_command_line();
	} else 
	{
		use_files(num_of_files, argv);
	}
}
void use_command_line() 
{
	char buf[2048];
	size_t ct = read(0, buf, 2048);
	for(int i = 0; i < (int) sizeof(buf); i++)
	{
		buf[i] = toupper(buf[i]);
	}
	write(1, buf, ct);
}

void use_files(int num_of_files, char *argv[])
{
	char *file;
	int file_descriptor;
	char buf[2048];
	size_t ct;

	for(int i = 0; i < num_of_files; i++)
	{
		file = argv[i + 1];
		file_descriptor = open(file, O_RDONLY);
		if(file_descriptor == -1)
		{
			perror("Error: ");
		}
		ct = read(file_descriptor, buf, 2048);
		for(int i = 0; i < (int) sizeof(buf); i++)
		{
			buf[i] = toupper(buf[i]);

		}
		write(1, buf, ct);
		close(file_descriptor);
	}
}