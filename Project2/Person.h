/* 
 * File:   Person.h
 * Author: Diego
 *
 * Created on June 5, 2014, 8:21 PM
 */

#ifndef PERSON_H
#define	PERSON_H
#include <iostream>

using namespace std;

class Person{
protected:
    string name;
    string address;
    string city;
    string state;
    int zip;
public:
    string getName();
    string getAddress();
    string getCity();
    string getState();
    int getZip();
    void setName(string);
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(int);
};


#endif	/* PERSON_H */

