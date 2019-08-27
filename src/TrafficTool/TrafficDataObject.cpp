/*
 * TrafficDataObject.cpp
 *
 *  Created on: Aug 17, 2019
 *      Author: john
 */

#include "TrafficDataObject.h"

#include <strings.h>
#include <sstream>

TrafficDataObject::TrafficDataObject(int route_id, std::string date, std::string time, std::string street_name,
                                     int parked_cars, int rental_cars, std::string zone,
                                     std::string congestion) {
    this->route_id = route_id;
    this->date = date;
    this->time = time;
    this->street_name = street_name;
    this->parked_cars = parked_cars;
    this->rental_cars = rental_cars;
    setParkingZone(zone);
    setParkingCongestion(congestion);

}


void TrafficDataObject::setParkingCongestion(std::string congestion) {
    if (congestion.compare("low") == 0) {
        this->congestion = LOW;
    } else if (congestion.compare("medium") == 0) {
        this->congestion = MEDIUM;
    } else if (congestion.compare("high") == 0) {
        this->congestion = HIGH;
    }
}

std::string TrafficDataObject::toString() {
    std::ostringstream oss;

    oss << "Route id: " << this->getRouteID() << " Date: "
        << this->getDate() << " Time: " << this->getTime() << "\nStreet Name: "
        << this->getStreetName() << " Parked Cars: " << this->getParkedCars() << " Rental Cars: "
        << this->getRentalCars()
        << " Parking Zone: " << this->stringifyParking() << " Congestion Level: " << this->stringifyCongestion();
    return oss.str();
}

void TrafficDataObject::setParkingZone(std::string zone) {
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

TrafficDataObject::~TrafficDataObject() {
    // TODO Auto-generated destructor stub
}
