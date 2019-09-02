/*
 * TrafficDataObject.h
 *
 *  Created on: Aug 17, 2019
 *      Author: john
 */

#ifndef TRAFFICDATAOBJECT_H_
#define TRAFFICDATAOBJECT_H_

#include "DataObject.h"
#include <string>
#include <iostream>
#include <sstream>

class TrafficDataObject : public DataObject {
protected:
    enum parking_congestions {
        LOW, MEDIUM, HIGH
    };
    enum parking_zones {
        RED, BLUE, GREEN, ORANGE
    };
public:
    TrafficDataObject(int route_id, std::string date, std::string time, std::string street_name, int parked_cars,
                      int rental_cars, std::string zone, std::string congestion) : DataObject(street_name, date, time) {
        this->route_id = route_id;
        this->parked_cars = parked_cars;
        this->rental_cars = rental_cars;
        setParkingZone(zone);
        setParkingCongestion(congestion);
    }

    virtual ~TrafficDataObject() {

    }

    int getRouteID() {
        return this->route_id;
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

    /**
     * Converts object into string notation
     * @return std::string object version of current 'this' object
     */
    std::string toString() {
        std::ostringstream oss;

        oss << "Route id: " << this->getRouteID() << " Date: "
            << this->getDate() << " Time: " << this->getTime() << "Street Name: "
            << this->getName() << " Parked Cars: " << this->getParkedCars() << " Rental Cars: "
            << this->getRentalCars()
            << " Parking Zone: " << this->stringifyParking() << " Congestion Level: " << this->stringifyCongestion();
        return oss.str();
    }

private:
    int route_id;
    int parked_cars;
    int rental_cars;

    void setParkingZone(std::string zone) {
        if (zone.compare("blue") == 0) {
            this->zone = BLUE;
        } else if (zone.compare("red") == 0) {
            this->zone = RED;
        } else if (zone.compare("green") == 0) {
            this->zone = GREEN;
        } else if (zone.compare("orange") == 0) {
            this->zone = ORANGE;
        }
    }

    void setParkingCongestion(std::string congestion) {
        if (congestion.compare("low") == 0) {
            this->congestion = LOW;
        } else if (congestion.compare("medium") == 0) {
            this->congestion = MEDIUM;
        } else if (congestion.compare("high") == 0) {
            this->congestion = HIGH;
        }
    }


    parking_zones zone;

    parking_congestions congestion;

};

#endif /* TRAFFICDATAOBJECT_H_ */
