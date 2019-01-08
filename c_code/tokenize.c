#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char string[] = "the quick brown fox jumped over the lazy dog";
	char* word = strtok(string, " ");
	char *result;
	while(word)
	{
		result = strncat(word, "\n",2);
		//printf("%s ", word);
		word = strtok(NULL, " ");
	}
	printf("%s", result);
	exit(0);
}