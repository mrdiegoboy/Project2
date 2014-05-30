/* 
 * File:   RetailItem.h
 * Author: Diego
 * implementation for retailitem
 * Created on May 28, 2014, 1:00 AM
 */

#include <iostream>
#include "RetailItem.h"
using namespace std;
int RetailItem::objectCount=0;
istream& operator >> (istream& in, RetailItem* r)
{
    in >> r->SKU;
    in >> r->description;
    in >> r->price;
    in >> r->AOH;
    return in;
}
RetailItem::RetailItem()
{
    objectCount++;
}
void RetailItem::setSKU(int s)
{
    SKU=s;
}
void RetailItem::setDesc(string s)
{
    description=s;
}
void RetailItem::setPrice(float p)
{
    price=p;
}
int RetailItem::getSKU()
{
    return SKU;
}
string RetailItem::getDesc()
{
    return description;
}
float RetailItem::getPrice()
{
    return price;
}
int RetailItem::getAOH()
{
    return AOH;
}
void RetailItem::setAOH(int a)
{
    AOH=a;
}
void RetailItem::sold()
{
    AOH--;
}


