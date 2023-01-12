#ifndef AUTHORISEDUSER_H
#define AUTHORISEDUSER_H

#include <list>
#include "user.h"

class AuthorisedUser
{
public:
    AuthorisedUser();
    std::list<User> userList;
    std::list<User>::iterator it = userList.begin();
    bool isAuthorise(User *user);
};

#endif // AUTHORISEDUSER_H
