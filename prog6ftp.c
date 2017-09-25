#include "prog6cli.h"
//unsigned length =12;
const char* cmds[] = {"","?","bye","cd","cdup","close","disconnect","help","lcd","open","pwd","quit" };
const char* cmd_he[] ={"not in the list ","?	prints the infomation about a command","bye	terminate connection and exit ftp",
"cd	changes the server remote directory","cdup	changes to parent directory","close	 terminate the session and enters into ftp interpreter",
"disconnect	terminate the session and enters into ftp interpreter"," help	prints information about command",
"lcd	changes the local directory"," open	open a coonetion to server","pwd	gives current working directory","quit	terminates the connection and exit ftp"};
int b=0;
int main()
{
/*const char* cmds[] = {"","?","bye","cd","cdup","close","disconnect","help","lcd","open","pwd","quit" };
const char* cmd_he[] ={"not in the list ","prints the infomation about a command","terminate connection and exit ftp",
"changes the server remote directory","changes to parent directory"," terminate the session and enters into ftp interpreter",
"terminate the session and enters into ftp interpreter"," prints information about */
char buf[MAXLINE];
 printf("ftp> ");
  while( fgets(buf,MAXLINE,stdin))
 {
   char* cmd = NULL;
   char* arg1=NULL; char* arg2 = NULL;
   if(strlen(buf) > 1)
   {
  buf[strlen(buf) -1]='\0'; 
char* event; 
event = strtok(buf," ");
  if(event!=NULL)
  {
    cmd = (char*) malloc(strlen(event) * sizeof(char));
     cmd = event;
  }
 event = strtok(NULL," ");
 if(event!=NULL)
{
arg1=(char*) malloc(strlen(event)*sizeof(char));
arg1 = event;
} 
event = strtok(NULL," ");
if(event!=NULL)
{
 arg2 = (char*) malloc(strlen(event)*sizeof(char));
 arg2 = event;
} 
 cmd_id j = find_id(cmd);
   switch(j)
    {
     	case NEG_:
				printf("not a valid command \n"); break;
     	case ZERO_: 
				printf("\n"); break;
     	case QM_: 
				QMARK(arg1,arg2); break;
	case HELP_:             HELP(arg1,arg2);
				break;
	case BYE_: 
				exit(0); break;
	case QUIT_:   
				exit(0); break;  
     	case CLOSE_:
			        if(b==0) printf("not connected\n"); break;
	case DISCONNECT_:
                                if(b==0) printf("not connected\n");           
						break;
     	case LCD_:
				LCD(arg1,arg2); break;
	case OPEN_:             client(arg1,arg2); break;
	  
     	case CD_: 
				CD();
             	  		break;
	case CDUP_: 
				CDUP(); break;
        case PWD_:
				PWD(); break;
	default: 
				printf("no commands \n");  
     }
   }
   printf("ftp> ");
}
return 0;
}
