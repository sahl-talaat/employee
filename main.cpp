#include<iostream>
#include"sqlite_orm.h"/* 
#include"employee.h"
#include"engineer.h"
#include"sales.h" */
//#include"emp_manage_sys.h"

struct Employee
{
    int id{};
    int age{};
    std::string first_name{};
    std::string last_name{};
    float salary{};

        Employee(int id,const std::string& first_name,const std::string& last_name,int age,float salary):id(id),first_name(first_name),last_name(last_name),age(age),salary(salary)
        {}
};

struct Engineer : public Employee
{
    int id;
    std::string speciality{};
    int experience{};
    float overtime_hours{};
    float overtime_hour_rate{};
    Engineer(int id,const std::string& first_name,const std::string& last_name,int age,float salary,const std::string& speciality,int experience,float overtime_hours,float overtime_hour_rate):Employee(id,first_name,last_name,age,salary),id(Employee::id),speciality(speciality),experience(experience),overtime_hours(overtime_hours),overtime_hour_rate(overtime_hour_rate)
    {}
};

struct Sales : public Employee
{
    int id;
    float gross_sales = 0.0;
    float commission_rate = 0.0;
    Sales(int id,const std::string& first_name,const std::string& last_name,int age,float salary,float gross,float comission):Employee(id,first_name,last_name,age,salary),id(Employee::id),gross_sales(gross),commission_rate(comission)
    {}
};

Engineer add_engineer()
{

    int id{}, age{}, experience{};
    std::string first_name{}, last_name{}, speciality{};
    float overtime_hours{}, overtime_hour_rate{}, salary{};
    std::cout << "Enter Engineer details:" << std::endl;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "First Name: ";
    std::cin >> first_name;
    std::cout << "Last Name: ";
    std::cin >> last_name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Speciality: ";
    std::cin >> speciality;
    std::cout << "Experience: ";
    std::cin >> experience;
    std::cout << "Salary: ";
    std::cin >> salary;
    std::cout << "Overtime Hours: ";
    std::cin >> overtime_hours;
    std::cout << "Overtime Hour Rate: ";
    std::cin >> overtime_hour_rate;
    Engineer eng(id,first_name,last_name,age,salary,speciality,experience,overtime_hours,overtime_hour_rate);
    return eng;                
}

Sales add_sale()
{
    int id{}, age{};
    std::string first_name{}, last_name{};
    float  salary{}, gross_sales{}, commission_rate{};
    std::cout << "Enter Salesperson details:" << std::endl;
    std::cout << "ID: ";
    std::cin >> id;
    std::cout << "First Name: ";
    std::cin >> first_name;
    std::cout << "Last Name: ";
    std::cin >> last_name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Gross: ";
    std::cin >> gross_sales;
    std::cout << "Commission: ";
    std::cin >> commission_rate;
    Sales sale(id,first_name,last_name,age,salary,gross_sales,commission_rate);
    return sale;
}

class Operation{
    public:

