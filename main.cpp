#include <iostream>
using namespace std;

class Empolyee {
private:
    string Name;
    string Empolyee_Id;
    int Base_salary = 0;

public:
    void getDetail() {
        cout << endl;
        cout << " ENTER YOUR NAME : ";
        cin.ignore() ; 
        getline(cin, Name);
        cout << " ENTER YOUR EMPLOYEE ID : ";
        cin >> Empolyee_Id;
        cout << " ENTER YOUR SALARY : ";
        cin >> Base_salary;
    }

    void Calculate_Salary() {
        cout << endl;
        cout << " TOTAL SALARY : $" << Base_salary << endl;
    }

    void Display() {
        cout << endl;
        cout << " NAME : " << Name << endl;
        cout << " EMPLOYEE ID : " << Empolyee_Id << endl;
        cout << " SALARY : $" << Base_salary << endl;
        cout << endl;
    }

    string getID() {
        return Empolyee_Id;
    }

    void Promotion() {
        int increase;
        cout << endl;
        cout << "CURRENT SALARY : $" << Base_salary << endl;
        cout << "INCREMENT AMOUNT IN SALARY : $";
        cin >> increase;
        Base_salary += increase;
    }
};

int main() {
    string temp;
    int choice;
    Empolyee obj[100];
    int empolyee_count = 0;
    int Empolyee_index;

    do {
    cout << "\n=========================================================\n";
    cout << "|                      Employee                         |\n";
    cout << "|                 Management System                     |\n";
    cout << "=========================================================\n\n";


    cout << "======================= MENU ===========================\n";
    cout << "|  [1]  | Add New Employee                             |\n";
    cout << "|  [2]  | View All Employees                           |\n";
    cout << "|  [3]  | Calculate Salaries                           |\n";
    cout << "|  [4]  | Promote an Employee                          |\n";
    cout << "|  [5]  | Search Employee by ID                        |\n";
    cout << "|  [6]  | Delete an Employee                           |\n";
    cout << "|  [7]  | Exit                                         |\n";
    cout << "========================================================\n\n";

    cout << "Please enter your choice (1-7): ";

        cin >> choice;
        

        switch (choice) {
        case 1:
            obj[empolyee_count].getDetail();
            empolyee_count++;
            break;

        case 2:
            for (int i = 0; i < empolyee_count; i++)
                obj[i].Display();
            break;

        case 3:
            for (int i = 0; i < empolyee_count; i++)
                obj[i].Calculate_Salary();
            break;

        case 4:
            cout << "ENTER EMPLOYEE ID : ";
            cin >> temp;
            {
                bool found = false;
                for (int i = 0; i < empolyee_count; i++) {
                    if (obj[i].getID() == temp) {
                        obj[i].Promotion();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "ID NOT FOUND" << endl;
            }
            break;

        case 5:
            cout << "ENTER EMPLOYEE ID : ";
            cin >> temp;
            {
                bool found = false;
                for (int i = 0; i < empolyee_count; i++) {
                    if (obj[i].getID() == temp) {
                        obj[i].Display();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "ID NOT FOUND" << endl;
            }
            break;

        case 6:
            cout << " ENTER EMPLOYEE ID : ";
            cin >> temp;
            {
                bool found = false;
                for (int i = 0; i < empolyee_count; i++) {
                    if (obj[i].getID() == temp) {
                        for (int j = i; j < empolyee_count - 1; j++) {
                            obj[j] = obj[j + 1];
                        }
                        empolyee_count--;
                        found = true;
                        cout << "EMPLOYEE DELETED SUCCESSFULLY.\n";
                        break;
                    }
                }
                if (!found)
                    cout << "ID NOT FOUND" << endl;
            }
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
