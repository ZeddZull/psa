#include "authoriseduser.h"

AuthorisedUser::AuthorisedUser(){
    User user1 = User("User1","1234");
    User user2 = User("User2","4567");
    User user3 = User("User3","891011");
    userList.insert(it, user1);
    userList.insert(++it, user2);
    userList.insert(++it, user3);
}

bool AuthorisedUser::isAuthorise(User *user){
    for (std::list<User>::iterator it1=userList.begin(); it1!=userList.end(); ++it1)
    {
        if(it1->isEgal(user))
            {return true;}
    }
       return false;
}
