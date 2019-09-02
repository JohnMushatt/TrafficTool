//
// Created by johnm on 9/1/2019.
//

#ifndef TRAFFIC_PROGRAM_GARAGE_H
#define TRAFFIC_PROGRAM_GARAGE_H

#include <string>
#include "DataObject.h"

class Garage: public DataObject {
public:
    Garage(int rc, int ts, int es, double un,std::string gn,std::string date, std::string time): DataObject(gn,date,time) {
        //Given values
        this->rental_cars = rc;
        this->total_spots=ts;
        this->empty_spots = es;
        this->utilization_num = un;
        this->garage_name = gn;
        this->date = date;
        this->time = time;
        //Derived values
        this->parked_cars = this->total_spots - empty_spots;
        this->utilization_num = (this->parked_cars / this->total_spots);
        determineUtilizationLevel();


    }
    virtual ~Garage() {

    }
private:
    int parked_cars,rental_cars,total_spots,empty_spots;
    double utilization_num;

    std::string garage_name,utilzation_level, date, time;
    void determineUtilizationLevel() {

        if(this->utilization_num >=.90) {
            this->utilzation_level = "HIGH";
        }
        else if(utilization_num >=.50) {
            this->utilzation_level = "MEDIUM";
        }
        else {
            this->utilzation_level = "LOW";
        }
    }
};


#endif //TRAFFIC_PROGRAM_GARAGE_H
