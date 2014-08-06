#ifndef DATABASE_H
#define DATABASE_H


#include <sqlite3.h>
#include <QMutex>
#include <QString>

#define PREPARE_INSERT_STATEMENT 1
#define PREPARE_SELECT_USER_STATEMENT 2

namespace PenguinServer
{
char * getAscii85(const char * data, size_t len);

char * getPlainfrom85(const char * data, int len);

class SqlConnection
{

    void prepareStatement(sqlite3_stmt ** stmt, int dataType);

public:

    class ContainedData;
    class SqlException;

    SqlConnection();


    ContainedData getUserByName(const std::string & username);

    bool insertUser(const std::string &name, const std::string &password, const std::string &salt);

    bool existsUser(const std::string &name);


    class ContainedData
    {
        ContainedData() { }
    public:

        ContainedData(const char name[20],const char pass[20]);

        int getID() const;

        const QString & getName() const;

        const QString & getPass() const;

        const QString & getSalt() const;

        friend class SqlConnection;

    private:

        int id;
        QString  name;
        QString  password;
        QString  salt;
    };

    class SqlException: public std::exception
    {
        std::string message;

    public:

        SqlException(std::string message): message(message)
        {
        }


        virtual ~SqlException() throw () {}

        virtual const char * what() const throw()
        {
            return message.c_str();
        }
    };


private:

    QMutex mutex;

    sqlite3 * connection;


};

}


#endif // SQLCONNECTION_H
