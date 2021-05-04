#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/writeByLine.h"

int writeByLine(const char * path, char * cline_content, const char * nline_num)
{
	int lineNum = atoi(nline_num);
	char buf[MAX_ROW][32] = {0};
	// load file content into buffer
	FILE * fp = fopen(path, "r");
	for (int i = 0; i < MAX_ROW; i++)
	{
		fgets(buf[i], 32, fp);
	}
	fclose(fp);
	
	
	for (int i = MAX_ROW - 1; i >= lineNum; i--) // eg. lineNum = 2, start from 9, stop by 2
	{
		strcpy(buf[i], buf[i-1]); // make space for insertion.
		// for (int j = 0; j < 32; j++)
		// {
		// 	buf[i][j] = buf[i-1][j];
		// }
	}
	
	strcpy(buf[lineNum-1], cline_content); // write the content into target line
	fp = fopen(path, "w");
	for (int i = 0; i < MAX_ROW; i++)
	{
		fputs(buf[i], fp);
	}
	fclose(fp);
	return 0;
}