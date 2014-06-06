#include "Person.h"
#include <iostream>

using namespace std;

string Person::getName()
{
    return name;
}
string Person::getAddress()
{
    return address;
}
string Person::getCity()
{
    return city;
}
string Person::getState()
{
    return state;
}
int Person::getZip()
{
    return zip;
}
void Person::setName(string n)
{
    this->name=n;
}
void Person::setAddress(string address)
{
    this->address=address;
}
void Person::setCity(string city)
{
    this->city=city;
}
void Person::setState(string state)
{
    this->state=state;
}
void Person::setZip(int zip)
{
    this->zip=zip;
}
