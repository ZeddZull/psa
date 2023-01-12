#include "user.h"

User::User(QString name, QString password)
{
    setUsername(name);
    setPassword(password);
}

bool User::isEgal(User *user){
    if (user->getUsername() == username && user->getPassword() == password)
        return true;
    else
        return false;
}

void User::setUsername(QString name)
{
    username = name;
}

void User::setPassword(QString pass)
{
    password = pass;
}

QString User::getUsername()
{
    return username;
}

QString User::getPassword()
{
    return password;
}
