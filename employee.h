#include<iostream>

#ifndef EMPLOYEE
#define EMPLOYEE


namespace sahl
{
class Employee
{
    protected:
        int id{};
        int age{};
        std::string name{};
        float salary;
    public: 
        Employee() // defualt ctor overloading ctor
        {}
        Employee(int id,const std::string& name,float salary,int age):id(id),name(name),salary(salary),age(age)
        {}
        // geters
        int get_id()const{return id;}
        std::string get_name() const { return name; }
        int get_age() const { return age; }


        // seters
        void set_name(const std::string& new_name) { name = new_name; }
        void set_age(const int& new_age) { 
            if(age<18&&age>=60)
            return;
            age = new_age;
            
             }
        
};
} // namespace sahl
#endif