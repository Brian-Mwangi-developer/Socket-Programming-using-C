#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    int number1,number2;
    printf("Enter the firstintergers:\n");
    scanf("%d",&number1);
    printf("Enter the Second intergers:\n");
    scanf("%d",&number2);

    char buffer[1024] = {0};
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    //sending data to Server
    char both_num[10];
    //sprintf()is used to send formatted output to the string.
    //it stores the output on char buffer that is specified in sprintf.instead of printing in console
    sprintf(both_num,"%d %d \n",number1,number2);
    send(sock, both_num, strlen(both_num), 0);
    //print a success messahe
    printf("Hello message sent successfully\n");
    return 0;
}

//valread = read( sock , buffer, 1024);
  //  printf("%s\n",buffer );
   // return 0;
