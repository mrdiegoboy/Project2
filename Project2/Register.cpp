#include "Register.h"

#include <iostream>

using namespace std;

Register::Register()
{
    cash=100;
    total_sales=0;
    checks=0;
}
float Register::getTotalSales()
{
    return total_sales;
}
float Register::getCash()
{
    return cash;
}
float Register::getCashReg()
{
    return cash_reg;
}
int Register::getChecks()
{
    return checks;
}
float Register::getChange()
{
    return change;
}
void Register::addTotalSales(float s)
{
    total_sales+=s;
}
void Register::addCash(float c)
{
    cash+=c;
    total_sales+=c;
    
}
void Register::addCheck(float c)
{
    chk_total+=c;
    checks++;
    total_sales+=c;
}
ostream& operator<<(ostream& os, const Register* r)
{
    os << "Total sales: $" << r->total_sales << endl
            << "Cash Sales: $" << r->cash-100 << endl
            << "Check Sales $" << r->chk_total
            << " Total Checks: " << r->checks << endl
            << "Total cash in Register: $" << r->cash
            << endl;
    return os;
}