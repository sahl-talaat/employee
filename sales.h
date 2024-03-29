#include<iostream>
#include"employee.h"

#ifndef SALES
#define SALES
class Sales : public Employee
{
    private:
        float gross_sales = 0.0;
        float commission_rate = 0.0;
    public:
        Sales(){}
        Sales(int id, std::string name,  int age,float salary,float gross_sales, float commission_rate)
        :Employee(id,name,age,salary),gross_sales(gross_sales),commission_rate(commission_rate) {}

        ~Sales(){}

        float get_gross() const { return gross_sales; }
        float get_commition() const { return commission_rate; }

        void display() const override{
        Employee::display();
        std::cout << "Gross Sales: " << gross_sales << ", Commission Rate: " << commission_rate <<", Total_Salary: "<< get_totalSalary() << std::endl;
        }

        float get_totalSalary() const override  {
            return salary + (gross_sales * commission_rate);
        }
        /* void save_to_file(std::ofstream& file) const { 
        file << id << ' ' << name << ' ' << age << ' ' << salary << ' ' << gross_sales << ' '
             << commission_rate << '\n';
    } */
};
#endif