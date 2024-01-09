#include<iostream>
#include"employee.h"

#ifndef ENGINEER
#define ENGINEER
class Engineer : public sahl::Employee
{
private:
    std::string speciality{};
    int experience{};
    float overtime_hours{};
    float overtime_hours_rate{};
public:
    Engineer(){}
    Engineer(int id,const std::string& name,float salary,int age, std::string speciality, int experience, int overtime_hours, float overtime_hours_rate):Employee(id,name,salary,age),speciality(speciality),experience(experience),overtime_hours(overtime_hours),overtime_hours_rate(overtime_hours_rate)
    {}
    ~Engineer(){}

    void set_overtime_hours(int overtime_hours)
    {
        this->overtime_hours = overtime_hours;
    }
    void set_overtime_hours_rate(float overtime_hours_rate)
    {
        this->overtime_hours_rate = overtime_hours_rate;
    }

    float get_totalSalary()
    {
        return salary + (overtime_hours * overtime_hours_rate);
    }


    int get_overtime_hours()
    {
        return overtime_hours;
    }

    float get_overtime_hours_rate()
    {
        return overtime_hours_rate;
    } 
};
#endif 
 