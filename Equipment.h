#pragma once
#include <iostream>
#include <string>
using namespace std;

class Equipment {
private:
    string ename;
    string model;
    int quantity;

public:
	Equipment(){
		ename = " ";
		model = " ";
		quantity = 0;
	}
	Equipment(string ename, string model, int quantity){
		this->ename = ename;
		this->model = model;
		this->quantity = quantity;
	}

    string Get_Equipment()  {
        return ename + " " + model + " " + to_string(quantity);
    }
    void Set_Equipment(string name, string model, int quantity)
    {

        this->ename = name;
        this->model = model;
        this->quantity = quantity;
    }

};