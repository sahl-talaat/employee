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
        Employee(){}
        Employee(int id, std::string name,int age,float salary)
        :id(id),name(name),salary(salary),age(age) {}
        virtual ~Employee() = default;  // Virtual destructor for polymorphism
        // geters
        int get_id()const{return id;}
        std::string get_name() const { return name; }
        int get_age() const { return age; }
        float get_salary() const { return salary; }
        virtual void display() const {
            std::cout<<"ID: "<<id<<", Name: "<<name<<", Age: "<<age<<", ";
        }
        void set_name(std::string new_name){
            this->name = new_name;
        }
        /* 
        virtual void save_to_file(std::ofstream& file) const{
        file <<id<<' '<<name<<' '<<age<<' '<<salary<<'\n';
        } */
        virtual float get_totalSalary() const = 0;
        
};
#endif