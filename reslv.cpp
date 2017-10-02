#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>

int main(int argc, char *argv[])
{
    struct addrinfo *paddr, *head;
    struct addrinfo addr_req;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <address>.\n", argv[0]);
        return 1;
    }
    // std::cout << "Resolving " << argv[1] << std::endl;
    memset(&addr_req, 0, sizeof(addr_req));
    addr_req.ai_family = AF_INET;
    addr_req.ai_socktype = SOCK_STREAM;
    char ip[INET_ADDRSTRLEN];
    struct sockaddr_in *sin = NULL;
    int r = 0;
    r = getaddrinfo(argv[1], NULL, &addr_req, &head);
    if (r == 0) {
        for (paddr = head; paddr; paddr = paddr->ai_next) {
            if (r == 0) {
                sin = (struct sockaddr_in *)paddr->ai_addr;
                if (inet_ntop(AF_INET, &sin->sin_addr, ip, sizeof(ip)))
                    std::cout << ip << std::endl;
                else
                    perror("inet_ntop()");
            }
        }
        freeaddrinfo(head);
    }
    else
        std::cerr << gai_strerror(r) << std::endl;
    return 0;
}
