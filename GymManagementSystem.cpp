#include <iostream>
#include "Gym.h"
#include "Person.h"
#include "Address.h"
#include "Member.h"
#include "Trainer.h"
#include <fstream>
using namespace std;
int main()
{
    Gym gym;
    Person *p;
    int choice;

    do
    {
        cout << "====================================\n";
        cout << "GYM MANAGEMENT SYSTEM\n";
        cout << "What do you want to access?" << endl;
        cout << "1. GYM SYSTEM" << endl;
        cout << "2. EQUIPMENT SYSTEM" << endl;
        cout << "3. MEMBER SYSTEM" << endl;
        cout << "4. TRAINER SYSTEM" << endl;
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            while (true)
            {

                cout << "GYM SYSTEM" << endl;
                cout << "1. Add Gym\n";
                cout << "2. View Gyms\n";
                cout << "3. Search Gym\n";
                cout << "4. Update Gym\n";
                cout << "5. Delete Gym\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter details of the gym to add:\n";
                    cin >> gym;
                    gym.addDatagym();
                    cout << endl;

                    break;
                case 2:
                    cout << "Listing all gyms:\n";
                    gym.viewGym();
                    cout << endl;

                    break;
                case 3:
                    cout << "Search for a gym:\n";
                    gym.searchgym();
                    cout << endl;
                    break;
                case 4:
                    cout << "Update an existing gym:\n";
                    gym.updategym();
                    cout << endl;
                    break;
                case 5:
                    cout << "Delete a gym:\n";
                    gym.deletegym();
                    cout << endl;
                    break;
                case 6:
                    cout << "Returning to main menu" << endl;
                    cout << endl;
                    break;
                default:
                    cout << "Invalid choice. Try again" << endl;
                    cout << endl;
                    break;
                }

                if (choice == 6)
                {
                    system("cls");
                    cout << endl;
                    break;
                }
            }
            break;
        case 2:
            while (true)
            {

                cout << "EQUIPMENT SYSTEM" << endl;
                cout << "1. Add Equipment\n";
                cout << "2. View Equipments\n";
                cout << "3. Search Equipments\n";
                cout << "4. Update Equipments\n";
                cout << "5. Delete Equipments\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter details of the Equipments to add:\n";
                    gym.addEquipment();
                    cout << endl;

                    break;
                case 2:
                    cout << "Listing all Equipments:\n";
                    gym.viewequip();
                    cout << endl;

                    break;
                case 3:
                    cout << "Search for a Equipment:\n";
                    gym.searchequip();
                    cout << endl;

                    break;
                case 4:
                    cout << "Update an existing Equipment record:\n";
                    gym.updateequip();
                    cout << endl;

                    break;
                case 5:
                    cout << "Delete a equipment:\n";
                    gym.deleteequip();
                    cout << endl;

                    break;
                case 6:
                    cout << "Returning to main menu" << endl;
                    cout << endl;

                    break;
                default:
                    cout << "Invalid choice. Try again" << endl;
                    cout << endl;

                    break;
                }

                if (choice == 6)
                {
                    system("cls");
                    cout << endl;

                    break;
                }
            }
            break;
        case 3:
            while (true)
            {
                p = new Member;
                cout << "MEMBER SYSTEM" << endl;
                cout << "1. Add Member\n";
                cout << "2. View Member\n";
                cout << "3. Search Member\n";
                cout << "4. Update Member\n";
                cout << "5. Delete Member\n";
                cout << "6. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter details of the Member to add:\n";
                    p->add_record();
                    cout << endl;

                    break;
                case 2:
                    cout << "Listing all members:\n";
                    cout << "Count of the Members is: " << Member::get_count() << endl;
                    p->view_record();
                    cout << endl;

                    break;
                case 3:
                    cout << "Search for a member:\n";
                    p->search_record();
                    cout << endl;

                    break;
                case 4:
                    cout << "Update an existing Member Record:\n";
                    p->update_record();
                    cout << endl;

                    break;
                case 5:
                    cout << "Delete a Member record:\n";
                    p->delete_record();
                    cout << endl;

                    break;
                case 6:
                    cout << "Returning to main menu" << endl;
                    cout << endl;

                    break;
                default:
                    cout << "Invalid choice. Try again" << endl;
                    cout << endl;

                    break;
                }

                if (choice == 6)
                {
                    system("cls");
                    cout << endl;

                    delete p;
                    break;
                }
            }
            break;
        case 4:
            p = new Trainer;
            cout << "TRAINER SYSTEM" << endl;
            cout << "1. Add Trainer\n";
            cout << "2. View Trainer\n";
            cout << "3. Search Trainer\n";
            cout << "4. Update Trainer\n";
            cout << "5. Delete Trainer\n";
            cout << "6. Back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter details of the Trainer to add:\n";
                p->add_record();
                cout << endl;

                break;
            case 2:
                cout << "Listing all Trainers:\n";
                cout << "Count of the Trainers is: " << Trainer::get_count() << endl;
                p->view_record();
                cout << endl;

                break;
            case 3:
                cout << "Search for a Trainer:\n";
                p->search_record();
                cout << endl;

                break;
            case 4:
                cout << "Update an existing Trainer Record:\n";
                p->update_record();
                cout << endl;

                break;
            case 5:
                cout << "Delete a Trainer record:\n";
                p->delete_record();
                cout << endl;

                break;
            case 6:
                cout << "Returning to main menu" << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Try again" << endl;
                cout << endl;

                break;
            }

            if (choice == 6)
            {
                system("cls");
                cout << endl;
                delete p;
                break;
            }
            

        }
        
    }while(choice != 5);
    return 0;
}
