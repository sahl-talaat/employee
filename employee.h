#include<iostream>

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
    protected:
        int id{};
        int age{};
        std::string name{};
        float salary{};
    public: 
        Employee() // defualt ctor overloading ctor
        {}
        Employee(int id, std::string name,int age,float salary):id(id),name(name),salary(salary),age(age)
        {}
        virtual ~Employee() = default;  // Virtual destructor for polymorphism
        // geters
        int get_id()const{return id;}
        std::string get_name() const { return name; }
        int get_age() const { return age; }
        virtual void display() const {
            std::cout<<"ID: "<<id<<", Name: "<<name<<", Age"<<age<<", Salary"<<", ";
        }
        virtual float get_totalSalary() = 0;
        
};
#endif