
#include<sys/types.h>
#include "prog6cli.h"
#include "/home/cs631/common/config.h"
//It is a prototype for Close wrapper function in which it calls the close system call.
int Close(int fd);
//It is a prototype for Socket wrapper function in which it calls the Socket system call.
int Socket(int family, int type, int protocol);
//It is a prototype for Inet_pton wrapper function in which it calls the inet_pton system call.
int Inet_pton(int af, const char *src, void *dst);
//It is a protype for Connet wrapper function in which it calls the connect system call.
int Connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
//It is a prototype for Fputs wrapper function in which it calls the fputs system call.
int Fputs(const char *s, FILE *stream); 
//It is a prototype for Fgets wrapper function in which it calls the fgets system call.
char* Fgets(char* str, int n, FILE* stream);
//It is a prototype for Writen wrapper function in which it calls the writen function.
ssize_t Writen(int fd, const void *vptr, size_t n);
//It is a prototype for Readline wrapper function in which it calls the readline function.
ssize_t Readline(int fd, void *vptr, size_t maxlen);
