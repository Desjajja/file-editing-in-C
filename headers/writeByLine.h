#if !defined(__WRITEBYLINE__)
#define __WRITEBYLINE__

#define MAX_ROW 10
int writeByLine(const char * path, char * cline_content ,const char * cline_num, char buf_restore[MAX_ROW][32], int restore);

#endif // __WRITEBYLINE__
