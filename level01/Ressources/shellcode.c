#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char **envp)
{
	char* ptr = getenv("SHELLCODE");
	printf("%p\n", ptr);
}
