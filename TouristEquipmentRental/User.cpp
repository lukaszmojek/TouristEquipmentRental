#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include "User.h"
//#include "UserType.h"
#include "Reservation.h"
#include "StringOperations.h"

User::User(string id, string firstName, string lastname, string email, string password, string activated)
{
    _id = id;
    _firstName = firstName;
    _lastName = lastname;
    _email = email;
    //TODO: add hashing
    _password = password;
    _activated = (activated == "1");
    _type = (id[0] == 'U') ? "Standard" : "Administrator";
}

string User::Id()
{
    return _id;
}

string User::FirstName()
{
    return _firstName;
}

string User::LastName()
{
    return _lastName;
}

string User:: Email()
{
    return _email;
}

string User::Password()
{
    return _password;
}

bool User::Activated()
{
    return _activated;
}

bool User::ChangePassword(string oldPassword, string newPassword)
{
    //TODO: add hashing
    if (oldPassword == _password)
    {
        //TODO: log password change
        _password = newPassword;
        return true;
    }

    return false;
}

void User::AssignReservationToUser(Reservation reservation)
{
    _reservations.push_back(reservation);
}

string User::Serialize(char separator)
{
    stringstream user;

    user << _id << separator
         << _firstName << separator
         << _lastName << separator
         << _email << separator
         << _password << separator
         << _activated;

    return user.str();
}

User User::Deserialize(string serializedData, char separator)
{
    auto userDetails = StringOperations::Split(serializedData, separator);

    auto user = * new User(
            userDetails[0],
            userDetails[1],
            userDetails[2],
            userDetails[3],
            userDetails[4],
            userDetails[5]);

    return user;
}


