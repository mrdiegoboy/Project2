/* 
 * File:   main.cpp
 * Author: Diego
 *
 * Created on May 23, 2014, 11:05 PM
 */
#include <iostream>
#include <vector>
#include <fstream>
#include "Person.h"
#include "Employee.h"
#include "RetailItem.h"
#include "Register.h"
#include "Customer.h"

using namespace std;

void Menu();
int getN();
void def(int);
void addEmployee(vector<Employee>&);
void addCustomer(vector<Customer>&);
void loadInventory(vector<RetailItem>&);
void loadEmployees(vector<Employee>&);
void viewEmployees(vector<Employee>);
void viewInventory(vector<RetailItem>);
void Sale(vector<RetailItem>&, vector<Employee>&, Register*);
void saveEmployee(vector<Employee>);
void saveInventory(vector<RetailItem>);
void registerTotal(Register *);
void deleteReg(Register *);
void saveCustomer(vector<Customer>);
void receiveItem(vector<RetailItem>&);

    int main(int argv,char *argc[])
    {
        Register *reg= new Register();
        vector<Employee> emps;
        vector<RetailItem> inventory;
        vector<Customer> customer;
        loadEmployees(emps);
        loadInventory(inventory);
	int inN, id;
        string pass;
        do{
            Menu();
            inN=getN();
         switch(inN){
          case 1:    
              addEmployee(emps);
              break;
          case 2:    
              addCustomer(customer);
              break;
          case 3:    
              Sale(inventory,emps,reg);
              break;
          case 4:    
              viewEmployees(emps);
              break;
          case 5:    
              viewInventory(inventory);
              break;
          case 6:    
              registerTotal(reg);
              break;
          case 7:
              receiveItem(inventory);
              break;
          default:   def(inN);}
        }while(inN<8);
        saveEmployee(emps);
        saveInventory(inventory);
        saveCustomer(customer);
        deleteReg(reg);
        return 0;
    }
    void Menu()
    {
           cout<<"\nType 1 for new employee"<<endl;
           cout<<"Type 2 for new Customer"<<endl;
           cout<<"Type 3 to add a sale"<<endl;
           cout<<"Type 4 View Employees"<<endl;
           cout<<"Type 5 View Inventory"<<endl;
           cout<<"Type 6 to Display Register Totals"<<endl;
           cout<<"Type 7 to Receive Inventory"<<endl;
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }
    
    //Function to add an employee to system
    void addEmployee(vector<Employee> &e)
    {
        Employee emp;
        string words;
        int nums;
        float dec;
        cout << "Please enter employee first and last name: " << endl;
        std::cin.sync(); 
        getline (cin, words);
        emp.setName(words);
        cout << "Please enter address: " << endl;
        getline (cin, words);
        emp.setAddress(words);
        cout << "Please enter city" << endl;
        cin >> words;
        emp.setCity(words);
        cout << "State: ";
        cin >> words;
        emp.setState(words);
        cout << "Zip: ";
        cin >> nums;
        emp.setZip(nums);
        cout << "Enter Wage greater than 0: ";
        cin >> dec;
        while(dec<0){
            cout << "Wage must be greater than 0";
            cin >> dec;
        }
        emp.setWage(dec);
        cout << "Employee successfully created\nPlease enter employee ID"
                "to assign ";
        cin >> nums;
        for(int i=0;i<e.size();i++)
        {
            if(e[i].getEmpID()==nums)
            {
                cout << "Employee ID already taken, please re-enter: ";
                cin >> nums;
            }
        }
        emp.setEmpID(nums);
        cout << "Please have employee enter a password " << endl;
        cin >> words;
        emp.setPassword(words);
        e.push_back(emp);
        
    }
    //add a customer to database
    void addCustomer(vector<Customer> &c)
    {
        Customer cust;
        string words;
        char choice;
        int nums;
        float dec;
        cout << "Please enter customer first and last name: " << endl;
        std::cin.sync(); 
        getline (cin, words);
        cust.setName(words);
        cout << "Please enter address: " << endl;
        getline (cin, words);
        cust.setAddress(words);
        cout << "Please enter city" << endl;
        cin >> words;
        cust.setCity(words);
        cout << "State: ";
        cin >> words;
        cust.setState(words);
        cout << "Zip: ";
        cin >> nums;
        cust.setZip(nums);
        cout << "Would customer like to be on our mailing list? (y)es or (n)o";
        cin >> choice;
        switch(choice){
            case 'y':
            case 'Y':
                cust.yestoSpam(true);
                cout << "Please enter customer email address: ";
                cin >> words;
                cust.setEmail(words);
                break;
            case 'n':
            case 'N':
                cust.yestoSpam(false);
                break;
        }
        c.push_back(cust);
    }
    
    //view employee database
    void viewEmployees(vector<Employee> e)
    {
        for(int i=0;i<e.size();i++)
        {
            cout << e[i] << endl;
        }
    }
    
    //view inventory
    void viewInventory(vector<RetailItem> r)
    {
        for(int i=0;i<r.size();i++)
        {
            cout << r[i] << endl;
        }
    }
    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
    
    //load employees from file
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
        int count=0;
        for(int i=0;i<num_employees;i++)
        {
            getline(myfile, line);
            e.setName(line);
            getline(myfile, line);
            e.setAddress(line);
            myfile >> e;
            getline(myfile, line);
            emps.push_back(e);
        }
    }
    
    //load inventory from file
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
    
    //add sale to employee and to register
    void Sale(vector<RetailItem>& r, vector<Employee>& e, Register *reg)
    {
        int sku,emp;
        int menu;
        float amt;
        int go_on=0;
        cout << "Please enter employee ID for sale: ";
        cin >> emp;
        for(int i=0;i<e.size();i++)
        {
            if(e[i].getEmpID()==emp)
            {
                go_on=1;
            }
        }
        if(go_on==1){
        cout << "Please enter the SKU: ";
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
                        cout << "Selling item" << r[i].getDesc() 
                                << "\t" << r[i].getPrice() << endl;
                        cout << "Customer paying cash or check?" << endl;
                        cout << "1 for Cash\n2 for Check: ";
                        cin >> menu;
                        while(menu!= 1 || menu !=2)
                        {
                            cout << "Invalid Choice.\n"
                                    "1 for Cash\n2 for Check: ";
                            cin >> menu;
                        }
                        switch (menu){
                            case 1: 
                                cout << "Enter amount customer paying for cash ";
                                cin >> amt;
                                reg->addCash(r[i].getPrice());
                                cout << "Change due to customer $:"
                                        << amt-r[i].getPrice();
                                break;
                            case 2:
                                cout << "Enter amount on check";
                                cin >> amt;
                                while(amt!=r[i].getPrice())
                                {
                                    cout << "Amount of check must match amount "
                                            << "of total.  Please re-enter amount ";
                                    cin >> amt;
                                }
                                reg->addCheck(r[i].getPrice());
                                cout << "Change due to customer $:"
                                        << amt-r[i].getPrice();
                        }
                    }
                }
            }
        }
        }
        else
            cout << "Employee number not found" << endl;
    }
    
    //save all  new employee and existing employee info to file
    void saveEmployee(vector<Employee> e)
    {
        fstream datafile;
        datafile.open("employee.txt", ios::out);
        if(datafile.fail())
        {
            cout << "Error: Cannot open file" << endl;
        }
        cout << "Saving all employee information...\n";
        for(int i=0;i<e.size();i++)
        {
            datafile << e[i].getName() << endl;
            datafile << e[i].getAddress() << endl;
            datafile << e[i].getCity() << endl;
            datafile << e[i].getState() << endl;
            datafile << e[i].getZip() << endl;
            datafile << e[i].getEmpID() << endl;
            datafile << e[i].getPassword() << endl;
            datafile << e[i].getWage() << endl;
            datafile << e[i].accessLevel() << endl;
        }
    }
    
    //save inventory to files
    void saveInventory(vector<RetailItem> r)
    {
        fstream datafile;
        datafile.open("inventory.txt", ios::out);
        if(datafile.fail())
        {
            cout << "Error: Cannot open file" << endl;
        }
        cout << "Saving all inventory information...\n";
        for(int i=0;i<r.size();i++)
        {
            datafile << r[i].getSKU() << " " << r[i].getDesc() << " "
                    << r[i].getPrice() << " " << r[i].getAOH() << endl;
        }
    }
    
    //output all register information
    void registerTotal(Register *r)
    {
        cout << r;
    }
    
    //delete register pointer
    void deleteReg(Register *r)
    {
        delete r;
    }
    
    //save all customer information to a file
    void saveCustomer(vector<Customer> c)
    {
        fstream datafile;
        datafile.open("customer.txt", ios::app);
        if(datafile.fail())
        {
            cout << "Error: Cannot open file" << endl;
        }
        cout << "Saving all customer information...\n";
        for(int i=0;i<c.size();i++)
        {
            datafile << c[i].getName() << endl;
            datafile << c[i].getAddress() << endl;
            datafile << c[i].getCity() << endl;
            datafile << c[i].getState() << endl;
            datafile << c[i].getZip() << endl;
            datafile << c[i].getEmail() << endl;
            datafile << c[i].wantsSpam() << endl;
        }
    }
    void receiveItem(vector<RetailItem> &r)
    {
        int num;
        int qty;
        int temp;
        cout << "Please enter sku you would like to receive: ";
        cin >> num;
        for(int i=0;i<r.size();i++)
        {
            if(r[i].getSKU()==num)
            {
                cout << "How many items are you receiving of "
                        << r[i].getDesc() << " :";
                cin >> qty;
                temp=r[i].getAOH();
                for(int j=0;j<qty;j++)
                    r[i].receive();
                cout << "Available on Hand before: " << temp << endl;
                cout << "Available on Hand after: " << r[i].getAOH(); 
            }
        }
        
    }



