#include "head.h"
bool ExitOrNO(const char* meaning){
    for(size_t i=0; i< strlen(meaning); ++i){
        if(meaning[i] == SYMBOL){
            return true;
        }
    }
    return false;
 }

 void ErrorOrNo(int meaning){
    if(meaning<0){
        cout<<"Error\n";
        exit(0);
    }
 }
void ClientOrServer(int system, const char* buffer){
    if(ExitOrNO(buffer)){
       close(system);
        cout<<"Goodbye... \n";
        exit(1);
    }
}
//Отправление сообщения
 void sendAMessage(int system, char* buffer){
    cin.getline(buffer, MAX_SIZE_BUF);
    //Отправляет сообщение  сервису
    send(system, buffer, MAX_SIZE_BUF,0);
    //Проверка не символ ли
    ClientOrServer(system, buffer);
 }

 //Принять сообщение
 void AcceptTheMessage(int system, char* buffer){
    recv(system, buffer, MAX_SIZE_BUF, 0);
    cout<<buffer;
    //Проверка не символ ли
   ClientOrServer(system, buffer);
   cout<<endl;
 }

 
