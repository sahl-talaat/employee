#include<iostream>
#include<fstream>
#include<vector>
#include"employee.h"

#ifndef ENGINEER
#define ENGINEER
class Engineer : public Employee
{
private:
    std::string speciality{};
    int experience{};
    float overtime_hours{};
    float overtime_hours_rate{};
public:
    Engineer(){}
    Engineer(int id, std::string name,int age,float salary, std::string speciality, int experience, int overtime_hours, float overtime_hours_rate)
    :Employee(id,name,age,salary),speciality(speciality),experience(experience),overtime_hours(overtime_hours),overtime_hours_rate(overtime_hours_rate)
    {}
    ~Engineer(){}

    void display() const override {
        Employee::display();
        std::cout << "Speciality: " << speciality << ", Experience: " << experience << ", Overtime Hours: "
                  << overtime_hours << ", Overtime Hour Rate: " << overtime_hours_rate << std::endl;
    }

    float get_totalSalary(){
        return salary + (overtime_hours * overtime_hours_rate);
    }


    void save_to_file(std::ofstream& file) const{
        file <<id<<' '<<name<<' '<<age<<' '<<salary<<' '<< speciality<<' '<<experience<<
        ' '<<overtime_hours<<' '<<overtime_hours_rate<<'\n';
    }

};
#endif 
 