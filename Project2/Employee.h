/* 
 * File:   Employee.h
 * Author: Diego
 * Outline for employee class
 * Created on May 23, 2014, 11:13 PM
 */
#include <iostream>
#include "Person.h"

using namespace std;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee : public Person
{
protected:
    int employee_id;
    string password;
    float wage;
    int access;
    float sales;
public:
    friend istream& operator >> (istream&, Employee&);
    friend ostream& operator<<(ostream&, const Employee&);
    static int objectCount;
    Employee();
    int getEmpID();
    bool checkPassword(string);
    void setPassword(string);
    int accessLevel();
    void setEmpID(int);
    void setWage(float);
    void resetPassword();
    void addSale(float);
    float getSales();
    void printEmployee();
    string getPassword();
    float getWage();
    void clock_on();
    void clock_off();
    void lunch_on();
    void lunch_off();
};

#endif	/* EMPLOYEE_H */

