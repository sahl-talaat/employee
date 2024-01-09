#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include"employee.h"


namespace sahl
{
    
class EmployeeManagementSystem
{
    private:
        std::vector<Employee> employees;
        std::string my_file = "employee.txt";
    public:
        EmployeeManagementSystem()
        {
            load_from_file();
        }
        ~EmployeeManagementSystem()
        {
            save_to_file();
            employees.clear();
        }

        int get_capacity()
        {
            return employees.capacity();
        }

        bool is_empty()
        {
            return employees.empty();
        }

        // Load employee data from a file
        void load_from_file() {
            std::ifstream file(my_file);
            if (file.is_open()) {
                employees.clear(); // Clear existing data

                std::string line;

                while (std::getline(file, line)) {
                    std::istringstream iss(line);
                    char dummy;
                    int id, age;
                    double salary;
                    std::string name, position;
                    if (iss >> id >> std::ws && std::getline(iss, name, ',') && std::getline(iss, position, ',') &&
                        iss >> salary >> std::ws && iss >> age) {
                        employees.emplace_back(id, name, position, salary, age);
                    }
                }

                file.close();
            
        }
        }
        void print_all_employees() {
        for (const auto& emp : employees) {
            std::cout << "ID: " << emp.get_id() << ", Name: " << emp.get_name() << ", Position: " << emp.get_position()
                      << ", Salary: " << emp.get_salary() << ", Age: " << emp.get_age() << std::endl;
        }
    }

        // Save employee data to a file
        void save_to_file() 
        {
            std::ofstream file(my_file, std::ios::app);
            if (file.is_open()) {
                for (const auto& emp : employees) {
                    file << emp.get_id() << ',' << emp.get_name() << ',' << emp.get_position() << ',' << emp.get_salary() << ',' << emp.get_age() << '\n';
                }
                file.close();
                std::cout << "Data saved successfully to " << my_file << std::endl;
            } else {
                std::cout << "Unable to open file for writing." << std::endl;
            }
        }

        void save_employee_to_file(const Employee& emp) 
        {
            std::ofstream file(my_file, std::ios_base::app);
            if (file.is_open()) {
                file << emp.get_id() << ',' << emp.get_name() << ',' << emp.get_position() << ',' << emp.get_salary() << ',' << emp.get_age() << '\n';
                file.close();
                std::cout << "Employee data saved successfully to " << my_file << std::endl;
            } else {
                std::cout << "Unable to open file for writing." << std::endl;
            }
        }

////////////////////////////////////////////////////////////////// || CREATE



        // add new employee
        void add_employee(const Employee& emp)
        {
            employees.push_back(emp);
            save_employee_to_file(emp);
        }



////////////////////////////////////////////////////////////////// || READ



        // display all
        void display_all()
        {
            for(const auto& emp : employees)
                std::cout << "[ID : " << emp.get_id() << "], [Name : " << emp.get_name()  << ", [Position : " << emp.get_position() << "], [Salary : " << emp.get_salary() <<"], [Age : " << emp.get_age()  << "]\n";
        }

        // display employee works same position
        void display_employees_by_posiotion(const std::string& position)
        {
            std::cout<< "Employee in position "<<position<<" : \n";
            for(const auto& emp : employees)
            {
                if(emp.get_position() == position)
                {
                    std::cout << "[ID : " << emp.get_id() << "], [Name : " << emp.get_name() <<"], [Position : "<<emp.get_position() << "[Salary : " << emp.get_salary() << "[Age : " << emp.get_age() << "]\n";
                }
            }
        }         



///////////////////////////////////////////////////////////////////



        // update position by id
        void update_position_by_id(int id, const std::string new_position)
        {
            auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee& emp){
                return emp.get_id() == id;
            });
            if (it != employees.end())
            {
                it->set_position(new_position);
                save_to_file(); // Save updated data to file
                std::cout << "Employee with [ID : " << id << "] updated successfully." << std::endl;
            }
            else
            {
                std::cout << "Employee with [ID : " << id << "] not found." << std::endl;
            }
        }

        // update name by id
        void update_name_by_id(int id, const std::string new_name)
        {
            auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee& emp){
                return emp.get_id() == id;
            });
            if (it != employees.end())
            {
                it->set_name(new_name);
                save_to_file();
                std::cout << "Employee with [ID : " << id << "] updated successfully." << std::endl;
            }
            else
            {
                std::cout << "Employee with [ID : " << id << "] not found." << std::endl;
            }
        }

        // update age by id
        void update_age_by_id(int id, const int new_age)
        {
            auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee& emp){
                return emp.get_id() == id;
            });
            if (it != employees.end())
            {
                it->set_age(new_age);
                save_to_file();
                std::cout << "Employee with [ID : " << id << "] updated successfully." << std::endl;
            }
            else
            {
                std::cout << "Employee with [ID : " << id << "] not found." << std::endl;
            }
        }

        // update salary by id
        void update_salary_by_id(int id, const float new_salary)
        {
            auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee& emp){
                return emp.get_id() == id;
            });
            if (it != employees.end())
            {
                it->set_salary(new_salary);
                save_to_file();
                std::cout << "Employee with [ID : " << id << "] updated successfully." << std::endl;
            }
            else
            {
                std::cout << "Employee with [ID : " << id << "] not found." << std::endl;
            }
        }



///////////////////////////////////////////////////////////////



        // delete employee by id
        void delete_by_id(int id)
        {
            auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee& emp){
                return emp.get_id() == id;
            });
            if (it != employees.end())
            {
                employees.erase(it, employees.end());
                std::cout << "Employee with [ID : " << id << "] deleted successfully." << std::endl;
            }
            else
            {
                std::cout << "Employee with [ID : " << id << "] not found." << std::endl;
            }
            
        }

        // search by id
        void search_by_id(int id)
        {
            auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee& emp){
                return  emp.get_id() == id;
            });
            if (it != employees.end()) {
                std::cout << "Employee found - [ID : " << it->get_id() << "], [Name : " << it->get_name() << "], [Age : " << it->get_age() << "], [Position : " << it->get_position() << "], [Salary : " << it->get_salary() << "]\n";
            } else {
                std::cout << "Employee not found." << std::endl;
            }
        }

           
};

} // namespace sahl