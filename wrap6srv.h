/*
 File name: wrap6srv.h
 Description : This file contains the function prototypes for wrapper functions. 
*/
#include<sys/socket.h>
#include "prog6srv.h"
#include "/home/cs631/common/config.h"
//Prototype for Socket wrapper function in which it calls the socket system call by passing necassary parameters which creates a socket
int Socket(int domain, int type, int protocol);
//prototype for Bind wrapper function in which it calls the bind sytem call by passing necassary parameters  inorder to bind the socket
int Bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
//prototype for Listen wrapper function in which it calls the listen system call by passing necassary parameters inorder to listen for theclients
int Listen(int sockfd, int backlog);
//prototype for Accept wrapper function in which it calls the accept system call by passing necassary parameters inorder to accept the client connection
int Accept(int sockfd, struct sockaddr* addr, socklen_t* addrlen);
//function prototype for close function.
int Close(int fd);
//function prototype for Fgets function 
char* Fgets(char* str, int n, FILE* stream);
//function prototype for writen function.
ssize_t Writen(int fd, const void* vptr, size_t n);
//function prototype for readline function.
ssize_t Readline(int fd, void* vptr, size_t maxlen);
//functions prototype waitpid wrapper function.
void Waitpid(pid_t pid,int* status, int options);
void Wait(int *);
//function prototype for fork system call.
pid_t Fork();
//function protype for signal system call.
typedef void (*sighandler_t)(int);
sighandler_t Signal(int signo, sighandler_t func);
