/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on May 23, 2014, 11:05 PM
 */
#include <iostream>
#include <vector>
#include "Employee.h"
#include "Supervisor.h"
using namespace std;

void Menu();
int getN();
void def(int);
void addEmployee();
void addSupervisor();
/*
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
 
             cout << "Login\n" << endl;
            cout << "Employee ID: ";
            cin >> id;
            cout << "Password: ";
            cin >> pass;*/


    int main(int argv,char *argc[])
    {
	int inN, id;
        string pass;
        do{
            Menu();
            inN=getN();
         switch(inN){
          case 1:    addEmployee();break;
          case 2:    addSupervisor();break;/*
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;*/
          default:   def(inN);}
        }while(inN<8);
        return 1;
    }
    void Menu()
    {
           cout<<"Type 1 for new employee"<<endl;
           cout<<"Type 2 for new supervisor"<<endl;
           cout<<"Type 3 for problem 3"<<endl;
           cout<<"Type 4 for problem 4"<<endl;
           cout<<"Type 5 for problem 5"<<endl;
           cout<<"Type 6 for problem 6"<<endl;
           cout<<"Type 7 for problem 7"<<endl;
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    //Function to add an employee to system
    void addEmployee()
    {
        Employee *emp=new Employee();
        string words;
        int nums;
        float dec;
        cout << "Please enter employee first and last name: " << endl;
        std::cin.sync(); 
        std::cin.get(); 
        getline (cin, words);
        emp->setName(words);
        cout << "Please enter address: " << endl;
        getline (cin, words);
        emp->setAddress(words);
        cout << "Please enter city" << endl;
        cin >> words;
        emp->setCity(words);
        cout << "State: ";
        cin >> words;
        emp->setState(words);
        cout << "Zip: ";
        cin >> nums;
        emp->setZip(nums);
        cout << "Department: (PC or Mobile): ";
        cin >> words;
        emp->setDept(words);
        emp->resetPassword();
        cout << "Wage: ";
        cin >> dec;
        emp->setWage(dec);
        cout << "Employee successfully created\nEmployee ID will"
                "be " << Employee::objectCount;
        emp->setEmpID(Employee::objectCount);
        
    }
    void addSupervisor()
    {
        Supervisor *sup=new Supervisor();
        string words;
        int nums;
        float dec;
        cout << "Please enter supervisor first and last name: " << endl;
        std::cin.sync(); 
        std::cin.get(); 
        getline (cin, words);
        sup->setName(words);
        cout << "Please enter address: " << endl;
        getline (cin, words);
        sup->setAddress(words);
        cout << "Please enter city" << endl;
        cin >> words;
        sup->setCity(words);
        cout << "State: ";
        cin >> words;
        sup->setState(words);
        cout << "Zip: ";
        cin >> nums;
        sup->setZip(nums);
        cout << "Department: (PC or Mobile): ";
        cin >> words;
        sup->setDept(words);
        sup->resetPassword();
        cout << "Wage: ";
        cin >> dec;
        sup->setWage(dec);
        cout << "Employee successfully created\nEmployee ID will"
                "be " << Employee::objectCount;
        sup->setEmpID(Employee::objectCount);
    }
    /*void problem3()
    {
           cout<<"In problem # 3"<<endl<<endl;
    }
    void problem4()
    {
           cout<<"In problem # 4"<<endl<<endl;
    }
    void problem5()
    {
           cout<<"In problem # 5"<<endl<<endl;
    }
    void problem6()
    {
           cout<<"In problem # 6"<<endl<<endl;
    }
    void problem7()
    {
		cout<<"In problem # 7"<<endl<<endl;
    }
    */
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }


