
#include<iostream>
//#include<sqlite_orm.h>
#include"engineer.h"
#include"sales.h"

#ifndef FORUSER
#define FORUSER
namespace forUser{
    int id{}, age{}, overtime_hours{}, experience{};
    std::string name{}, speciality{};
    float  overtime_hour_rate{}, salary{},gross_sales{}, commission_rate{};
int employee_type_list(){
    int employeeType;
    std::cout << "Enter type of employee (1 - Engineer, 2 - Sales): ";
    std::cin >> employeeType;
    return employeeType;
}
int main_list(){
    int choice{};
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Add new employee" << std::endl;
    std::cout << "2. Display all employees" << std::endl;
    std::cout << "3. Display all engineers" << std::endl;
    std::cout << "4. Display all sales" << std::endl;
    std::cout << "5. Update name foe engineer" << std::endl;
    std::cout << "6. Update name for sale" << std::endl;
    std::cout << "7. Delete an engineer by id" << std::endl;
    std::cout << "8. Delete an sale by id" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}
 Engineer add_engineer()
{
    std::cout << "Enter Engineer details:" << std::endl;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << " Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Salary: ";
    std::cin >> salary;
    std::cout << "Speciality: ";
    std::cin >> speciality;
    std::cout << "Experience: ";
    std::cin >> experience;
    std::cout << "Overtime Hours: ";
    std::cin >> overtime_hours;
    std::cout << "Overtime Hour Rate: ";
    std::cin >> overtime_hour_rate;
    Engineer eng(id,name,age,salary,speciality,experience,overtime_hours,overtime_hour_rate);
    return eng;                
}

Sales add_sale()
{
    std::cout << "Enter Salesperson details:" << std::endl;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Salary: ";
    std::cin >> salary;
    std::cout << "Gross: ";
    std::cin >> gross_sales;
    std::cout << "Commission: ";
    std::cin >> commission_rate;
    Sales sale(id,name,age,salary,gross_sales,commission_rate);
    return sale;
}    

int take_id(){
    int id;
    std::cout << "Enter employee ID to update: ";
    std::cin >> id;
    return id;
}
std::string take_new_name(){
    std::string new_name;
    std::cout << "Enter new name: ";
    std::cin >> new_name;
    return new_name;
}

// Create or upgrade tables
/* auto storage_access() {
    Employee employee;
    using namespace sqlite_orm;
    auto storage = sqlite_orm::make_storage("emplouees.db",
    make_table("employees",
    make_column("id", &Employee::id, primary_key().autoincrement()),
    make_column("name", &Employee::name),
    make_column("age", &Employee::age),
    make_column("salary", &Employee::salary)
    ),
    make_table("sales",
    make_column("id", &Sales::id, foreign_key(&Employee::id)),
    make_column("gross_sales", &Sales::gross_sales),
    make_column("commision_rate", &Sales::commission_rate),
    make_column("total_salary", (&Sales::commission_rate * &Sales::gross_sales)) 
    ),
    make_table("engineers",
    make_column("id", &Engineer::id, foreign_key(&Employee::id)),
    make_column("speciality", &Engineer::speciality),
    make_column("experience", &Engineer::experience),
    make_column("overtime_hours", &Engineer::overtime_hours),
    make_column("overtime_hour_rate", &Engineer::overtime_hour_rate) ,
    make_column("total_salary", (&Engineer::overtime_hours * &Engineer::overtime_hours_rate)) 
    ));
    storage.sync_schema();
    return storage; 
} */

}
#endif