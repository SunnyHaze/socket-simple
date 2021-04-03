#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
const int BACKLOG = 10;
int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    //AF_INET6是IPv6
    //SOCK_DGRAM 无连接的数据的传输方式 UDP
    //SOCK_STREAM以TCP连接的方式保证传输能力
    //为bind函数做准备
    sockaddr_in sockAddr;
    memset(&sockAddr,0,sizeof(sockAddr));
    sockAddr.sin_addr.s_addr = INADDR_ANY;//这个是自动调用本机的设置
    // inet_addr已经是网络字节格式。
    //自行设置用这种方式：inet_addr("192.168.3.10")
    if(sockAddr.sin_addr.s_addr == -1){
        printf("target IP wrong!\n");
        return 1;
    }
    printf("%s\n",inet_ntoa(sockAddr.sin_addr));
    sockAddr.sin_family = PF_INET;
    // 端口号可以是1024到65535的端口（只要没被其他程序使用）
    sockAddr.sin_port - htons(20800);
    if(bind(sock,(sockaddr*)&sockAddr,sizeof(sockaddr)) < 0 ){
        printf("Bind faild,ERROR\n");
        return 1;
    };

    if(listen(sock,BACKLOG) == -1){
        printf("listen ERROR!\n");
        return 0;
    }
    
}   