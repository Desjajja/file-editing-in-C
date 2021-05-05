#include <stdio.h>
#include <stdlib.h>
#include "../headers/readByLine.h"
#include "../headers/writeByLine.h"

int main(int argc, char const *argv[])
{
	char * iread = NULL;
	char * iwrite = NULL;
	char cread, cwrite, ch, option;
	char cline_content[32] = {0};
	char buf_restore[MAX_ROW][32];
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
	writeByLine(argv[1], cline_content, iwrite, buf_restore, 0);
	// writeByLine("test.txt", cline_content, iwrite);
	printf("\nUndo:Yes(y)/No(n)");
	scanf("%d", &option);
	ch = getchar();
	if(option == "Y" | option == "y")
	{
		writeByLine(argv[1], cline_content, iwrite, buf_restore, 1);	
	}
	return 0;
}
