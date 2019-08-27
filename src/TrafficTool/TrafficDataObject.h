/*
 * TrafficDataObject.h
 *
 *  Created on: Aug 17, 2019
 *      Author: john
 */

#ifndef TRAFFICDATAOBJECT_H_
#define TRAFFICDATAOBJECT_H_

#include <string>
#include <iostream>

class TrafficDataObject {
protected:
    enum parking_congestions {
        LOW, MEDIUM, HIGH
    };
    enum parking_zones {
        RED, BLUE, GREEN, ORANGE
    };
public:
    TrafficDataObject(int route_id, std::string date, std::string time, std::string street_name, int parked_cars,
                      int rental_cars, std::string zone, std::string congestion);

    virtual ~TrafficDataObject();

    int getRouteID() {
        return this->route_id;
    }

    std::string getStreetName() {
        return this->street_name;
    }

    int getParkedCars() {
        return this->parked_cars;
    }

    int getRentalCars() {
        return this->rental_cars;
    }

    parking_zones getParkingZone() {
        return this->zone;
    }
    std::string getDate() {
        return this->date;
    }
    std::string getTime() {
        return this->time;
    }
    parking_congestions getParkingCongestion() {
        return this->congestion;
    }

    std::string stringifyParking() {
        if (zone == RED) {
            return std::string("RED");
        } else if (zone == BLUE) {
            return std::string("BLUE");
        } else if (zone == GREEN) {
            return std::string("GREEN");
        } else if (zone == ORANGE) {
            return std::string("ORANGE");
        }
        return std::string("DOES NOT EXIST");
    }

    std::string stringifyCongestion() {
        if (congestion == LOW) {
            return "LOW";
        } else if (congestion == MEDIUM) {
            return "MEDIUM";
        } else if (congestion == HIGH) {
            return "HIGH";
        }
        return "DOES NOT EXIST";
    }
    std::string toString();

private:
    int route_id;
    std::string street_name, date, time;
    int parked_cars;
    int rental_cars;

    void setParkingZone(std::string zone);

    void setParkingCongestion(std::string congestion);


    parking_zones zone;

    parking_congestions congestion;

};

#endif /* TRAFFICDATAOBJECT_H_ */
