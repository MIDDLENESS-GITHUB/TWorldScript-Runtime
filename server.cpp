#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 4000

#include "server.h"

void Server::listen() {
    std::cout << "Starting server" << std::endl;
    struct sockaddr_in sockAddr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    int options = 1;
    int sockAddrSize = sizeof(sockAddr);

    int sockServer = socket(AF_INET, SOCK_STREAM, 0);

    setsockopt(sockServer, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &options, sizeof(options));

    if (sockServer == -1) std::cout << "Can not create server error status=" << sockServer << std::endl;
}

