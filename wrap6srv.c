/*
 File name: wrap6srv.c
*/
#include "wrap6srv.h"
#include "prog6srv.h"
#include "inOut.h"
//In this wrapper function, call the socket system call by passing necassary parameters inorder to create socket for the communication
int Socket(int domain, int type, int protocol)
{
  //sets the error number to zero
  errno = 0;
  //stores the return value of the socket system call
  int so;
    if((so = socket(domain, type, protocol))<0)
	{
	  fprintf(stderr, "socket creation failed %s", strerror(errno));
	  Close(so);
	  exit(1);
	}
    return so;
}
// In this wrapper function, call the bind system call by passing necassary parameters inorder to bind the socket 
int Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen)
{
   //sets the error number to zero
   errno = 0;
   //stores the return value of the bind system call
   int bo;
      if((bo = bind(sockfd, addr, addrlen))<0)
	{
	  fprintf(stderr, "binding of socket failed %s", strerror(errno));
	  Close(sockfd);
	  exit(1);
	}
    return bo;
}
//In this wrapper function, call the listen system call by passing necassary arguments in order to listen for the clients who are reqesting connections  
int Listen(int sockfd, int backlog)
{
 //sets the error number to zero
  errno = 0;
 // stores the return value of the listen system call.
  int lo;
   if((lo = listen(sockfd, backlog)) < 0)
    {
      fprintf(stderr, "listen failed %s", strerror(errno));
      Close(sockfd);
	  exit(1);
    }
  return lo;
}
//In this wrapper function, call the accept system call by passing necassary arguments inorder to accept the client to make connection
int Accept(int sockfd, struct sockaddr* addr, socklen_t *addrlen)
{
// sets the error number to zero
   again:  errno = 0;
  // stores the rteurn valueof the accept syatem call
   int ac;
    if((ac = accept(sockfd, addr, addrlen))<0)
    {
		//checking for the interrupt signal on a call to accept.
		if(errno == EINTR) goto again;
      fprintf(stderr, " accept failed %s", strerror(errno));
       Close(sockfd);
	   exit(1);
    }
 return ac;
}
 //In this wrapper function, call the close system call by passing the necassary arguments inorder to close the socket.
int Close(int fd)
{
errno = 0;
//stores the return value of the close system call
 int f;
  if(((f = close(fd)) < 0)&& errno!=0 )
    {
      perror("close failed on socket side");
      exit(1);
     }
  return f;
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
  if((n = readline(fd,buf,count)) < 0)
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


ssize_t Writen(int filedes, const void* buf, size_t count)
{
  ssize_t n;
   if((n = writen(filedes, buf, count)) < 0)
    {
      fprintf(stderr, "writen error");
      exit(1);
    }
   return n;
 }

/*
Function name   : Fork
description     : handles the server to create multiple process to behave server as a concurrent server. 
*/
pid_t Fork()
{
	errno = 0;
	pid_t t;
	//calling the fork system call.
	if((t = fork()) <0)
	{
		fprintf(stderr,"Fork error %s", strerror(errno));
		exit(-1);
	}
	return t;
}
// Function name : Signal
// description : it handles the signal process of child to father.
sighandler_t Signal(int signo, sighandler_t func)
{
	errno = 0;
	//calling the signal system call.
	signal(signo,func);
	if(errno!=0)
	{
		fprintf(stderr,"signal error %s",strerror(errno));
		exit(-1);
	}
 return func;
}
void Wait(int* status)
{
  errno = 0;
  pid_t pi;
    if( ((pi = wait(status)) < 0) && ( errno!=0))
	{
           fprintf(stderr,"wait error %s",strerror(errno));
	  exit(-1);
	}
}
