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
float Register::getCashSales()
{
    return cash-100;
}
float Register::getCashReg()
{
    return cash;
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
}
void Register::addCheck(float c)
{
    chk_total+=c;
    checks++;
}
