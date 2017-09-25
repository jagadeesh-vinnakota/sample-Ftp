/*
 Filename : wrap6cli.c
 Description: This file contains the wrapper functions required for prog6cli.c.
*/
#include "prog6cli.h"
#include "wrap6cli.h"
#include "inOut.h"
//#include <unistd.h>
/*********************************************************************************************************************************************************************

Function Name : Socket
Parameters    : network layer protocol, transport layer protocol,
		protocol information
Return        : An integer is returned
Description   : This fuction is a wrapper around socket() system call.
		It returns an integer(file discriptor) on sucess. If an error occurs during the execution of system call then an error is displayed and it exits.

******************************************************************************************************************************************************************* */
    int Socket(int family, int type, int protocol)
	{
	   errno = 0;
	   int s;
	   if((s = socket(family, type, protocol)) < 0)
		{
		  fprintf(stderr, "sock fn failed %s ", strerror(errno));
		  Close(s);
		  exit(1);
		 }
	    return s;
	}
/*******************************************************************************************************************************************************************

Function Name : Inet_pton
parameters    : network layer protocal, IP address of the destination, structure variable to store converted adress
Return	      : An integer is returned
Description   : This function is a wrapper around inet_pton() system call. 
		It converts the ip address to network format and store it in 
		a structure variable and returns an integer on success. If any error occurs during system call an error message is displayed and exits 	

******************************************************************************************************************************************************************* */
  int Inet_pton(int af, const char *src, void *dst) 
       {
	 errno =0;
	int i;
	    if(((i = (inet_pton(af, src, dst))) <=0))
	    {
             if(i < 0 )
	      {
	      perror("inet_pton error");
              // fprintf(stderr, "not a valid adress in the specified family %s",strerror(errno));
             exit(1);
              }
             if(i == 0)
		{
		fprintf ( stderr, "not a valid adress\n" );
                //perror(" system error ip");
	        exit(2);
		}
	    }
         return i;
       }
/********************************************************************************************************************************************************************

Function Name : Connect
Parameters    : socketfile descriptor, address of the detination machine, length of the adress
Return        : An integer is returned
Desription    : This function is a wrapper around connect() system call.
		It connects the socket to the destination and an iteger is returned on success. If any error occurs on execution of system call then error is displayed 		and exits.
 
*********************************************************************************************************************************************************************/
   int Connect(int sockfd, const  struct sockaddr* addr, socklen_t addrlen)
      {
        errno =0;
	int co;
	 if((co = connect(sockfd, addr, addrlen)) < 0 )
           {
	    fprintf(stderr, "connection failed %s", strerror(errno));
	      Close(sockfd);
               exit(1);  
	   }
         return co;
      }
/********************************************************************************************************************************************************************

Function Name : Fputs
Parameters    : chracter stream, file stream
Return	      : An integer is returned
Desription    : It is a wrapper around fputs() system call. 
		Takes the character stream and writes it to file. It returns an integer on success. If any error during read then error is printed and exits.
 
*********************************************************************************************************************************************************************/
    int Fputs(const char *s, FILE *stream)
    {
	 errno=0;
	int t = fputs(s, stream);
	  if(t<0)
	   {
	  fprintf(stderr, "fputs error %s", strerror(errno));
	  exit(1);
	}
       return 0;
     }
/*********************************************************************************************************************************************************************

Function Name : Close
Parameters    : file descriptor
Return        : An integer is returned
Description   : It is a wrapper around close() system call.
                It takes the file descriptor, closes the file and returns an integer on sucess. If any error in system call then error is displayed and exits.

**********************************************************************************************************************************************************************/
int Close(int fd)
{
 errno =0;
	if(close(fd) < 0)
	{
          perror("error on close \n");
          exit(1);
	}
        else
	{
	 return 0;
	}
}
/***********************************************************************/
//  Fgets()	: A wrapper function which takes  contents from stdout.	
//  Arguments	: returns the character string read.						/
//  Return	: Upon successful completion, it return the string. 	
/**********************************************************************/

char* Fgets(char *str, int n, FILE* stream)
{
errno = 0;
  char* res;
   res = fgets(str,n,stream);
   return res;
}
/***********************************************************************/
//  Readline()	: A wrapper function which is used to read from a file	/
//  		  descriptor.						/
//  Arguments	: Attempts to read up to 'count' bytes from file descri-/
//  		  ptor 'fd' into the buffer starting at 'buf'.		/	
//  Return	: On success, the number of bytes read is returned (zero/
//  		  indicates EOF), and the file position is advanced by  /
//  		  this number. On error, -1 is returned, and errno  is 	/
//  		  set appropriately. In this case it is left unspecified/
//  		  whether the file position (if any) changes.		/
//**********************************************************************/

ssize_t Readline(int fd, void *buf, size_t count)
{
errno = 0;
 ssize_t n;
  if((n = readline(fd,buf,count))<0)
     {
       fprintf(stderr, "readline error");
       exit(1);
       }
  return n;
} 
/***********************************************************************/
//  Writen()	: A wrapper function which writes contents in the buffer/
//  		  into a file.						/	
//  Arguments	: write 'nbyte' bytes from the buffer pointed to by'buf'/
//  	          to the file associated with the open file descriptor, /
//  	          'fildes'.						/
//  Return	: Upon successful completion, Write()shall return the	/
//  		  number of bytes actually written to the file associat-/
//  		  ed with fildes.Otherwise, -1 shall be returned and 	/
//  		  errno set to indicate the error. 			/	
//**********************************************************************/
ssize_t Writen(int fildes, const void* buf, size_t count)
{
 errno = 0;
  ssize_t n;
   if((n = writen(fildes, buf, count))<0)
   {
      fprintf(stderr, "writen error");
       exit(1);
     }
 return n;
}
