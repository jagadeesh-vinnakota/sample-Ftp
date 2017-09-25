/**************************************************************************
File Name: util6cli.c
Description:   contains the information about the commands.
*************************************************************************/
#include "prog6cli.h"
//this function prints the help information about a command.
void HELP(char* ag1,char* ag2)
{
	if(ag1!=NULL && ag2!=NULL) printf("correct usage is: help \n");
	//printing the valid list of commands if no argument is provided to help.
	else if(ag1==NULL&&ag2==NULL ) prnt_cmd_list();
	//printing the informnation about a command if argument is specified.
                 else if(ag1!=NULL && ag2==NULL)  prnt_cmd_help(ag1);
}
//this function prints the help information about a command.
void QMARK(char* ag1,char* ag2)
{
		if(ag1!=NULL && ag2!=NULL) printf("correct usage is: ? \n");
	//printing the informnation about a command if argument is specified.
		else if(ag1==NULL&&ag2==NULL ) prnt_cmd_list();
	//printing the informnation about a command if argument is specified.
	else if(ag1!=NULL && ag2==NULL)  prnt_cmd_help(ag1);
}
//this function checks if the client connected to server or not.
void CD()
{
	//checking the connection related variable.
	if(b==0)
	{
	 printf("not connected.\n");
	}
}
//this function checks if the client connected to server or not.
void CDUP()
{
		//checking the connection related variable.
	if(b==0)
	{
	  printf("not connected.\n");
	}
}
//changing the local directory.
void LCD(char* ag1,char* ag2)
{
	//checking for the usage.
 if(ag1!=NULL && ag2!=NULL) {
			printf("usage is: lcd localdirectory \n"); 
			}
			//checking for arguments provided or not.
                else if(ag1!=NULL && ag2==NULL) 
		        {
					//checking for ~.
                    if(strcmp(ag1,"~")==0 )
						{
					//changing directory to home directory.
					chdir(getenv("HOME"));
					}
                  else{
					  //changing the directory to specific directory.
                   chdir(ag1);	
                    }
		   char storr[MAXLINE];
		    getcwd(storr,MAXLINE);
			//printing the local directory.
		   printf("LOCAL DIRECTORY NOW  %s\n",storr);
			} 
               else if(ag1==NULL&&ag2==NULL)
		   {
			char stor[MAXLINE];
                 getcwd(stor,MAXLINE);
		   printf("LOCAL DIRECTORY NOW  %s \n", stor);	
          }
}
//this function checks if the client connected to server or not.
void PWD()
{
		//checking the connection related variable.
	if(b==0)
	{
		 printf("not connected.\n");
	}
}

//printing the information about a particular command.
void prnt_cmd_help(char* a)
{
  int k = find_id(a);
  puts(cmd_he[k]);
}
//used to return the index of the array which is equal to the ennumeration.
cmd_id find_id(char* cmd)
{
 for(unsigned i=0;i<length;i++)
 {
    if((strcmp(cmd,cmds[i])) ==0)
     {
      return i ;
     }
  }
  return -1; 
}
//printing the list of valid commands.
void prnt_cmd_list()
{
 for(unsigned i=1;i<length;i++)
  {
     printf("%s \t",cmds[i]); 
   }
  printf("\n");
}
