#include<iostream>

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
    //protected:
    private:
        int id;
        std::string name;
        std::string position;
        int age;
        float salary;
    public:
        Employee():name("unknown"),age(0),position("unknown"),id(0),salary(0.0) // defualt ctor overloading ctor
        {}
        Employee(int id,std::string name,std::string position,float salary,int age)
        {
            this->id = id;
            this->name = name;
            this->age = age;
            this->position = position;
            this->salary = salary;
        }
        // geters
        int get_id()const{return id;}
        std::string get_name() const { return name; }
        std::string get_position() const { return position; }
        float get_salary() const { return salary; }
        int get_age() const { return age; }


        // seters
        void set_name(const std::string& new_name) { name = new_name; }
        void set_age(const int& new_age) { age = new_age; }
        void set_position(const std::string& new_position) { position = new_position; }
        void set_salary(const float& new_salary) { salary = new_salary; }
        
};

#endif