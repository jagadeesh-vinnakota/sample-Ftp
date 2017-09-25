/*
  file name : inOut.c
*/
#include "inOut.h"
/*
 Function name : written
 return type: ssize_t
 Description: This function writes the requested data to the server. 
 return : returns the number of bytes written t the server 
*/
ssize_t writen(int fd, const void *vptr, size_t n)
{
  size_t nleft;
  ssize_t nwritten;
  const char *ptr;
   ptr = vptr;
   nleft = n;
  while(nleft > 0)
  {
    if( (nwritten = write(fd, ptr, nleft)) <=0)
         {
	   if(nwritten < 0 && errno == EINTR)
	      nwritten = 0;
	    else
	       return (-1);
	 }
     nleft -= nwritten;
     ptr+=nwritten;
  }
 return (n);
}
/*
  Funtion name : readline
  return type : ssize_t
  Description : This function reads the response which is given by the server.
  return : Returns the nuber of read. 
*/
ssize_t readline(int fd, void *vptr, size_t maxlen)
{
   ssize_t rc;
   size_t n;
   char c, *ptr;
   ptr = vptr;
   for(n =1;n<maxlen;n++)
    {
      again:
	   if( (rc = read(fd, &c, 1)) == 1)
	     {
		//printf("%c",c);
		*ptr++ = c;
		 if(c == '\n')
		  break;
	       }
             else if(rc == 0)
		{
		 *ptr = 0;
		 return (n-1);
		}
	      else
		{
		  if(errno == EINTR)
                    goto again;
		  return (-1);
                }
            }
   *ptr = 0;
   return (n);
 }
