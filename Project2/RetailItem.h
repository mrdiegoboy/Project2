/* 
 * File:   RetailItem.h
 * Author: Diego
 * blueprint for retailitem
 * Created on May 28, 2014, 1:00 AM
 */
#include <iostream>

using namespace std;

#ifndef RETAILITEM_H
#define	RETAILITEM_H

class RetailItem
{
private:
    int SKU;
    string description;
    float price;
    int AOH;
public:
    friend istream& operator >> (istream&, RetailItem*);
    static int objectCount;
    RetailItem();
    void setSKU(int);
    void setDesc(string);
    void setPrice(float);
    void setAOH(int);
    int getSKU();
    string getDesc();
    float getPrice();
    int getAOH();
    void sold();
};



#endif	/* RETAILITEM_H */

