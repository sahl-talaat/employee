#include<iostream>
#include"employee.h"

#ifndef SALES
#define SALES
class Sales : public sahl::Employee
{
    private:
        float gross_sales = 0.0;
        float commission_rate = 0.0;
    public:
        Sales(){}
        Sales(int id, std::string name, float salary, int age,float gross_sales, float commission_rate):Employee(id,name,salary,age),gross_sales(gross_sales),commission_rate(commission_rate)
        {}

        ~Sales(){}

        /* void set_commission_rate(float commission_rate)
        {
            this->commission_rate = commission_rate;
        }

        void set_gross_sales(float gross_sale)
        {
            this->gross_sales = gross_sale;
        } */

        float get_totalSalary() // pure virtual function implementation
        {
            return salary + (gross_sales * commission_rate);
        }
};
#endif