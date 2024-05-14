#pragma once
#include "Person.h"
#include "Invoice.h"
#include "Address.h"
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Member : public Person
{
private:
    static int count_members;
    string trainer_required;
    ifstream fin;
    Invoice bill;

public:

    Member() : Person()
    {
        count_members++;
        trainer_required = " ";
    }
   Member(int id, string name, float contact_no, string trainer_required,
           int trainer_charges, int gym_fee, int street_no, string sector, int house_no, string city)
        : Person(id, name, contact_no, street_no, sector, house_no, city) { 
        this->trainer_required = trainer_required;
        bill.set_trainer_charges(trainer_charges);
        bill.set_gym_fee(gym_fee);
        
    }
    void setTrainer_required(string trainer_required)
    {
        this->trainer_required = trainer_required;
    }
    string getTrainer_required()
    {
        return trainer_required;
    }
   string tostring() override {
    return to_string(*id) + "\t" + name + "\t" + to_string(contact_no) + "\t" +
           trainer_required + "\t" + to_string(bill.Total_amount()) + "\t" + address.Get_Address() + "\n";
}

    static int get_count()
    {
        ifstream fin;
        try
        {
            fin.open("Member.txt");
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
        count_members = count;
        return count_members;
        cout << endl;
        fin.close();
    }
    void read_data()
    {
        try
        {
            fin.open("Member.txt");
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
    void save_data(float total_amount, int street_no, string sector, int house_no, string city)
    {
        ofstream fout;
        fout.open("Member.txt", ios::app);
        fout << *id << "\t" << name << "\t" << contact_no << "\t" << trainer_required << "\t" << total_amount << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << "\n";
        fout.close();
    }

    void add_record() override
    {
        int street_no, house_no;
        string city, sector;
        cout << "What is ID of the Member" << endl;
        cin >> *id;
        cout << "What is name of the Member?" << endl;
        cin >> name;
        cout << "What is the contact number of Member" << endl;
        cin >> contact_no;
        cout << "What is the street number of the member" << endl;
        cin >> street_no;
        cout << "What is the sector of the member?" << endl;
        cin >> sector;
        cout << "What is the house number of the member?" << endl;
        cin >> house_no;
        cout << "What is the city of the member?" << endl;
        cin >> city;
        cout << "Does the Member require a trainer (YES or NO)" << endl;
        cin >> trainer_required;
        int gym_fee = 1000;
        int trainer_fee = 0;
        if (trainer_required == "YES" || trainer_required == "yes")
        {
            trainer_fee = 2000;
        }
        bill.set_gym_fee(gym_fee);
        bill.set_trainer_charges(trainer_fee);
        float total_amount = bill.calculate_total_amount();
        address.Set_Address(street_no, sector, house_no, city);
        save_data(total_amount, street_no, sector, house_no, city);
        cout << endl;
    }
   void view_record() override
{
    float total_amount;
    int house_no, street_no;
    string sector, city;
    read_data();

    cout << left << setw(5) << "ID" << setw(15) << "NAME" << setw(15) << "CONTACT_NO"
         << setw(20) << "TRAINER_REQUIRED" << setw(15) << "TOTAL AMOUNT"
         << setw(15) << "STREET NUMBER" << setw(15) << "SECTOR"
         << setw(10) << "HOUSE_NO" << setw(10) << "CITY" << endl;

    while (fin >> *id >> name >> contact_no >> trainer_required >> total_amount >> street_no >> sector >> house_no >> city)
    {
        cout << left << setw(5) << *id << setw(15) << name << setw(15) << contact_no
             << setw(20) << trainer_required << setw(15) << total_amount
             << setw(15) << street_no << setw(15) << sector
             << setw(10) << house_no << setw(10) << city << endl;
    }

    fin.close();
    cout << endl;
}

    void search_record() override
    {
        read_data();
        int findid;
        float total_amount;
        int house_no, street_no;
        string sector, city;
        bool found = false;
        cout << "Which record do you want to find? Tell the ID" << endl;
        cin >> findid;
        cout << left << setw(5) << "ID" << setw(15) << "NAME" << setw(15) << "CONTACT_NO"
         << setw(20) << "TRAINER_REQUIRED" << setw(15) << "TOTAL AMOUNT"
         << setw(15) << "STREET NUMBER" << setw(15) << "SECTOR"
         << setw(10) << "HOUSE_NO" << setw(10) << "CITY" << endl;
        while (fin >> *id >> name >> contact_no >> trainer_required >> total_amount >> street_no >> sector >> house_no >> city)
        {
            if (*id == findid)
            {
cout << left << setw(5) << *id << setw(15) << name << setw(15) << contact_no
             << setw(20) << trainer_required << setw(15) << total_amount
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
        cout << endl;
    }
    void update_record() override
    {
        read_data();
        int updateId;
        cout << "Enter the ID of the Member you want to update: ";
        cin >> updateId;
        float total_amount;
        int house_no, street_no;
        string sector, city;
        bool found = false;

        ofstream fout("Member1.txt", ios::app);

        while (fin >> *id >> name >> contact_no >> trainer_required >> total_amount >> street_no >> sector >> house_no >> city)
        {
            if (*id == updateId)
            {
                found = true;
                cout << "Enter new name: ";
                cin >> name;

                fout << *id << "\t" << name << "\t" << contact_no << "\t" << trainer_required << "\t" << total_amount << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << endl;
            }
            else
            {
                fout << *id << "\t" << name << "\t" << contact_no << "\t" << trainer_required << "\t" << total_amount << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << endl;
            }
        }

        fin.close();
        fout.close();

        if (found == true)
        {
            remove("Member.txt");
            rename("Member1.txt", "Member.txt");
            cout << "The record has been updated" << endl;
        }
        else
        {
            remove("Member1.txt");
            cout << "The record was not found." << endl;
        }
        cout << endl;
    }
    void delete_record() override
    {
        read_data();
        int street_no, house_no;
        string sector, city;
        ofstream fout("Member1.txt", ios::app);
        cout << "Enter ID of the record do you want to delete?" << endl;
        int delid;
        cin >> delid;
        float total_amount;
        bool deleted = false;
        while (fin >> *id >> name >> contact_no >> trainer_required >> total_amount >> street_no >> sector >> house_no >> city)
        {
            if (*id != delid)
            {
            fout << *id << "\t" << name << "\t" << contact_no << "\t" << trainer_required << "\t" << total_amount << "\t" << street_no << "\t" << sector << "\t" << house_no << "\t" << city << endl;
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
            remove("Member.txt");
            rename("Member1.txt", "Member.txt");
            cout << "The record has been deleted" << endl;
        }
        else
        {
            remove("Member.txt");
            cout << "The record was not found." << endl;
        }
    }
};
int Member::count_members = 0;
