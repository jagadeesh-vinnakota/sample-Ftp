// defines the Internet layer protocol
#ifndef DOMAIN
#define DOMAIN AF_INET
#endif
//defines the transport layer protocol
#ifndef TYPE
#define TYPE SOCK_STREAM
#endif
#ifndef PROTOCOL
#define PROTOCOL 0
#endif
//defines the size of the buffer
#ifndef MAXLINE
#define MAXLINE 1000
#endif
//defines the number of clients can wait in a queue
#ifndef LIST
#define LIST 5
#endif
#ifndef SA
#define SA struct sockaddr
#endif
#ifndef PATH
#define PATH "/home/cs631/common/books.d"
#endif
#ifndef SERV_PORT
#define SERV_PORT 9880
#endif
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/errno.h>
#include<string.h>
#include<time.h>
#include<stdint.h>
#include<signal.h>
#include<sys/wait.h>
//function prototype for pwd function.
char* PWD();
//function prototype for the cal function
void cal(int);
//function prototype to handle the terminated child processes.
void sig_chld( );
