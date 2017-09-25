/*
NAME 				: VINNAKOTA JAGADEESH.
ASSIGNMENT NUMBER 	: 6.
DUE DATE			: 4/11/2016.
*/
#include "prog6cli.h"
#include "wrap6cli.h"
#include "inOut.h"
/***********************************************************************************************************************************
Name : client
return : int
Parameters : char*,char*
Description: This function is used to handle the client by connecting to the remote server by giving the ip adress and port number.
			Then it calls the subroutine str_cli to continue communication with the server.
***********************************************************************************************************************************/
int client(char* ag1,char* ag2)
{
	//variable to store ip adress.
    char ags[MAXLINE];
	//a variable to store the port number
  int  portno;
  //variables to stores the parsed string.
 char* c=NULL;char* cc=NULL;
	if(ag1==NULL)
	{ 
	   printf("(to)");
	   //reading the ip adress to ags.
           fgets(ags,MAXLINE,stdin);
           ags[strlen(ags)-1] = '\0';
		   //a variable to store the splitted string.
           char* eve = strtok(ags," ");
	  if(eve!=NULL)
	  {
		  //allocating memory to c.
	   c = (char*) malloc(strlen(eve)*sizeof(char));
	   //copying the string to c.
          strcpy(c,eve);
	  }
	//a variable to store the splitted string.
	  eve =strtok(NULL," ");
	  if(eve!=NULL)
	    {
			//allocating memory
              cc = (char*) malloc(strlen(eve)*sizeof(char));
	strcpy(cc,eve);
		}
		//assigning the port number.
           if(cc==NULL) portno = SERV_PORT;
	   else 
	   {
		   //converting the port number to integer.
		   portno = atoi(cc);
	   }
	}
     if(ag1!=NULL) 
        {
			//copying the string 
			strcpy(ags,ag1); 
			//assigning the default port number.
	portno = SERV_PORT; 
	    }
	else if(ag2!=NULL)
	{
		//converting the portnumber from string to integer.
		portno = atoi(ag2);
	}
   // sockfd stores the socket information. cn stores the connect information. in stores the inet_pton information. n stores the read information.  
   int sockfd,in;
   //a variable to store the message 
   struct sockaddr_in servaddr;
		 //calling the socket wrapper function inorder to create a socket.
       sockfd = Socket(DOMAIN, TYPE, PROTOCOL);
    // This function fill the structure with zeros.
       bzero(&servaddr, sizeof(servaddr));
	   //filling the server structure
       servaddr.sin_family = DOMAIN;
    // htons converts the host byte order to network byte order
       servaddr.sin_port = htons(portno);
    // calling the inet_pton wrapper function inorder to convert the ip adress	   
      if( ((in = Inet_pton(DOMAIN, ags, &servaddr.sin_addr))==1) )
     {
        // calling the connect wrapper function inorder to connect to the server.
               Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
			//a variable to determine the connection.
			b=1;   
			printf(" \n connected to %s \n",ags);
			printf("ftp> ");
			//a variable to store the command.
			char buf[MAXLINE];
  while( fgets(buf,MAXLINE,stdin))
 {
	 			//a variable to store the command.
   char buff[MAXLINE];
   //copying the string.
   strcpy(buff,buf);
 //declaring the variables to store the parsed command.
   char* cmd = NULL;
   char* arg1=NULL; char* arg2 = NULL;
   //checking for the command length. 
   if(strlen(buff) > 1)
   {
	   //replacing \n with \0.
	buff[strlen(buff) -1]='\0'; 
	buf[strlen(buf)-1] = '\0';
	//a variable to store the command.
	char* event; 
	//splitting the string.
	event = strtok(buff," ");
	if(event!=NULL)
	{
		//allocating memory.
    cmd = (char*) malloc(strlen(event) * sizeof(char));
	//copying the string.
     strcpy(cmd,event);
	}
	//storing the splitted string.
	event = strtok(NULL," ");
	if(event!=NULL)
	{
		//allocating memory.
		arg1=(char*) malloc(strlen(event)*sizeof(char));
		//copying the string.
		strcpy(arg1,event);
	} 
	event = strtok(NULL," ");
	if(event!=NULL)
	{
		//allocating memory.
		arg2 = (char*) malloc(strlen(event)*sizeof(char));
		strcpy(arg2,event);
	} 
	//getting the vaalue of cmd_id type value to give input to the switch case.
 cmd_id j = find_id(cmd);
   switch(j)
    {
     case NEG_:
				//not a vlaid command.
				printf("not a valid command \n"); break;
     case ZERO_: 
				//if not a valid command.
				printf("\n"); break;
     case QM_: 
				//calling the QMARK function.
				QMARK(arg1,arg2); break;
     case HELP_:
					//calling the HELP function.
                		HELP(arg1,arg2);
				break;
     case BYE_:
				//closing the socket and terminating the program.
				Close(sockfd);
				exit(0);
				break;
    case QUIT_:
				//closing the socket and terminating the program.
				Close(sockfd);
				 exit(0); 
				 break;  
    case CLOSE_:
				//closing the socket.
				Close(sockfd);
				puts("\n Goodbye");
				//changing the connection related variable.
			              b=0;
				  return 1;
				break;
    case DISCONNECT_:
				//closing the socket.
				Close(sockfd);
				puts("\n Goodbye");
				//changing the connection related variable.
				 b=0;
				 return 1;                        
				 break;
    case OPEN_:	
				//checking for the double open.
				if(b==1) 
				 {
					printf("already in connection. first close the connection\n");     
				 } break;
    case LCD_:
				//calling the LCD function.
				LCD(arg1,arg2); 
				break;
	  
    case CD_: if(arg1==NULL) 
				{
					//declaring the variable.
                    char ar[MAXLINE];
					printf("(remote directory)");
					//reading the variable.
					fgets(ar,MAXLINE,stdin);
					//replacing \n with \0.
					ar[strlen(ar)-1] = '\0';
					unsigned j=0;
					//inserting space to the string.
					buf[strlen(buf)] = ' ';
					for(unsigned i=strlen(buf);i<(strlen(buf))+strlen(ar);i++)
						buf[i] = ar[j++];
 				}
				//calling the str_cli function.
				 str_cli(sockfd,buf,strlen(buf));                    
     		        	  break;
   case CDUP_:
				//calling the str_cli function.   
				str_cli(sockfd,buf,strlen(buf)); break;
   case PWD_: 
   				//calling the str_cli function.
				str_cli(sockfd,buf,strlen(buf)); break;
   default: 
				printf("no commands \n");  
     }
   }
   printf("ftp> ");
 } 
		//closing the socket.
        Close(sockfd); 
}
return 0;
}
void str_cli(int sockfd,char param[],size_t size)
{
		//a variable to store the message.
    char recvline[MAXLINE];
	             param[size] = '\n';         
       size_t len = strlen(param);
				//writing the data to the socket inorder to get the response fro the server.
               Writen(sockfd, param, len);
			   //filling the recvline with zeros.
        bzero(recvline,MAXLINE);
				//reading the data from the server and storing it in recvline.             
if( Readline(sockfd, recvline, MAXLINE) == 0)
		      {
		        fprintf(stderr, "server terminated prematurely\n");
		      }
			  //priting the response on stdout.
            if(recvline[0]=='0')
				puts("Sucessfully changed remote diretory");
               else if(recvline[0]=='1')
				   puts("unsucess while changing remote diretory");
              else Fputs(recvline, stdout);
       //filling the array with zeros.
	   bzero(recvline,MAXLINE);
             }
