/* 
 * File:   Supervisor.h
 * Author: Diego
 *Blueprint for supervisor
 * Created on May 23, 2014, 11:49 PM
 */

#include <iostream>
#include "Employee.h"

using namespace std;

#ifndef SUPERVISOR_H
#define	SUPERVISOR_H

class Supervisor : public Employee
{
private:
    double bonus;
public:
    Supervisor();
};

#endif	/* SUPERVISOR_H */

