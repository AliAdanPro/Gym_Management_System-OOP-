#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Equipment.h"
#include "Address.h"
#include <iomanip>

using namespace std;

class Gym
{
private:
    string name;
    int contact_No;
    static int count_gym;
    Equipment *equipments;
    int numEquipments;
    static int count_equip;
    Address address;

public:
    Gym()
    {
        name = " ";
        contact_No = 0;
        equipments = nullptr;
        numEquipments = 0;
        count_gym++;
    }
    Gym( string name, int contact_No, Equipment *equipments, int numEquipments, int street_no, string sector, int house_no, string city)
    {
        this->name = name;
        this->contact_No = contact_No;
        this->numEquipments = numEquipments;
        this->equipments = new Equipment[numEquipments];
        for (int i = 0; i < numEquipments; i++)
        {
            this->equipments[i] = equipments[i];
        }
        address.Set_Address(street_no, sector, house_no, city);
        count_gym++;
    }

    ~Gym()
    {
        delete[] equipments;
    }

    void setGym(const string name, int contact_No, int street_no, string sector, int house_no, string city)
    {
        this->name = name;
        this->contact_No = contact_No;
        address.Set_Address(street_no, sector, house_no, city);
    }

    string getGym()
    {
        string outputgym = name + " " + to_string(contact_No) + " " + address.Get_Address() + "\n";
        return outputgym;
    }
    string outEquipment()
    {
        string outputequip;
        for (int i = 0; i < numEquipments; i++)
        {
            outputequip += equipments[i].Get_Equipment() + "\n";
        }
        return outputequip;
    }

    static int getCountgym()
    {
        ifstream fin;
        try
        {
            fin.open("Gym.txt");
            if (fin.fail())
            {
                throw runtime_error("Error opening");
            }
        }
        catch (...)
        {
            cerr << "Error opening file" << endl;
        }

        int count = 0;
        string line;
        while (getline(fin, line))
        {
            count++;
        }
        fin.close();
        count_gym = count;
        return count_gym;
    }
    static int getCountequip()
    {
        ifstream fin;
        try
        {
            fin.open("Equipment.txt");
            if (fin.fail())
            {
                throw runtime_error("Error opening");
            }
        }
        catch (...)
        {
            cerr << "Error opening file" << endl;
        }

        int count = 0;
        string line;
        while (getline(fin, line))
        {
            count++;
        }
        fin.close();
        count_equip = count;
        return count_equip;
    }

    friend istream &operator>>(istream &input, Gym &gym)
    {
        cout << "Enter Gym Name: \n";
        input >> gym.name;
        cout << "Enter Contact Number: \n";
        input >> gym.contact_No;

        int street_no, house_no;
        string sector, city;
        cout << "Enter Street No: \n";
        input >> street_no;
        cout << "Enter Sector: \n";

        input >> sector;
        cout << "Enter House No: \n";
        input >> house_no;
        cout << "Enter City: \n";
        input >> city;
        gym.address.Set_Address(street_no, sector, house_no, city);
        return input;
    }
    void addEquipment()
    {
        cout << "Enter number of equipment items: \n";
        cin >> numEquipments;
        equipments = new Equipment[numEquipments];

        string ename, model;
        int quantity;
        for (int i = 0; i < numEquipments; i++)
        {

            cout << "Enter Equipment Name: ";
            cin >> ename;
            cout << "Enter Equipment Model: ";
            cin >> model;
            cout << "Enter Equipment Quantity: ";
            cin >> quantity;
            equipments[i].Set_Equipment(ename, model, quantity);
        }
        addDataequip();
    }

    void viewGym()
    {
        cout << "Total Gyms: " << Gym::getCountgym() << endl;
        cout << endl;
       cout << left << setw(20) << "GYM_NAME" << setw(15) << "CONTACT_NO" << setw(15) << "STREET NUMBER"
         << setw(15) << "SECTOR" << setw(10) << "HOUSE_NO" << setw(10) << "CITY" << endl;

        ifstream fin;
        try
        {
            fin.open("Gym.txt");
            if (fin.fail())
            {
                throw runtime_error("Error opening");
            }
        }
        catch (...)
        {
            cerr << "Unable to open file" << endl;
        }
        string gym_name, sector, city;
        string contact_no, street_no, house_no;
        while (fin >> gym_name >> contact_no >> street_no >> sector >> house_no >> city)
        {
            cout << left << setw(20) << gym_name << setw(15) << contact_no << setw(15) << street_no
             << setw(15) << sector << setw(10) << house_no << setw(10) << city << endl;
        }

        fin.close();
    }

