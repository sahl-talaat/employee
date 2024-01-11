#include<iostream>
#include"sales.h"
#include"engineer.h"
#include"employee.h"
#include"reuse_funcs.h"
#include<vector>
#include<memory>
#include<algorithm>

class CrudOperation{
    private:
    std::vector<Employee*> employees;
    std::vector<Engineer*> engineers;
    std::vector<Sales*> sales;
    public:

    
       /*  try
        {
            //auto storage = storage_access();
        }
        catch(...)
        {
            std::cerr << "ctor error\n";
        }  */
    
    ~CrudOperation(){/* 
        for (auto eng : engineers){
            delete eng;
        }
        for (auto sale : sales){
            delete sale;
        } */
        
    }

    void display_all(){
        /* auto all_employees = storage_access().get_all<Employee>();
        std::cout<<"All Employees"<<std::endl;
        for (const auto& employee : all_employees){
            std::cout<<"ID: "<<employee.id<<", Name: " << employee.first_name <<" "<<employee.last_name<< ", Age: " << employee.age << std::endl;
        } */

    }
    void display_engineers() {
        /* auto allEngineers = storage_access().get_all<Engineer>();
        std::cout << "All Engineers:" << std::endl;
        for (const auto& engineer : allEngineers) {
            std::cout << "ID: " << engineer.id << ", Name: " << engineer.first_name<<" "<<engineer.last_name
                    << ", Speciality: " << engineer.speciality << ", Experience: " << engineer.experience << std::endl;
        } */
    
    }
    void display_sales() {
        /* auto allSales= storage_access().get_all<Sales>();
        std::cout << "All Salespersons:" << std::endl;
        for (const auto& salesperson : allSales) {
            std::cout << "ID: " << salesperson.id << ", Name: " << salesperson.first_name<<" "<<salesperson.last_name
                    << ", Gross: " << salesperson.gross_sales << ", Commission: " << salesperson.commission_rate << std::endl;
        } */

    }

    // employee

    void load_employees_from_file(const std::string& employee_file){
        std::ifstream file(employee_file);
        if(file.is_open()){
            int id,age;
            float salary;
            std::string name;
            while(file >> id>>name>>age>>salary){
                employees.emplace_back(id,name,age,salary);
            }
            file.close();
        }
    }

    void save_employee(const std::vector<Engineer>& engineers,const std::string engineer_file){
        std::ofstream file(engineer_file);
        if(file.is_open()){
            for (const auto& eng : engineers){
                eng.save_to_file(file);
            }
            file.close();
        }
    }

    void display_all_employees() const {
        std::cout << "All Employees:" << std::endl;
        for (const auto& employee : employees) {
            employee->display();
        }
    }
    
    // emgineers

    void load_engineers_from_file(const std::string& engineer_file){
        std::ifstream file(engineer_file);
        if(file.is_open()){
            int id,age,experience,overtime_hours;
            float salary,overtime_hour_rate;
            std::string name,specility;
            while(file >> id>>name>>age>>salary){
                engineers.emplace_back(id,name,age,salary,experience,specility,overtime_hours,overtime_hour_rate);
            }
            file.close();
        }
    }

    void save_engineers(const std::vector<Engineer>& engineers,const std::string engineer_file){
        std::ofstream file(engineer_file);
        if(file.is_open()){
            for (const auto& eng : engineers){
                eng.save_to_file(file);
            }
            file.close();
        }
    }

    void display_all_engineers() const {
        std::cout << "All Engineers:" << std::endl;
        for (const auto& engineer : engineers) {
            engineer->display();
        }
    }

    void add_engineers(){
        // storage.insert(for_user::add_engineer());
        Engineer new_engineer = forUser::add_engineer();
        engineers.emplace_back(new_engineer);
    }

    // sales

    void load_sales_from_file(const std::string& sales_file){
        std::ifstream file(sales_file);
        if(file.is_open()){
            int id,age;
            float salary, gross_sales,commision_rate;
            std::string name;
            while(file >> id>>name>>age>>salary>>gross_sales>>commision_rate){
                sales.emplace_back(id,name,age,salary,gross_sales,commision_rate);
            }
            file.close();
        }
    }

     void save_sales(const std::vector<Sales>& sales,const std::string& sales_file){
        std::ofstream file(sales_file);
        if(file.is_open()){
            for(const auto& sale : sales){
                sale.save_to_file(file);
            }
            file.close();
        }
    }

    void display_all_sales() const {
        std::cout << "All Sales:" << std::endl;
        for (const auto& sale : sales) {
            sale->display();
        }
    }

    
    void add_sales(){
        // storage.insert(for_user::add_sale());
        Sales new_sale = forUser::add_sale();
        engineers.emplace_back(new_sale);
    }
   
};
// Define a function to perform CRUD operations

