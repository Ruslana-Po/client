#include "head.h"

int main(){
    //Объявляет переменную для хранения дескриптора сокета
    int client = 0;
    //указывает на структуру в которой хранится информация о сокете
    struct sockaddr_in server_address;
    //Создает сокет с использованием протокола TCP (SOCK_STREAM).
    client = socket(AF_INET, SOCK_STREAM, 0);
    ErrorOrNo(client);
    
   //Устанавливает номер порта, на котором сервер будет слушать подключения.
    server_address.sin_port = htons(NUMBER_PORT);

    //использование IPv4.
    server_address.sin_family =AF_INET;

    // Преобразуем строковый IP-адрес в двоичный формат
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);
    cout<<"\n => Soket для клиента создан";

    //Привязывает сокет к указанному адресу и порту.
     int ret = connect(client, reinterpret_cast<const struct sockaddr*>(&server_address), sizeof(server_address));
    if(ret==0){
        cout<<"\n---Connection to server  "<< inet_ntoa(server_address.sin_addr)<<" whith port number: "<<NUMBER_PORT<<"\n ";

    }
    //ErrorOrNo(ret);
    
    char buffer[MAX_SIZE_BUF];
    cout<<"=> Ожидание подтверждения с сервера... \n";

    //получение сообщения от клиента
    recv(client, buffer, MAX_SIZE_BUF, 0);
    cout<<"=> Connection establishing.\n";
    cout<<"Enter "<<SYMBOL<<" for close the connection"<<endl;
    
    while(true){
        cout<<"Client: ";
        sendAMessage(client,buffer);
        cout<<"Server: ";
        //получение сообщение от сервеса
        AcceptTheMessage(client, buffer);
        cout<<endl;
    }

    return 0;
}
