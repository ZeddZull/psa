#ifndef USER_H
#define USER_H
#include <QString>

class User
{
private:
    QString username;
    QString password;

public:
    User(QString name, QString password);
    //User(std::string Username = "", std::string Password = "");

    void setUsername(QString name);
    QString getUsername();
    void setPassword(QString pass);
    QString getPassword();
    bool isEgal(User *user);
};

#endif // USER_H
