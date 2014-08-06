#include "serverlistener.h"

namespace PenguinServer
{

ServerListener::ServerListener(QObject *parent) :
    QTcpServer(parent), list(0)
{

}

void ServerListener::start()
{
    list = new SharedList;
    database = new SqlConnection;
    if(!this->listen(QHostAddress::Any, 27173))
    {

    }
}



void ServerListener::incomingConnection(qintptr handle)
{
    ServerThread * thread = new ServerThread(handle, list, database);

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();

}

}//namespace PenguinServer
