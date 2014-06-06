/* 
 * File:   Customer.h
 * Author: Diego
 *
 * Created on June 5, 2014, 9:28 PM
 */
#include <iostream>
#include "Person.h"
using namespace std;

#ifndef CUSTOMER_H
#define	CUSTOMER_H

class Customer : public Person
{
private:
        bool mailinglist;
        string email;
public:
    friend ostream& operator<<(ostream&, const Customer&);
    void yestoSpam(bool);
    bool wantsSpam();
    void setEmail(string);
    string getEmail();
};

#endif	/* CUSTOMER_H */

