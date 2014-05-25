/* 
 * File:   Employee.h
 * Author: Diego
 * Outline for employee class
 * Created on May 23, 2014, 11:13 PM
 */

#include <iostream>
#include "Employee.h"

using namespace std;
int Employee::objectCount=1;

Employee::Employee()
{
    objectCount++;
    access=0;
    sales=0;
}
string Employee::getName()
{
    return name;
}
string Employee::getAddress()
{
    return address;
}
string Employee::getCity()
{
    return city;
}
string Employee::getState()
{
    return state;
}
int Employee::getZip()
{
    return zip;
}
int Employee::getEmpID()
{
    return employee_id;
}
bool Employee::checkPassword(string pass)
{
    return pass==password;
}
void Employee::setPassword(string pass)
{
    password=pass;
}
int Employee::accessLevel()
{
    return access;
}
void Employee::setName(string n)
{
    this->name=n;
}
void Employee::setAddress(string address)
{
    this->address=address;
}
void Employee::setCity(string city)
{
    this->city=city;
}
void Employee::setState(string state)
{
    this->state=state;
}
void Employee::setZip(int zip)
{
    this->zip=zip;
}
void Employee::setEmpID(int emp)
{
    this->employee_id=emp;
}
void Employee::resetPassword()
{
    password="start";
}
void Employee::setWage(float w)
{
    wage=w;
}
void Employee::addSale(float sale)
{
    sales+=sale;
}
float Employee::getSales()
{
    return sales;
}
void Employee::setDept(string department)
{
    dept=department;
}
string Employee::getDept()
{
    return dept;
}
