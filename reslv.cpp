/**
    Test dns resolving module, more CPP-like.
*/
#include <iostream>
#include "creslv.h"

void print_usage()
{
    std::cerr << "Usage: reslv <www-address>" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        C_Reslv resolver(argv[1]);
        if (resolver.Err() == 0) {
            const struct sockaddr_in *paddr;
            char buf[INET_ADDRSTRLEN];
            do {
                paddr = resolver.Get();
                if (inet_ntop(AF_INET, (const void *)&paddr->sin_addr, buf, sizeof(buf)))
                    std::cout << "[IP] => " << buf << std::endl;
            } while (resolver.Next());
        }
        else {
            std::cerr << resolver.ErrDesc() << std::endl;
        }
    }
    else {
        print_usage();
    }
    return 0;
}
