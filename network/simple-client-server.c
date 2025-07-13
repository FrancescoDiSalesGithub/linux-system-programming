#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<string.h>
#include<arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main()
{
    int client_fd;

    struct sockaddr_in address;
    int server_fd = socket(AF_INET,SOCK_STREAM,0);
    
    char buffer[BUF_SIZE] = {0};
    int addrlen = sizeof(address);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd,(struct sockaddr*)&address,addrlen);
    listen(server_fd,3);

    client_fd = accept(server_fd,(struct sockaddr*)&address,(socklen_t*)&addrlen);


    while(strcmp(buffer,"exit"))
    {
        read(client_fd,buffer,BUF_SIZE);
        printf("received %s \n",buffer);
        send(client_fd,buffer,strlen(buffer),0);

    }
 

    close(client_fd);
    close(server_fd);

    return 0;
}
