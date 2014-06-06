#include <iostream>
#include "Customer.h"


void Customer::yestoSpam(bool def)
{
    mailinglist=def;
}
bool Customer::wantsSpam()
{
    return mailinglist;
}
void Customer::setEmail(string e)
{
    email=e;
}
string Customer::getEmail()
{
    return email;
}
ostream& operator<<(ostream& os, const Customer& c)
{
    os << c.name << endl << c.address << endl
            << c.city << ", " << c.state << " " << c.zip << endl
            << c.email << " Wants spam: " << c.mailinglist;
    return os;
}
