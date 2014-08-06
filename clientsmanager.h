#ifndef CLIENTSMANAGER_H
#define CLIENTSMANAGER_H

#include <QThread>
#include <QList>

#include "sharedlist.h"


namespace PenguinServer
{

class SharedList; //forward declaration


/**
 * @brief The ClientsManager class
 *        This class represents manager of all clients.
 *        Curently this manager is responsible for resending the Clients list, but for
 *        the future will be used to manage all other issues checking state of communication
 *        and other
 */
class ClientsManager : public QThread
{
    Q_OBJECT
public:

    /**
       * @brief ClientsManager constructor
       * @param l The shared list to work with
       * @param parent - The parent of object
       */
    ClientsManager(SharedList * l, QObject * parent = 0):
        QThread(parent), list(l) {}


    /**
     * @brief run abstract metod inhered from QThread
     *  runs the loop which emits the data send signal.
     */
    void run();

    /**
     * @brief setList
     * @param l
     */
    void setList(SharedList * l);



private:
    SharedList * list;
};

}// namespace Penguin server

#endif // CLIENTSMANAGER_H
