#include "sharedlist.h"

namespace PenguinServer
{

SharedList::SharedList(): QObject(), mutex()
{
    c = new ClientsManager(this);
    c->start();
}

bool SharedList::addClient(ConnectedClient * cli)
{
    mutex.lock();
    QString q = cli->getName();
    if(clients.contains(q))
    {
        mutex.unlock();
        return false;
    }
    clients[q] = cli;
    mutex.unlock();
    return true;
}

bool SharedList::removeClient(const QString & tR)
{
    mutex.lock();
    int k = clients.remove(tR);
    mutex.unlock();
    if(k==0) return false;
    return true;
}

void SharedList::callAllClients()
{
    mutex.lock();
//    QList<QString> toSent = clients.keys();
//    QMap<QString, ConnectedClient*>::Iterator it;
//    for(it = clients.begin(); it!= clients.end(); it++)
//    {
//        ConnectedClient * c = *it;
//        emit c->sendUpdatedList(toSent);
//    }
    qDebug() << "Sending all data";
    auto toSent = clients.keys();

    auto it = clients.begin();

    for(; it != clients.end(); it++)
    {
        ConnectedClient * c = *it;
        c->sendList(toSent);
    }

    mutex.unlock();
}

void SharedList::callClient(const QString &destName, const QString &srcName, qint16 type)
{
    mutex.lock();
    if(!clients.contains(destName))
    {
        mutex.unlock();
        return;
    }
    ConnectedClient* c = clients[destName];
    c->callRequest(type, clients[srcName]);
    mutex.unlock();

}


}//namespace PenguinServer
