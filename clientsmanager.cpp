#include "clientsmanager.h"

namespace PenguinServer
{

void ClientsManager::run()
{
    bool quit = false;
    while(!quit)
    {
        list->callAllClients();
        sleep(30);
    }
}

void ClientsManager::setList(SharedList * l)
{
    list = l;
}

}
