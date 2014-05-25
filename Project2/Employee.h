/* 
 * File:   Employee.h
 * Author: Diego
 * Outline for employee class
 * Created on May 23, 2014, 11:13 PM
 */
#include <iostream>

using namespace std;

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee
{
protected:
    string name;
    string address;
    string city;
    string state;
    int zip;
    int employee_id;
    string password;
    float wage;
    int access;
    float sales;
    string dept;
public:
    static int objectCount;
    Employee();
    string getName();
    string getAddress();
    string getCity();
    string getState();
    int getZip();
    int getEmpID();
    bool checkPassword(string);
    void setPassword(string);
    int accessLevel();
    void setName(string);
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(int);
    void setEmpID(int);
    void setWage(float);
    void resetPassword();
    void addSale(float);
    float getSales();
    void setDept(string);
    string getDept();
};

#endif	/* EMPLOYEE_H */

