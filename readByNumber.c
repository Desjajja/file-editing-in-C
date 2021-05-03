#include <stdio.h>
int main(int argc, char const *argv[])
{
	// 1st arg: path to the file
	// 2nd arg: number of the target line
	
	//TODO: check arg types

	char c;
	int lineNum = 0;
	FILE* fp = NULL;
	fp = fopen(argv[1], "r+");
	if (!fp)
	{
		printf("File open error!");
		return -1;
	}
	while ((c = getc(fp)) != EOF)
	{
		if ('\n' == c)
		{
			lineNum++;
		}
		//TODO: check whether exceed the maxium of line number
		if (lineNum >= argv[2])
		{
			goto stopReadingFile;
		}
		
	}
	stopReadingFile:
	fclose(fp);
	return 0;
}
