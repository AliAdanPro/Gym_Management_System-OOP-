#pragma once
#include "Person.h"
#include <iostream>
#include <fstream>
#include <iomanip>
class Trainer : public Person
{
private:
    string specialization;
    static int count_trainers;
    ifstream fin;

public:
    Trainer() : Person()
    {
        count_trainers++;
        specialization = " ";
    }

    Trainer(int id, string name, float contact_no, string specialization, int street_no, string sector, int house_no, string city)
        : Person(id, name, contact_no, street_no, sector, house_no, city)
    {
        this->specialization = specialization;
    }

    void setspecialization(string specialization)
    {
        this->specialization = specialization;
    }
    string getspecialization()
    {
        return specialization;
    }

    string tostring() override
    {
        return to_string(*id) + "\t" + name + "\t" + to_string(contact_no) + "\t" + specialization + address.Get_Address() + "\n";
            
    }

void read_data()
{
    try
    {
        fin.open("Trainer.txt");
        if (fin.fail())
        {
            throw runtime_error("Error");
        }
    }
    catch (...)
    {
        cerr << "Error. File was not opened" << endl;
    }
}
static int get_count()
{
    ifstream fin;
    try
    {
        fin.open("Trainer.txt");
        if (fin.fail())
        {
            throw runtime_error("Error");
        }
    }
    catch (...)
    {
        cerr << "Error. File was not opened" << endl;
    }
    int count = 0;
    string line;
    while (getline(fin, line))
    {
        count++;
    }
    count_trainers = count;
    return count_trainers;
    fin.close();
}
void add_record() override
{
    int street_no, house_no;
    string city, sector;
    cout << "What is ID of the trainer" << endl;
    cin >> *id;
    cout << "What is name of the trainer?" << endl;
    cin >> name;
    cout << "What is the contact number of trainer" << endl;
    cin >> contact_no;
    cout << "What is the street number of the Trainer" << endl;
        cin >> street_no;
        cout << "What is the sector of the Trainer?" << endl;
        cin >> sector;
        cout << "What is the house number of the Trainer?" << endl;
        cin >> house_no;
        cout << "What is the city of the Trainer?" << endl;
        cin >> city;
    cout << "What is the specialization of the Trainer" << endl;
    cin >> specialization;
     address.Set_Address(street_no, sector, house_no, city);
    save_data(street_no, sector, house_no, city);
}
void view_record() override
{
    int house_no, street_no;
    string sector, city;
    read_data();
    cout << left << setw(5) << "ID" << setw(15) << "NAME" << setw(15) << "CONTACT_NO"
         << setw(20) << "SPECIALIZATION"
         << setw(15) << "STREET NUMBER" << setw(15) << "SECTOR"
         << setw(10) << "HOUSE_NO" << setw(10) << "CITY" << endl;
    while (fin >> *id >> name >> contact_no >> specialization >> street_no >> sector >> house_no >> city)
    {
cout << left << setw(5) << *id << setw(15) << name << setw(15) << contact_no
             << setw(20) << specialization
             << setw(15) << street_no << setw(15) << sector
             << setw(10) << house_no << setw(10) << city << endl;    }
    fin.close();
}
void save_data(int street_no, string sector, int house_no, string city)
{
    ofstream fout;
    fout.open("Trainer.txt", ios::app);
     fout << *id << "\t" << name << "\t" << contact_no << "\t" << specialization << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << "\n";
    fout.close();
}

void search_record() override
{
    read_data();
    int findid;
    int house_no, street_no;
    string sector, city;
    bool found = false;
    cout << "Which record do you want to find? Tell the ID" << endl;
    cin >> findid;
    cout << left << setw(5) << "ID" << setw(15) << "NAME" << setw(15) << "CONTACT_NO"
         << setw(20) << "SPECIALIZATION"
         << setw(15) << "STREET NUMBER" << setw(15) << "SECTOR"
         << setw(10) << "HOUSE_NO" << setw(10) << "CITY" << endl;
    while (fin >> *id >> name >> contact_no >> specialization >> street_no >> sector >> house_no >> city)
    {
        if (*id == findid)
        {
cout << left << setw(5) << *id << setw(15) << name << setw(15) << contact_no
             << setw(20) << specialization
             << setw(15) << street_no << setw(15) << sector
             << setw(10) << house_no << setw(10) << city << endl;               
             found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Record not found" << endl;
    }
    fin.close();
}
void delete_record() override
{
    read_data();
    int street_no, house_no;
    string sector, city;
    ofstream fout("Trainer1.txt", ios::app);
    cout << "Which ID do you want to delete?" << endl;
    int delid;
    cin >> delid;
    bool deleted = false;
        while (fin >> *id >> name >> contact_no >> specialization >> street_no >> sector >> house_no >> city)
    {
        if (*id != delid)
        {
            fout << *id << "\t" << name << "\t" << contact_no << "\t" << specialization << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << endl;
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
        remove("Trainer.txt");
        rename("Trainer1.txt", "Trainer.txt");
        cout << "The record has been deleted" << endl;
    }
    else
    {
        remove("Trainer1.txt");
        cout << "The record was not found." << endl;
    }
}

void update_record() override
{
    read_data();
    int updateId;
    int house_no, street_no;
    string sector, city;
    cout << "Enter the ID of the trainer you want to update: ";
    cin >> updateId;
    bool found = false;

    ofstream fout("Trainer1.txt", ios::app);

        while (fin >> *id >> name >> contact_no >> specialization >> street_no >> sector >> house_no >> city)
    {
        if (*id == updateId)
        {
            found = true;
            cout << "Enter new name: ";
            cin >> name;

                fout << *id << "\t" << name << "\t" << contact_no << "\t" << specialization << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << endl;
        }
        else
        {
                fout << *id << "\t" << name << "\t" << contact_no << "\t" << specialization << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << endl;
        }
    }

    fin.close();
    fout.close();

    if (found == true)
    {
        remove("Trainer.txt");
        rename("Trainer1.txt", "Trainer.txt");
        cout << "The record has been updated" << endl;
    }
    else
    {
        remove("Trainer1.txt");
        cout << "The record was not found." << endl;
    }
}
};
int Trainer::count_trainers = 0;
