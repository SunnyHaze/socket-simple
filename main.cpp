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
    //AF_INET6��IPv6
    //SOCK_DGRAM �����ӵ����ݵĴ��䷽ʽ UDP
    //SOCK_STREAM��TCP���ӵķ�ʽ��֤��������
    //Ϊbind������׼��
    sockaddr_in sockAddr;
    memset(&sockAddr,0,sizeof(sockAddr));
    sockAddr.sin_addr.s_addr = INADDR_ANY;//������Զ����ñ���������
    // inet_addr�Ѿ��������ֽڸ�ʽ��
    //�������������ַ�ʽ��inet_addr("192.168.3.10")
    if(sockAddr.sin_addr.s_addr == -1){
        printf("target IP wrong!\n");
        return 1;
    }
    printf("%s\n",inet_ntoa(sockAddr.sin_addr));
    sockAddr.sin_family = PF_INET;
    // �˿ںſ�����1024��65535�Ķ˿ڣ�ֻҪû����������ʹ�ã�
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