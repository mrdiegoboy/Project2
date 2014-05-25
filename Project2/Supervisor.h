/* 
 * File:   Supervisor.h
 * Author: Diego
 *Blueprint for supervisor inherits from employee
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
    float bonus;
    float budget;
public:
    Supervisor();
    void setBonus(float);
    void setBudget(float);
    void getBonus();
    void getBudget();
};

#endif	/* SUPERVISOR_H */

