#include<iostream>
#include<fstream>
#include"sales.h"
#include"engineer.h"
#include"employee.h"
#include"reuse_funcs.h"
#include<vector>
#include<algorithm>

class CrudOperation{
    public:
    CrudOperation(){

    }
    ~CrudOperation(){
    }


    

    // employee


    /* void load_employees_from_file(const std::string employee_file){
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
    } */

    /* void save_employee(const std::string employee_file){
        std::ofstream file(employee_file);
        if(file.is_open()){
            for (const auto& employee : employees){
                employee.save_to_file(file);
            }
            file.close();
        }
    } */


    
    // load data from files

    void load_engineers_from_file(std::vector<Engineer> &engineers,const std::string engineer_file){
        std::ifstream file(engineer_file);
        if(file.is_open()){
            engineers.clear();
            int id,age,experience,overtime_hours;
            float salary,overtime_hour_rate;
            std::string name,specility;
            while(file >> id>>name>>age>>salary>>specility>>experience>>overtime_hours>>overtime_hour_rate){
                engineers.emplace_back(id,name,age,salary,specility,experience,overtime_hours,overtime_hour_rate);
            }
            file.close();
        }
    } 

     void load_sales_from_file(std::vector<Sales> &sales,const std::string sale_file){
        std::ifstream file(sale_file);
        if(file.is_open()){
            sales.clear();
            int id,age;
            float salary,gross_sales,commission_rate;
            std::string name;
            while(file >> id>>name>>age>>salary>>gross_sales>>commission_rate){
                sales.emplace_back(id,name,age,salary,gross_sales,commission_rate);
            }
            file.close();
        }
    } 

    // save data in files
    void save_engineers(const std::vector<Engineer>& engineers, const std::string& engineer_file) {
        std::ofstream file(engineer_file);
        if (file.is_open()) {
            for (const auto& engineer : engineers) {
                file << engineer.get_id() << " " << engineer.get_name() << " " << engineer.get_age() << " " << engineer.get_salary()
                << " " << engineer.get_speciality() << " " << engineer.get_experience() << " " << engineer.get_overtime() << " " << engineer.get_overtime_rate() << "\n";
            }
        }
        file.close();
    }

    void save_sale(const std::vector<Sales>& sales, const std::string& sale_file) {
        std::ofstream file(sale_file);
        if (file.is_open()) {
            for (const auto& sale : sales) {
                file << sale.get_id() << " " << sale.get_name() << " " << sale.get_age() << " " << sale.get_salary()
                << " " << sale.get_gross() << " " << sale.get_commition() << "\n";
            }
        }
        file.close();
    }

    /* void save_engineers(const std::string engineer_file){
        std::ofstream file(engineer_file);
        if(file.is_open()){
            for (const auto& engineer : engineers){
                engineer.save_to_file(file);
            }
            file.close();
        }
    } */



    // sales

   /*  void load_sales_from_file(const std::string& sales_file){
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
    } */

     /* void save_sales(const std::vector<Sales>& sales,const std::string& sales_file){
        std::ofstream file(sales_file);
        if(file.is_open()){
            for(const auto& sale : sales){
                sale.save_to_file(file);
            }
            file.close();
        }
    } */
    // create
    void add_new_engineer(std::vector<Engineer> &engineers, Engineer &new_engineer,const std::string &engineer_file)
    {
        engineers.push_back(new_engineer);
        save_engineers(engineers,engineer_file);
    }

    void add_new_sale(std::vector<Sales> &sales, Sales &new_sale,const std::string &sale_file)
    {
        sales.push_back(new_sale);
        save_sale(sales,sale_file);
    }

    // display
    void display_all_employees(std::vector<Employee> &employees)  {
        std::cout << "All Employees:" << std::endl;
        for (const auto& employee : employees) {
            employee.display();
        }
    }

    void display_all_engineers(std::vector<Engineer> &engineers)  {
        std::cout << "All Engineers:" << std::endl;
        for (const auto& engineer : engineers) {
            engineer.display();
        }
    }

    void display_all_sales(std::vector<Sales> &sales)  {
        std::cout << "All Sales:" << std::endl;
        for (const auto& sale : sales) {
            sale.display();
        }
    }

    // update
    void update_name_by_id(std::vector<Employee> &employees, int id, const std::string &new_name){
        auto it = std::find_if(employees.begin(),employees.end(), [id](const Employee &employee) {
            return employee.get_id() == id;
        });
        if (it != employees.end()) {
            it->set_name(new_name);
        } 
   }

    void update_engineer_name_by_id(std::vector<Engineer> &engineers, int id, const std::string &new_name, std::string &engineer_file){
        for (auto &engineer : engineers) {
            if(engineer.get_id() == id){
                engineer.set_name(new_name);
                break;
            }
        }
        save_engineers(engineers,engineer_file);
        
        /* auto it = std::find_if(engineers.begin(),engineers.end(), [id](const Engineer &engineer) {
            return engineer.get_id() == id;
        });
        if (it != engineers.end()) {
            it->set_name(new_name);
        }  */
    }
   
    void update_sale_name_by_id(std::vector<Sales> &sales, int id, const std::string &new_name, std::string &sale_file){
        auto it = std::find_if(sales.begin(),sales.end(), [id](const Sales &sale) {
            return sale.get_id() == id;
        });
        if (it != sales.end()) {
            it->set_name(new_name);
        } 
        save_sale(sales,sale_file);
    }

    // delete 
    void delete_by_id(std::vector<Employee> &employees, int id) {
    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee &emp) {
        return emp.get_age() == id;
    });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
    } 
    }

    void delete_engineer_by_id(std::vector<Engineer> &engineers, int id,std::string &engineer_file) {
    auto it = std::remove_if(engineers.begin(), engineers.end(), [id](const Engineer &eng) {
        return eng.get_id() == id;
    });

    if (it != engineers.end()) {
        engineers.erase(it, engineers.end());
    } 
    save_engineers(engineers,engineer_file);
    }

    void delete_sale_by_id(std::vector<Sales> &sales, int id, std::string &sale_file) {
    auto it = std::remove_if(sales.begin(), sales.end(), [id](const Sales &sale) {
        return sale.get_id() == id;
    });

    if (it != sales.end()) {
        sales.erase(it, sales.end());
    } 
    save_sale(sales,sale_file);
    }
};
// Define a function to perform CRUD operations

