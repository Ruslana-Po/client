#include<iostream>
#include<string.h>
#include<stdlib.h>
//exit
#include<unistd.h>
//содержит функции для работы с сетевыми адресами, такие как htons.
#include<arpa/inet.h>
//определяет символы, начинающиеся с " AF_ " для различных видов сетей и для работы сокетов
#include<sys/socket.h>
//функции для работы с сетевыми именами и адресами.
#include<netdb.h>
//содержащую определения для работы с интернет-адресами и портами.
#include<netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define NUMBER_PORT 1610
#define SYMBOL '~'
#define MAX_SIZE_BUF 1024

using namespace std;
bool ExitOrNO(const char* meaning);
void ErrorOrNo(int meaning);
void sendAMessage(int system, char* buffer);
void AcceptTheMessage(int system, char* buffer);
