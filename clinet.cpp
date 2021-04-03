#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define DEST_IP "192.168.3.10"
#define DEST_PORT 20800
int main(){
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in dest_addr;
    memset(&dest_addr,0,sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    dest_addr.sin_port = htons(DEST_PORT);
    if(connect(sockfd,(sockaddr*)&dest_addr,sizeof(sockaddr) == -1)){
        printf("Connect Faild!");
        return 1;
    }

}
  

