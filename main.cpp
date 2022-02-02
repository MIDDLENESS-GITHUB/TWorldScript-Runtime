#include "tworld.h"
#include "server.h"

int main() {
    TWorldStarter starter;
    starter.test();
    Server server;
    server.listen();
    return 0;
}