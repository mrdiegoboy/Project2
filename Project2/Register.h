/* 
 * File:   Register.h
 * Author: Diego
 *
 * Created on June 3, 2014, 12:31 AM
 */

#ifndef REGISTER_H
#define	REGISTER_H

class Register
{
private:
    float cash_paid;
    float total_sales;
    float cash;
    int checks;
    float chk_total;
    float change;
public:
    Register();
    float getTotalSales();
    float getCashSales();
    float getCashReg();
    int getChecks();
    float getChange();
    void addTotalSales(float);
    void addCash(float);
    void addCheck(float);
    
    
};

#endif	/* REGISTER_H */