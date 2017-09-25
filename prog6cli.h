/*
 File name: prog6cli.h
 Description: This function contains the variables used in prog6cli.c file.
*/
#include "/home/cs631/common/config.h"
//variable for domain.
#ifndef DOMAIN
#define DOMAIN AF_INET
#endif
//variable for type.
#ifndef TYPE 
#define TYPE SOCK_STREAM
#endif
//variable for protocol.
#ifndef PROTOCOL
#define PROTOCOL 0
#endif
//variable for MAXLINE
#ifndef MAXLINE
#define MAXLINE 1000
#endif
//value for SERV_PORT.
#ifndef SERV_PORT
#define SERV_PORT 9880
#endif
#ifndef SA
#define SA struct sockaddr
#endif
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/errno.h>
#include<string.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#ifndef length
#define length 12
#endif
#ifndef de
#define de
//declaring the enum.
typedef enum {NEG_=-1,ZERO_,QM_,BYE_,CD_,CDUP_,CLOSE_,DISCONNECT_,HELP_,LCD_,OPEN_,PWD_,QUIT_} cmd_id;
//declaring the array.
extern const char* cmds[];
//declaring the array.  
extern const char* cmd_he[];
//declaring the int variable.
extern int b;
//cmd_id get_args(char*,char*,char*,char*);
cmd_id find_id(char*);
//function to print the list of valid commands.
void prnt_cmd_list();
//function to get the help about any command.
void prnt_cmd_help(char*);
//function prototype for cd.
void CD();
//function prototype for cdup
void CDUP();
//function prototype for help.
void HELP(char*,char*);
//function prototype for lcd.
void LCD(char*,char*);
//function prototype for open.
void OPEN(char*,char*,char*);
//function prototype for pwd.
void PWD();
//function prototype for qmark.
void QMARK(char*,char*);
//function prototype for client.
int client(char*,char*);
//function prototype for str_cli.
void str_cli(int,char[],size_t);
#endif
