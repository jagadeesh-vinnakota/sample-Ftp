/*
  File name: inOut.h
*/

#include "prog6srv.h"
//function prototype for writen which is used to write the data to the socket
ssize_t writen(int filedes, const void* buf, size_t nbytes);
//function prototype for readline which is used to read the data from the socket
ssize_t readline(int fildes, void *buf, size_t maxlen);
