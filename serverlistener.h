#ifndef SERVERLISTENER_H
#define SERVERLISTENER_H

#include <QObject>
#include <QTcpServer>

#include "sharedlist.h"
#include "serverthread.h"

namespace PenguinServer
{

/**
 * @brief The ServerListener class
 *        Class represents a Tcp Listenere which manages all incomming
 *         calls
 */
class ServerListener : public QTcpServer
{
    Q_OBJECT
public:

    /**
     * @brief ServerListener
     * @param parent
     */
    explicit ServerListener(QObject *parent = 0);

    void start();

signals:

public slots:

protected:
    void incomingConnection(qintptr handle);

private:
    SharedList * list;
    SqlConnection * database;

};

class Controler: public QThread
{
    Q_OBJECT
public:

    explicit Controler(QObject * parent = 0);
    virtual ~Controler();

    virtual void run();

signals:
    void finish();

};
}
#endif // SERVERLISTENER_H
