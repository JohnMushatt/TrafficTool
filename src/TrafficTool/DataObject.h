//
// Created by johnm on 9/2/2019.
//

#ifndef TRAFFIC_PROGRAM_DATAOBJECT_H
#define TRAFFIC_PROGRAM_DATAOBJECT_H
#include <string>
#endif //TRAFFIC_PROGRAM_DATAOBJECT_H
class DataObject {
public:
    DataObject(std::string name, std::string date, std::string time) {
        this->name = name;
        this->date = date;
        this->time = time;
    }

    std::string getName() {
        return this->name;
    };
    std::string getDate() {
        return this->date;
    }
    std::string getTime() {
        return this->time;
    }
    virtual ~DataObject() {

    }
private:
    std::string name, date, time;

};