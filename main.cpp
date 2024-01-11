#include<iostream>
//#include"sqlite_orm.h"
#include"employee.h"
#include"engineer.h"
/* #include"sales.h"
 */#include"reuse_funcs.h"
#include"crud.h"


    /* // Read data from the database
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
    }  */



int main()
{
    CrudOperation crud;
    crud.load_employees_from_file("employee.txt");
    crud.load_engineers_from_file("engineer.txt");
    crud.load_sales_from_file("sale.txt");
    int choice = forUser::main_list();
    do {
        switch (choice) {
            case 1: {
                int employee_type = forUser::employee_type_list();
                if (employee_type == 1) 
                {
                    crud.add_engineers();
                } 
                else if (employee_type == 2) 
                {
                    crud.add_sales();
                } 
                else 
                {
                    std::cout << "Invalid choice!" << std::endl;
                }
                break;
            }
            case 2:
            {
                crud.display_all();
                break;
            }
            case 3:
            {
                crud.display_engineers();
                break;
            }
            case 4:
            {
                crud.display_sales();
                break;
            }
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