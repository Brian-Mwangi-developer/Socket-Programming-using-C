#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    //server_fd and new_socket are file descriptors for the sockets.
    int server_fd, new_socket;
    //address is a struct that holds the server address and port,
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    //buffer is an array to hold incoming data from the client
    int num1,num2,sum;
    char buffer[1024] = {0};
   // const char *hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Assigning IP and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the IP and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
//backlog value of 3, which means that the server can handle up to 3 pending connections.
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accepting incoming connection
    //accept creates a new socket 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Reading data from client
    int valread = read(new_socket, buffer, 1024);
    //sscanf is used to read input from a string,
    // a buffer (temporary storage that stores input/output commands), or a character array
    sscanf(buffer,"%d %d",&num1,&num2);
    printf("Integers from the client are:%d and %d \n",num1,num2);

    //calcualting sum of the integers
    sum =num1 + num2;

    //print the sum 
    printf("Sum of integers from the client: %d \n",sum);
    printf("The message was received successfully ");
    return 0;
}

// Sending data to client
    //char sum_send[10];
    //sprintf(sum_send,"%d",sum);
    //send(new_socket, sum_send, strlen(sum_send), 0);