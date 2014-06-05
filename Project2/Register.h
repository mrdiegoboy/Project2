/* 
 * File:   Register.h
 * Author: Diego
 *
 * Created on June 3, 2014, 12:31 AM
 */
#include <iostream>
using namespace std;

#ifndef REGISTER_H
#define	REGISTER_H

class Register
{
private:
    float cash_reg;
    float total_sales;
    float cash;
    int checks;
    float chk_total;
    float change;
public:
    Register();
    friend ostream& operator<<(ostream&, const Register*);
    float getTotalSales();
    float getCash();
    float getCashReg();
    int getChecks();
    float getChange();
    void addTotalSales(float);
    void addCash(float);
    void addCheck(float);
    
    
};

#endif	/* REGISTER_H */