/*
 * DataParser.h
 *
 *  Created on: Aug 17, 2019
 *      Author: john
 */

#ifndef DATAPARSER_H_
#define DATAPARSER_H_

#include <vector>
#include <stdlib.h>
#include "TrafficDataObject.h"
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/regex.hpp>
#include <iterator>
#include <functional>

#define KBLU "\x1B[34m"
#define RST "\x1B[36m"

#define FBLU(x) KBLU x RST

class DataParser {

public:
	/**
	 * Constructor calls private openFile() with given argument
	 */
	DataParser(const char *file_name);
	/**
	 * Default Destructor
	 */
	virtual ~DataParser();
private:
	//2D Vector holding traffic data objects
	std::vector<TrafficDataObject*> data;
	/**
	 * Parses files
	 */
	bool parseFile(const char *file);
	/**
	 * Constructs a TrafficDataObject from parsed information
	 */
	bool buildTrafficDataObject(int route_id, std::string date,
			std::string time, std::string street_name, int parked_cars,
			int rental_cars, std::string parking_zone,
			std::string parking_congestion);

};

#endif /* DATAPARSER_H_ */
