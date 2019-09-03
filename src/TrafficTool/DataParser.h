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
#include <algorithm>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/regex.hpp>
#include "MathUtilities.h"
#include "MemoryTools.h"
#include <mgl2/mgl.h>
#include <iterator>
#include <functional>
#include <stdexcept>
#define KBLU "\x1B[34m"
#define RST "\x1B[36m"

#define FBLU(x) KBLU x RST

class DataParser {

public:
	/**
	 * Constructor calls private openFile() with given argument
	 */
	DataParser();
	/**
	 * Default Destructor
	 */
	virtual ~DataParser();

	void displayData();
	std::vector<TrafficDataObject *>   getParkingMax();
	double computeAverageParkedCars();
    /**
     * Parses files
     */
    bool parseFile(const char *file);
    /**
	 * Parses the file via json property tree
	 * @param file File to parse
	 * @return True if successfully parsed the file into a property tree
	 */
    bool jsonParser(const char *file);

private:
	//2D Vector holding traffic data objects
	std::vector<TrafficDataObject *> data;


	void printTree(boost::property_tree::ptree const& pt);
	/**
	 * Constructs a TrafficDataObject from parsed information
	 */
	bool buildTrafficDataObject(int route_id, std::string date,
			std::string time, std::string street_name, int parked_cars,
			int rental_cars, std::string parking_zone,
			std::string parking_congestion);

};

#endif /* DATAPARSER_H_ */