    Operation()
    {
        /* try
        {
            auto storage = storage_access();
        }
        catch(...)
        {
            std::cerr << "ctor error\n";
        } */
    }

auto storage_access() {
     using namespace sqlite_orm;
    auto storage = sqlite_orm::make_storage("emplouees.db",
    make_table("employees",
    make_column("id", &Employee::id, primary_key().autoincrement()),
    make_column("first_name", &Employee::first_name),
    make_column("last_name", &Employee::last_name),
    make_column("age", &Employee::age),
    make_column("salary", &Employee::salary)
    ),
    make_table("sales",
    make_column("id", &Sales::id, foreign_key(&Employee::id)),
    make_column("gross_sales", &Sales::gross_sales),
    make_column("commision_rate", &Sales::commission_rate)/* ,
    make_column("total_salary", (&Sales::commission_rate * &Sales::gross_sales)) */
    ),
    make_table("engineers",
    make_column("id", &Engineer::id, foreign_key(&Employee::id)),
    make_column("speciality", &Engineer::speciality),
    make_column("experience", &Engineer::experience),
    make_column("overtime_hours", &Engineer::overtime_hours),
    make_column("overtime_hour_rate", &Engineer::overtime_hour_rate)/* ,
    make_column("total_salary", (&Engineer::overtime_hours * &Engineer::overtime_hours_rate)) */
    ));

    // Create or upgrade tables
    storage.sync_schema();
    return storage;
   

   /*  // Add new employee
    Engineer newEngineer;
    newEngineer.id = 1;
    newEngineer.name = "John Doe";
    newEngineer.age = 30;
    newEngineer.speciality = "Software Development";
    newEngineer.experience = 5;
    newEngineer.overtime_hours = 10.5;
    newEngineer.overtime_hour_rate = 20.0;

    storage.insert(newEngineer); // Insert the new engineer into the database

    // Read data from the database
    auto employees = storage.get_all<Engineer>(where(c(&Employee::id) == 1));
    if (!employees.empty()) {
        Engineer& retrievedEngineer = employees[0];
        std::cout << "Retrieved Employee: " << retrievedEngineer.name << std::endl;

        // Update employee by id
        retrievedEngineer.overtime_hours = 15.0;
        storage.update(retrievedEngineer);
        std::cout << "Updated Overtime Hours: " << retrievedEngineer.overtime_hours << std::endl;

        // Delete employee by id
        storage.remove<Engineer>(1);
        std::cout << "Employee deleted." << std::endl;
    } */
}   

void add_new_to_engineer(const Engineer &new_eng){
    storage_access().insert(new_eng);
}

void add_new_to_slae(const Sales &new_sale){
    storage_access().insert(new_sale);
}

void display_all(){
    auto all_employees = storage_access().get_all<Employee>();
    std::cout<<"All Employees"<<std::endl;
    for (const auto& employee : all_employees){
        std::cout<<"ID: "<<employee.id<<", Name: " << employee.first_name <<" "<<employee.last_name<< ", Age: " << employee.age << std::endl;
    }
}

void display_engineers() {
    auto allEngineers = storage_access().get_all<Engineer>();
    std::cout << "All Engineers:" << std::endl;
    for (const auto& engineer : allEngineers) {
        std::cout << "ID: " << engineer.id << ", Name: " << engineer.first_name<<" "<<engineer.last_name
                  << ", Speciality: " << engineer.speciality << ", Experience: " << engineer.experience << std::endl;
    }
}

void display_sales() {
    auto allSales= storage_access().get_all<Sales>();
    std::cout << "All Salespersons:" << std::endl;
    for (const auto& salesperson : allSales) {
        std::cout << "ID: " << salesperson.id << ", Name: " << salesperson.first_name<<" "<<salesperson.last_name
                  << ", Gross: " << salesperson.gross_sales << ", Commission: " << salesperson.commission_rate << std::endl;
    }
}
};
// Define a function to perform CRUD operations



