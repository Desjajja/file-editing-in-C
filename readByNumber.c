#include <stdio.h>
int main(int argc, char const *argv[])
{
	// 1st arg: path to the file
	// 2nd arg: number of the target line

	//TODO: check arg types

	char c;
	int lineNum = 0;
	printf("Input the line number to be printed: ");
	char ctarget = getchar();
	printf("\n");
	int ntarget = ctarget - '0';
	FILE *fp = NULL;

	// fp = fopen(argv[1], "r+");
	fp = fopen("./test.txt", "r+");
	if (!fp)
	{
		printf("File open error!");
		return -1;
	}
	while ((c = getc(fp)) != EOF)
	{
		//TODO: check whether exceed the maxium of line number
		if (lineNum >= ntarget)
		{
			goto stopReadingFile;
		}
		if (lineNum == ntarget - 1)
		{
			printf("%c", c);
		}
		if ('\n' == c)
		{
			lineNum++;
		}
	}
stopReadingFile:
	fclose(fp);
	return 0;
}
