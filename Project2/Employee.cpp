/* 
 * File:   Employee.h
 * Author: Diego
 * Outline for employee class
 * Created on May 23, 2014, 11:13 PM
 */

#include <iostream>
#include "Employee.h"
#include <ctime>

using namespace std;
int Employee::objectCount=0;

Employee::Employee()
{
    objectCount++;
    access=0;
    sales=0;
}
istream& operator >> (istream& in, Employee &e)
{
    in >> e.city;
    in >> e.state;
    in >> e.zip;
    in >> e.employee_id;
    in >> e.password;
    in >> e.wage;
    in >> e.access;
    return in;
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
ostream& operator<<(ostream& os, const Employee& e)
{
    os << e.name << endl << e.address << endl
            << e.city << ", " << e.state << " " << e.zip << endl
            << "Total Sales: $" << e.sales;
    return os;
}
string Employee::getPassword()
{
    return password;
}
float Employee::getWage()
{
    return wage;
}
