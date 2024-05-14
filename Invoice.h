#pragma once
#include "Member.h"

class Invoice{
    private:
    int trainer_charges;
    int gym_fee;
    float total_amount;
    public:
    Invoice(){
        trainer_charges = 0;
        gym_fee = 0;
        total_amount = 0;
    }
    Invoice(int trainer_charges, int gym_fee, float total_amount){
        this->trainer_charges = trainer_charges;
        this->gym_fee = gym_fee;
        this->total_amount = total_amount;
    }
    void set_gym_fee(int gym_fee){
        this->gym_fee = gym_fee;
    }
    int get_gym_fee(){
        return gym_fee;
    }
    void set_trainer_charges(int trainer_charges){
        this->trainer_charges = trainer_charges;
    }
    int get_trainer_charges(){
        return trainer_charges;
    }
    float calculate_total_amount(){
        total_amount = gym_fee + trainer_charges;
        return total_amount;
    }
    float Total_amount(){
        return total_amount;
    }


};