#include <stdio.h>
#include "../headers/readByLine.h"
int main(int argc, char const *argv[])
{
	char cline_content[32] = {0};
	readByLine(argv[1], cline_content, argv[2]);
	printf("%s\n", cline_content);
	return 0;
}
