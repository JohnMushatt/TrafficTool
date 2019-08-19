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
	TrafficDataObject(int route_id, std::string date, std::string time,std::string street_name, int parked_cars,
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
	parking_congestions getParkingCongestion() {
		return this->congestion;
	}

private:
	int route_id;
	std::string street_name, date,time;
	int parked_cars;
	int rental_cars;
	void setParkzingZone(std::string zone);
	void setParkingCongestion(std::string congstion);


	parking_zones zone;

	parking_congestions congestion;

};

#endif /* TRAFFICDATAOBJECT_H_ */