int main()
{
    Operation obj;
    
    int choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add new employee" << std::endl;
        std::cout << "2. Display all employees" << std::endl;
        std::cout << "3. Display all engineers" << std::endl;
        std::cout << "4. Display all salespersons" << std::endl;
        std::cout << "5. Update employee details" << std::endl;
        std::cout << "6. Delete an employee" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int employeeType;
                std::cout << "Enter type of employee (1 - Engineer, 2 - Sales): ";
                std::cin >> employeeType;
                if (employeeType == 1) {
                    obj.add_new_to_engineer(add_engineer());

                } else if (employeeType == 2) {
                    obj.add_new_to_slae(add_sale());
                } else {
                    std::cout << "Invalid choice!" << std::endl;
                }
                break;
            }
            case 2:
                obj.display_all();
                break;
            case 3:
                obj.display_engineers();
                break;
            case 4:
                obj.display_sales();
                break;
            case 5: {
                int idToUpdate;
                std::cout << "Enter employee ID to update: ";
                std::cin >> idToUpdate;

                std::string newName;
                float newSalary;
                std::cout << "Enter new name: ";
                std::cin >> newName;
                std::cout << "Enter new salary: ";
                std::cin >> newSalary;

                //updateEmployeeByID<Sales>(storage, idToUpdate, newName, newSalary);
                break;
            }
            case 6: {
                int idToDelete;
                std::cout << "Enter employee ID to delete: ";
                std::cin >> idToDelete;

                //deleteEmployeeByID<Sales>(storage, idToDelete);
                break;
            }
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 7);



    /* sahl::EmployeeManagementSystem empSystem;
    sahl::Employee employee;
    while (true)
    {
        int choose{};
        std::cout<<"\tChoose operation\n";
        std::cout<<"    1 . add new\n";
        std::cout<<"    2 . display\n";
        std::cout<<"    3 . update\n";
        std::cout<<"    4 . search\n";
        std::cout<<"    5 . delete\n";
        std::cout<<"    0 . log out\n";
        std::cin>>choose;
     
        switch (choose)
        {
            case 1: // add new emp
            {
                int emp_num,id,age;
                double salary;
                std::string name,position;
                std::cout<<" how many employees u'll add : ";
                std::cin>>emp_num;
                for(int i = 0 ; i < emp_num ; i++)
                {
                    std::cout<<" Enter the data of employee "<<i+1<<"\n";
                    std::cout<<"    Name : ";
                    std::cin>>name;
                    std::cout<<"    ID : ";
                    std::cin>>id;
                    std::cout<<"    Age : ";
                    std::cin>>age;
                    std::cout<<"    Position : ";
                    std::cin>>position;
                    std::cout<<"    Salary : ";
                    std::cin>>salary;
                    empSystem.add_employee(sahl::Employee(id,name,position,salary,age));
                    //empSystem.save_to_file();
                }
                break;
            }
            case 2: // dislay
            {
                while (true)
                {
                    int print_choose = 0;
                    std::cout<<"\t display operations\n";
                    std::cout<<"\tChoose operation\n";
                    std::cout<<"    1 . display all employees\n";
                    std::cout<<"    2 . display by posiotion\n";
                    std::cout<<"    0 . back to main\n";
                    std::cin>>print_choose;

                    switch (print_choose)
                    {
                        case 1:
                        {
                            if(empSystem.is_empty())
                            {
                                std::cout<<"\t...there is no data...\n";
                                break;
                            }
                            std::cout<<"**************************************************************************\n";
                            empSystem.display_all();
                            std::cout<<"**************************************************************************\n";
                            break;
                        }
                        case 2:
                        {
                            std::string position;
                            std::cout<<" enter position to display employees :";
                            std::cin>>position;
                            empSystem.display_employees_by_posiotion(position);
                            break;
                        }
                        default:
                        { 
                            std::cout<<"    Re-Enter \n";
                            break;
                        }
                    }
                }
                break;
            }
            case 3: // update
            {
                 bool update_running = true;
                while (update_running)
                {
                    int update_choose = 0,id;
                    std::cout<<"\t update operations\n";
                    std::cout<<"\t update by ID\n";
                    std::cout<<"    1 . update name\n";
                    std::cout<<"    2 . update age\n";
                    std::cout<<"    3 . update position\n";
                    std::cout<<"    4 . update salary\n";
                    std::cout<<"    0 . back to main\n";
                    std::cin>>update_choose;
                    if (update_choose == 0)
                    {
                        update_running = false;
                        break;
                    }
                    switch (update_choose)
                    {
                        case 1:
                        {
                            int id;
                            std::string name;
                            std::cout<< " enter ID : ";
                            std::cin>>id;
                            std::cout<< " enter new Name : ";
                            std::cin>>name;
                            empSystem.update_name_by_id(id,name);
                            break;
                        }
                        case 2:
                        {
                            int id,age;
                            std::cout<< " enter ID : ";
                            std::cin>>id;
                            std::cout<< " enter new Age : ";
                            std::cin>>age;
                            empSystem.update_age_by_id(id,age);
                            break;
                        }
                        case 3:
                        {
                            int id;
                            std::string position;
                            std::cout<< " enter ID : ";
                            std::cin>>id;
                            std::cout<< " enter new Position : ";
                            std::cin>>position;
                            empSystem.update_position_by_id(id,position);
                            break;
                        }
                        case 4:
                        {
                            int id;
                            double salary;
                            std::cout<< " enter ID : ";
                            std::cin>>id;
                            std::cout<< " enter new Salary : ";
                            std::cin>>salary;
                            empSystem.update_salary_by_id(id,salary);
                            break;
                        }
                        default:
                        { 
                            std::cout<<"    Re-Enter \n";
                            break;
                        }
                    }
                }
                break;
            }
            case 4: // search
            {
                int id;
                std::cout<<"enter id to search :";
                std::cin>>id;
                empSystem.search_by_id(id);
                break;
            }
            case 5: // delete
            {
                int id;
                std::cout<<"enter id to delete :";
                std::cin>>id;
                empSystem.delete_by_id(id);
                break;
            }
            default:
            {
                std::cout<<"    Re-Enter \n";
                break;
            }
        }
        

    }
 */
    //Operation op;
    //op.add_new_emp();

    /* Employee  *emp_ptr;

    Sales s1("Ahemd",120,5000);
    s1.set_gross_sales(50000);
    s1.set_commission_rate(0.1);

    Engineer e1("Hassan",150,7000,"SW Engineer",3);
    e1.set_overtime_hours(10);
    e1.set_overtime_hours_rate(50);

    emp_ptr = &s1;
    emp_ptr->get_totalSalary();
    emp_ptr->print();

    emp_ptr = &e1;
    emp_ptr->get_totalSalary();
    emp_ptr->print();

    std::cout<<emp_ptr<<std::endl; */
    return 0;
}