    void addDatagym()
    {
        ofstream fout("Gym.txt", ios::app);
        fout << getGym();
        fout.close();
    }
    

    void searchgym()
    {
        ifstream fin;
        try
        {
            fin.open("Gym.txt");
            if (fin.fail())
            {
                throw runtime_error("Error opening file");
            }
        }
        catch (...)
        {
            cerr << "Unable to Open the Gym.txt file" << endl;
        }
        string search_gym;
        cout << "Enter the gym name of the gym you want to find?" << endl;
        cin >> search_gym;
        bool found = false;
        string gym_name, sector, city;
        string contact_no, street_no, house_no;
        cout << left << setw(20) << "GYM_NAME" << setw(15) << "CONTACT_NO" << setw(15) << "STREET NUMBER"
         << setw(15) << "SECTOR" << setw(10) << "HOUSE_NO" << setw(10) << "CITY" << endl;
        while (fin >> gym_name >> contact_no >> street_no >> sector >> house_no >> city)
        {
            if (gym_name == search_gym)
            {
                cout << left << setw(20) << gym_name << setw(15) << contact_no << setw(15) << street_no
                 << setw(15) << sector << setw(10) << house_no << setw(10) << city << endl;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            cout << "Record not found" << endl;
        }
        fin.close();
        cout << endl;
    }

    void updategym()
    {
        ifstream fin;
        try
        {
            fin.open("Gym.txt");
            if (fin.fail())
            {
                throw runtime_error("Couldn't open");
            }
        }
        catch (...)
        {
            cerr << "Error opening file" << endl;
        }
        string update_gym_name;
        cout << "Enter the gym name of the Gym you want to update: ";
        cin >> update_gym_name;
        string house_no, street_no, contact_no;
        string sector, city, gym_name;
        bool found = false;

        ofstream fout("Gym1.txt", ios::app);

        while (fin >> gym_name >> contact_no >> street_no >> sector >> house_no >> city)
        {
            if (gym_name == update_gym_name)
            {
                found = true;
                cout << "Enter new gym name: ";
                cin >> gym_name;

                fout << gym_name << " " << contact_no << " " << street_no << " " << sector << " " << house_no << " " << city << endl;
            }
            else
            {
                fout << gym_name << " " << contact_no << " " << street_no << " " << sector << " " << house_no << " " << city << endl;
            }
        }

        fin.close();
        fout.close();

        if (found == true)
        {
            remove("Gym.txt");
            rename("Gym1.txt", "Gym.txt");
            cout << "The record has been updated" << endl;
        }
        else
        {
            remove("Gym1.txt");
            cout << "The record was not found." << endl;
        }
        cout << endl;
    }

    void deletegym()
    {
        ifstream fin;
        try
        {
            fin.open("Gym.txt");
            if (fin.fail())
            {
                throw runtime_error("Couldn't open");
            }
        }
        catch (...)
        {
            cerr << "Error opening file" << endl;
        }
        string delete_gym_name;
        cout << "Enter the gym name of the Gym record you want to delete: ";
        cin >> delete_gym_name;
        string house_no, street_no, contact_no;
        string sector, city, gym_name;
        bool deleted = false;

        ofstream fout("Gym1.txt", ios::app);

        while (fin >> gym_name >> contact_No >> street_no >> sector >> house_no >> city)
        {
            if (gym_name != delete_gym_name)
            {

                fout << gym_name << " " << contact_no << " " << street_no << " " << sector << " " << house_no << " " << city << endl;
            }
            else
            {
                deleted = true;
            }
        }

        fin.close();
        fout.close();

        if (deleted == true)
        {
            remove("Gym.txt");
            rename("Gym1.txt", "Gym.txt");
            cout << "The record has been deleted" << endl;
        }
        else
        {
            remove("Gym1.txt");
            cout << "The record was not found." << endl;
        }
        cout << endl;
    }

    //s
     void viewequip()
    {
        cout << "Total Equipments: " << Gym::getCountequip() << endl;
        cout << endl;
cout << left << setw(20) << "E_NAME" << setw(15) << "E_MODEL" << setw(15) << "E_QUANTITY" << endl;     

        ifstream fin;
        try
        {
            fin.open("Equipment.txt");
            if (fin.fail())
            {
                throw runtime_error("Error opening");
            }
        }
        catch (...)
        {
            cerr << "Unable to open file" << endl;
        }
        string ename, model, quantity;
        while (fin >> ename >> model >> quantity)
        {
        cout << left << setw(20) << ename << setw(15) << model << setw(15) << quantity << endl;
        }

        fin.close();
    }

   
    void addDataequip()
    {
        ofstream fout("Equipment.txt", ios::app);
        fout << outEquipment();
        fout.close();
    }

    void searchequip()
    {
        ifstream fin;
        try
        {
            fin.open("Equipment.txt");
            if (fin.fail())
            {
                throw runtime_error("Error opening file");
            }
        }
        catch (...)
        {
            cerr << "Unable to Open the Gym.txt file" << endl;
        }
        string search_equip_name;
        cout << "Enter the equipment name of the equipment you want to find?" << endl;
        cin >> search_equip_name;
        bool found = false;
        string ename, model, quantity;
    cout << left << setw(20) << "E_NAME" << setw(15) << "E_MODEL" << setw(15) << "E_QUANTITY" << endl;
        while (fin >> ename >> model >> quantity)
        {
            if (search_equip_name == ename)
            {
            cout << left << setw(20) << ename << setw(15) << model << setw(15) << quantity << endl;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            cout << "Record not found" << endl;
        }
        fin.close();
        cout << endl;
    }

    void updateequip()
    {
        ifstream fin;
        try
        {
            fin.open("Equipment.txt");
            if (fin.fail())
            {
                throw runtime_error("Couldn't open");
            }
        }
        catch (...)
        {
            cerr << "Error opening file" << endl;
        }
        string update_equip_name;
        cout << "Enter the equipment name of the equipment you want to update: ";
        cin >> update_equip_name;
        string ename, model, quantity;
        bool found = false;

        ofstream fout("Equipment1.txt", ios::app);

        while (fin >> ename >> model >> quantity)
        {
            if (ename == update_equip_name)
            {
                found = true;
                cout << "Enter new equipment name: ";
                cin >> ename;

                fout << ename << " " << model << " " << quantity << endl;
            }
            else
            {
                fout << ename << " " << model << " " << quantity << endl;
            }
        }

        fin.close();
        fout.close();

        if (found == true)
        {
            remove("Equipment.txt");
            rename("Equipment1.txt", "Equipment.txt");
            cout << "The record has been updated" << endl;
        }
        else
        {
            remove("Equipment1.txt");
            cout << "The record was not found." << endl;
        }
        cout << endl;
    }

    void deleteequip()
    {
        ifstream fin;
        try
        {
            fin.open("Equipment.txt");
            if (fin.fail())
            {
                throw runtime_error("Couldn't open");
            }
        }
        catch (...)
        {
            cerr << "Error opening file" << endl;
        }
        string delete_equip_name;
        cout << "Enter the equipment name of the equipment record you want to delete: ";
        cin >> delete_equip_name;
        string ename, model, quantity;
        bool deleted = false;

        ofstream fout("Equipment1.txt", ios::app);

        while (fin >> ename >> model >> quantity)
        {
            if (ename != delete_equip_name)
            {

                fout << ename << " " << model << " " << quantity << endl;
            }
            else
            {
                deleted = true;
            }
        }

        fin.close();
        fout.close();

        if (deleted == true)
        {
            remove("Equipment.txt");
            rename("Equipment1.txt", "Equipment.txt");
            cout << "The record has been deleted" << endl;
        }
        else
        {
            remove("Equipment1.txt");
            cout << "The record was not found." << endl;
        }
        cout << endl;
    }
};
int Gym::count_gym = 0;
int Gym::count_equip = 0;