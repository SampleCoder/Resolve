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
    if (err == 0) {
        pai_addr = pai_head;
        for (;pai_addr; pai_addr = pai_addr->ai_next) {
			list.push_back(*(const struct sockaddr_in *)pai_addr->ai_addr);
		}
		curelem = list.begin();
	}
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

struct sockaddr_in C_Reslv::Get()
{
	struct sockaddr_in addr { 0 };
	if (!list.empty())
		addr = *curelem;
    return addr;
}

void C_Reslv::First()
{
	if (!list.empty())
		curelem = list.begin();
}

bool C_Reslv::Next()
{
	curelem++;
    return curelem != list.end();
}
