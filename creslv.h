/**
 * Resolver class header.
*/
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <vector>

class C_Reslv {
private:
    int err;
    struct addrinfo ai_hints;
    struct addrinfo *pai_head, *pai_addr;
public:
    C_Reslv(const char *wwwaddr);
    ~C_Reslv();
    int Err();
    const char *ErrDesc();
    struct sockaddr_in Get();
    void First();
    bool Next();
    std::vector<struct sockaddr_in> list;
    std::vector<struct sockaddr_in>::iterator curelem;
};
