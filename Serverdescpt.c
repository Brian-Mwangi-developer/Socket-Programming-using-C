#include <sys/socket.h>
//create a server socket
int socket (int AF_INET, int SOCK_STREAM, int TCP);
//create a connect function
int connect(int sockfd,const struct sockaddr*serveraddr,socklen_t addrlen);
//create a bind function
int bind(int sockfd, const struct sockaddr * myaddr, socklen_t addrlen);
//create a listen function
int listen(int sockfd, int backlog);
//create the accept function
int accept(int sockfd, struct sockaddr * cliaddr, socklen_t addrlen);