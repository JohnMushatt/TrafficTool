/*
 * DataParser.cpp
 *
 *  Created on: Aug 17, 2019
 *      Author: john
 */

#include "DataParser.h"

/**
 * Constructor for DataParser
 * @param file_name File path to be parsed
 */
DataParser::DataParser(const char *file_name) {

    parseFile(file_name);
}

/**
 * Parse file for data
 * @param file file path to be parsed
 * @return True if file is opened and parsed, false if otherwise
 */
bool DataParser::parseFile(const char *file) {
    unsigned int row_count = 0;
    int route_id, parked_cars, rental_cars;
    std::string street_name, date, time, zone, congestion;
    std::fstream data_file(file);

    if (data_file.is_open()) {
        std::cout << "Successfully opened the file" << std::endl;
        std::string line;
        //Setup regex to look for all elements in between ','
        std::regex reg("[^,]+");
        //Setup matching regex
        std::smatch m;
        std::vector<std::string> current_line;
        while (std::getline(data_file, line)) {
            row_count++;
            //While there are still results to process
            while (std::regex_search(line, m, reg)) {
                for (auto x : m) {
                    current_line.push_back(x);
                }
                line = m.suffix().str();
            }
            route_id = std::stoi(current_line.at(0));
            date = current_line.at(1);
            time = current_line.at(2);
            street_name = current_line.at(3);
            parked_cars = std::stoi(current_line.at(4));
            rental_cars = std::stoi(current_line.at(5));
            zone = current_line.at(6);
            congestion = current_line.at(7);
            buildTrafficDataObject(route_id, date, time, street_name,
                                   parked_cars, rental_cars, zone, congestion);
            std::cout<<data.at(data.size()-1)->toString()<<std::endl;
        }

    } else {
        throw std::runtime_error("Failed to open file");
    }
    std::cout << "Logging info." << std::endl << "Number of parsed rows: " << row_count
              << std::endl;
   // for(std::size_t i = 0; i < data.size(); i++) {
        //std::cout << data.at(i)->toString()<<std::endl;
    //}
    return true;
}

/**
 * Consturcts a TrafficDataObject and inserts it into a container
 * @param route_id Given route id
 * @param date Given date
 * @param time  Given time
 * @param street_name   Given street name
 * @param parked_cars   Given parked cars
 * @param rental_cars   Given rental cars
 * @param parking_zone  Given parking zone
 * @param parking_congestion    Given parking congestion
 * @return True if succesfully added data to vector container
 */
bool DataParser::buildTrafficDataObject(int route_id, std::string date,
                                        std::string time, std::string street_name, int parked_cars,
                                        int rental_cars, std::string parking_zone,
                                        std::string parking_congestion) {
    //Create a unique pointer to the current piece of data
    TrafficDataObject *current_data= new TrafficDataObject(route_id, date,
                                                                          time, street_name, parked_cars, rental_cars,
                                                                          parking_zone,
                                                                          parking_congestion);

    if (!current_data) {
        throw std::runtime_error("Failed to create data object, check data file");

    }
    current_data->toString();
    data.push_back(current_data);
    return true;

}

/**
 * Destructor for DataParser
 */
DataParser::~DataParser() {

}

void DataParser::displayData() {

    //auto hist = boost::histogram::make_histogram(boost::histogram::axis::regular<>(6,-1,2,"x"));
}

int main(int argc, char **argv) {
    std::cout << "Running data tool with arguments: " << argv[1] << std::endl;

    if (argc <= 1) {
        std::cout << "Re-run program with 1 or more arguments" << std::endl;
        return EXIT_FAILURE;
    }
    const char *file_name = argv[1];
    std::unique_ptr<DataParser> parser(new DataParser(file_name));

    return EXIT_SUCCESS;
}
