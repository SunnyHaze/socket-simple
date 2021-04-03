#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
const int BACKLOG = 10;
int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock == -1){
        std::cout << "Error while creating a socket" << std::endl;
    }
    std::cout << "socket created \n";
    
    //AF_INET6是IPv6
    //SOCK_DGRAM 无连接的数据的传输方式 UDP
    //SOCK_STREAM以TCP连接的方式保证传输能力
    //为bind函数做准备
    sockaddr_in sockAddr;
    memset(&sockAddr,0,sizeof(sockAddr));

    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//这个是自动调用本机的设置
    // inet_addr已经是网络字节格式。
    //自行设置用这种方式：inet_addr("192.168.3.10")
    if(sockAddr.sin_addr.s_addr == -1){
        printf("target IP wrong!\n");
        return 1;
    }
    printf("%s:",inet_ntoa(sockAddr.sin_addr));
    sockAddr.sin_family = AF_INET;
    // 端口号可以是1024到65535的端口（只要没被其他程序使用）
    sockAddr.sin_port = htons(1234);
    
    if(bind(sock,(sockaddr*)&sockAddr,sizeof(sockAddr)) < 0 ){
        printf("Bind faild,ERROR\n");
        return 1;
    };
    std::cout << sockAddr.sin_port << std::endl;
    printf("bind done\n");

    if(listen(sock,20) == -1){
        printf("listen ERROR!\n");
        return 0;
    }

    printf("Waiting for incoming connections...\n");
    
    socklen_t c = sizeof(sockaddr_in);
    sockaddr_in client;
    // accept connection from an incoming client;
    int client_sock = accept(sock,(sockaddr*)&client,&c);
    if(client_sock < 0){
        printf("ACCEPT faild\n");
        return 1;
    }
       
    printf("Connection accepted\n");

    char client_message[100];
    int read_size;
    while( (read_size = recv(client_sock,client_message,sizeof(client_message),0) )> 0 ){
        std::cout << client_message << std::endl;
    }
    if(read_size == 0){
        std::cout << "Client disconnected" << std::endl;
    }
    if(read_size == -1){
        std::cout << "RECV faild" << std::endl;
    }
    return 0;
}   