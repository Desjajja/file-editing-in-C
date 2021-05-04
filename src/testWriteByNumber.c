#include <stdio.h>
#include <stdlib.h>
#include "../headers/readByLine.h"
#include "../headers/writeByLine.h"

int main(int argc, char const *argv[])
{
	char * iread = NULL;
	char * iwrite = NULL;
	char cread, cwrite, ch;
	char cline_content[32] = {0};
	printf("choose one line to read from: ");
	scanf("%c", &cread);
	ch = getchar();
	iread = &cread;
	readByLine(argv[1], cline_content, iread);
	// readByLine("./test.txt", cline_content, iread);
	printf("\nThe line read is: %s\n", cline_content);

	printf("choose one line to write to: ");
	scanf("%c", &cwrite);
	ch = getchar();
	iwrite = &cwrite;
	writeByLine(argv[1], cline_content, iwrite);
	// writeByLine("test.txt", cline_content, iwrite);
	return 0;
}
