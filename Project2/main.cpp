/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on May 23, 2014, 11:05 PM
 */
#include <iostream>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "Supervisor.h"
#include "RetailItem.h"

using namespace std;

void Menu();
int getN();
void def(int);
void addEmployee();
void addSupervisor();
void loadInventory(vector<RetailItem>&);
void loadEmployees(vector<Employee>&);
void viewEmployees(vector<Employee>);
void viewInventory(vector<RetailItem>);
void Sale(vector<RetailItem>&, vector<Employee>&);
/*
void problem6();
void problem7();
 
             cout << "Login\n" << endl;
            cout << "Employee ID: ";
            cin >> id;
            cout << "Password: ";
            cin >> pass;*/


    int main(int argv,char *argc[])
    {
        vector<Employee> emps;
        vector<RetailItem> inventory;
        loadEmployees(emps);
        loadInventory(inventory);
	int inN, id;
        string pass;
        do{
            Menu();
            inN=getN();
         switch(inN){
          case 1:    addEmployee();break;
          case 2:    addSupervisor();break;
          case 3:    Sale(inventory,emps);break;
          case 4:    viewEmployees(emps);break;
          case 5:    viewInventory(inventory);break;
          case 6:    ;break;
          case 7:    ;break;
          default:   def(inN);}
        }while(inN<8);
        return 1;
    }
    void Menu()
    {
           cout<<"\nType 1 for new employee"<<endl;
           cout<<"Type 2 for new supervisor"<<endl;
           cout<<"Type 3 to add a sale"<<endl;
           cout<<"Type 4 View Employees"<<endl;
           cout<<"Type 5 View Inventory"<<endl;
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
        sup->resetPassword();
        cout << "Wage: ";
        cin >> dec;
        sup->setWage(dec);
        sup->setEmpID(Employee::objectCount);
    }
    
    void viewEmployees(vector<Employee> e)
    {
        for(int i=0;i<e.size();i++)
        {
            cout << e[i];
        }
    }
    void viewInventory(vector<RetailItem> r)
    {
        for(int i=0;i<r.size();i++)
        {
            cout << r[i] << endl;
        }
    }/*
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
    void loadEmployees(vector<Employee> &emps)
    {
        int num_lines=0;
        int num_employees;
        string line;
        ifstream myfile("employee.txt");
        if(myfile.fail())
        {
            cout << "Error opening the file\n";
        }
        while(getline(myfile, line))
            ++num_lines;
        num_employees=num_lines/9;
        myfile.close();
        myfile.open("employee.txt");
        Employee e;
        cout << num_employees << "NUM EMPLOYEES";
        for(int i=0;i<num_employees;i++)
        {
            getline(myfile, line);
            e.setName(line);
            getline(myfile, line);
            e.setAddress(line);
            while (myfile >> e)
    
            emps.push_back(e);
        }
    }
    void loadInventory(vector<RetailItem> &item)
    {
        int num_lines=0;
        string line;
        ifstream myfile("inventory.txt");
        if(myfile.fail())
        {
            cout << "Error opening the file\n";
        }
        while(getline(myfile, line))
            ++num_lines;
        myfile.close();
        myfile.open("inventory.txt");
        RetailItem r;
        for(int i=0;i<num_lines;i++){
            while(myfile >> r)

            item.push_back(r);
        }
   
        myfile.close();
    }
    void Sale(vector<RetailItem>& r, vector<Employee>& e)
    {
        int sku,emp;
        cout << "Please enter employee ID for sale";
        cin >> emp;
        cout << "Please enter the SKU";
        cin >> sku;
        for(int i=0;i<r.size();i++)
        {
            if(r[i].getSKU()==sku)
            {
                for(int i=0;i<e.size();i++)
                {
                    if (e[i].getEmpID()==emp){
                        e[i].addSale(r[i].getPrice());
                        r[i].sold();
                    }
                }
            }
        }
    }



