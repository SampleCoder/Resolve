/**
 * Resolver class implementation.
 */

#include "creslv.h"

C_Reslv::C_Reslv(const char *wwwaddr)
{
    memset(&ai_hints, 0, sizeof(ai_hints));
    ai_hints.ai_family = AF_INET;
    ai_hints.ai_socktype = SOCK_STREAM;
    err = getaddrinfo(wwwaddr, NULL, &ai_hints, &pai_head);
    if (err == 0)
        pai_addr = pai_head;
    else {
        pai_head = NULL;
        pai_addr = NULL;
    }
}

C_Reslv::~C_Reslv()
{
    if (pai_head)
        freeaddrinfo(pai_head);
}

int C_Reslv::Err()
{
    return err;
}

const char *C_Reslv::ErrDesc()
{
    return gai_strerror(err);
}

const struct sockaddr_in *C_Reslv::Get()
{
    const struct sockaddr_in *ip_addr = NULL;
    if (pai_addr)
        ip_addr = (const struct sockaddr_in *)pai_addr->ai_addr;
    return ip_addr;
}

void C_Reslv::First()
{
    pai_addr = pai_head;
}

bool C_Reslv::Next()
{
    if (pai_addr)
        pai_addr = pai_addr->ai_next;
    return pai_addr != NULL;
}
