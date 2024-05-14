#pragma once
#include <iostream>
#include "Address.h"
#include <string>
using namespace std;

class Person{
    protected:
    int *id; 
    string name;
    float contact_no;
    Address address;
    public:

    Person(){
        id = new int (0);
        name = "";
        contact_no = 0;
    }
   Person(int id, string name, float contact_no, int street_no, string sector,int house_no, string city) {
        this->id = new int(id);
        this->name = name;
        this->contact_no = contact_no;
        address.Set_Address(street_no, sector, house_no, city);
    }
    virtual string tostring() = 0;
    virtual void add_record() = 0;
    virtual void view_record() = 0;
    virtual void search_record() = 0;
    virtual void delete_record() = 0;
    virtual void update_record() = 0;
    

    void setId(int id){
        *(this->id) = id;
    }
    int getId(){
        return *id;
    }
    void setName(string name){
        this ->name= name;
    }
    string getName(){
        return name;
    }
    void setContact(float contact_no){
        this->contact_no = contact_no;
    }
    float getContact(){
        return contact_no;
    }

    virtual ~Person(){
        delete id;
    }
};