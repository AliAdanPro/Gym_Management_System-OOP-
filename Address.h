#pragma once
#include <string>
using namespace std;

class Address {
private:
    int street_no;
    string sector;
    int house_no;
    string city;

public:
   Address() {
    street_no = 0;
    sector = " ";
    house_no = 0;
    city = " ";
}

Address(int street_no, string sector, int house_no, string city) {
    this->street_no = street_no;
    this->sector = sector;
    this->house_no = house_no;
    this->city = city;
}

    string Get_Address() {
        return to_string(street_no) + " " + sector + " " + to_string(house_no) + " " + city;
    }


    void Set_Address(int street_no, string sector, int house_no, string city) {
        this->street_no = street_no;
        this->sector = sector;
        this->house_no = house_no;
        this->city = city;
    }
};