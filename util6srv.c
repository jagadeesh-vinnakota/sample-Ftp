#include "prog6srv.h"
// this function is used to get the present working directory path.
char* PWD()
{
	//variables to store the length and data.
char* ch;
long size;
//setting the size to the maxlen with sytem variable.
size = pathconf(".",_PC_PATH_MAX);
//allocating memory.
ch = (char*) malloc((size_t)size);
if(ch!=NULL)
{
	//calling the getcwd function to get the current working directory.
 getcwd(ch,(size_t)size);
}
 return ch;
}

