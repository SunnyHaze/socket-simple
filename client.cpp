#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define DEST_IP "127.0.0.1"
#define DEST_PORT 4001
#include <iostream>
int main(){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock == -1){
        std::cout << "Could not create socket\n";
    }
    std::cout << "Socket created\n";

    struct sockaddr_in dest_addr;
    memset(&dest_addr,0,sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr("192.168.3.10");
    dest_addr.sin_port = htons(1234);

    //Á´½Ó·þÎñ¶Ë
    if(connect(sock,(sockaddr*)&dest_addr,sizeof(dest_addr)) == -1){
        printf("Connect Faild!");
        return 1;
    }
    std::cout << "Connected\n";
    char message[100];
    while(1){
        std::cout << "Enter message:\n";
        memset(message,0,sizeof(message));//????????????????
        std::cin >> message;
        if(send(sock,message,strlen(message),0) == -1){
            
        }
    }
    close(sock);
    return 0;
}
  

