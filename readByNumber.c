#include <stdio.h>
#include <stdlib.h>
#include "./readByLine.h"
int readByLine(const char * path, const char * line_num)
{
	// 1st arg: path to the file
	// 2nd arg: number of the target line

	//TODO: check arg types

	char c;
	int curLineNum = 0;
	//printf("argv[2]: %d\n", atoi(argv[2]));
	
	// printf("Input the line number to be printed: ");
	// char ctarget = getchar();
	// printf("\n");
	int ntarget = atoi(line_num);
	FILE *fp = NULL;
	
	fp = fopen(path, "r+");
	// fp = fopen("./test.txt", "r+");
	if (!fp)
	{
		printf("File open error!");
		return -1;
	}
	while ((c = getc(fp)) != EOF)
	{
		//TODO: check whether exceed the maxium of line number
		if (curLineNum >= ntarget)
		{
			goto stopReadingFile;
		}
		if (curLineNum == ntarget - 1)
		{
			printf("%c", c);
		}
		if ('\n' == c)
		{
			curLineNum++;
		}
	}
	printf("\n");
stopReadingFile:
	fclose(fp);
	return 0;
}
