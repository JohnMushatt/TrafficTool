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
DataParser::DataParser() {
    //jsonParser(file_name);
    //parseFile(file_name);
}

bool DataParser::jsonParser(const char *file) {
    try {
        //String stream
        std::stringstream stream;
        //Property stream
        boost::property_tree::ptree pt;
        //Json parser
        boost::property_tree::read_json(file, pt);
        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("route_id"))
        {
            assert(v.first.empty());
            std::cout<< v.first.data() <<std::endl;
            std::cout<< v.second.data() <<std::endl;

        }
        //
        printTree(pt);
        return true;
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

void DataParser::printTree(boost::property_tree::ptree const &pt) {
    using boost::property_tree::ptree;
    ptree::const_iterator end = pt.end();
    for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
        std::cout << it->first << ": " << it->second.get_value<std::string>() << std::endl;
        printTree(it->second);
    }
}

/**
 * Parse given file for data, it will add newly created DataTrafficObject to a vector container
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
            current_line.clear();
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
        }

    } else {
        throw std::runtime_error("Failed to open file");
    }
    std::cout << "Logging info." << std::endl << "Number of parsed rows: " << row_count
              << std::endl << "Parsed data\n-------------------------------------" << std::endl;
    for (std::size_t i = 0; i < data.size(); i++) {
        std::cout << data.at(i)->toString() << std::endl;
    }

    std::cout << "-------------------------------------" << std::endl;

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
 * @return True if successfully added data to vector container
 */
bool DataParser::buildTrafficDataObject(int route_id, std::string date,
                                        std::string time, std::string street_name, int parked_cars,
                                        int rental_cars, std::string parking_zone,
                                        std::string parking_congestion) {
    //Create a unique pointer to the current piece of data
    TrafficDataObject *current_data = new TrafficDataObject(route_id, date,
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
    //Call the delete method on all current objects in the vector
    data.clear();
    //Resize the vector to 0, freeing up all memory
    data.shrink_to_fit();
}

void DataParser::displayData() {
    //mglGraph graph;
    //graph.FPlot("sin(pi*x)");
    //graph.WriteFrame("test.png");
}

double DataParser::computeAverageParkedCars() {

    std::vector<int> values;
    std::map<std::string, int> parked_cars;
    for (auto &element : data) {
        std::string str(element->getName());
        std::pair<std::string, int> p(str, element->getParkedCars());
        if (parked_cars.find(str) == parked_cars.end()) {
            parked_cars.insert(p);
        } else {
            int new_val = element->getParkedCars() + parked_cars.at(str);

            parked_cars.insert(std::pair<std::string, int>(p.first, new_val));
        }
    }
    for (auto &element : parked_cars) {
        values.push_back(element.second);
    }
    const double final_val = computeAverage(values);
    return final_val;
}

/**
 * Returns one or more TrafficDataObjects that contain the max number of parked cars (Not max capacity)
 * @return Vector container one or more TrafficData objects that have the max number of parked cars in the set
 */
std::vector<TrafficDataObject *> DataParser::getParkingMax() {

    std::vector<double> values;
    for (auto element : data) {
        values.push_back(element->getParkedCars());
    }
    int max = findMax(values);

    std::vector<TrafficDataObject *> list;

    for (auto element :  data) {
        int val = element->getParkedCars();
        if (val == max) {
            list.push_back(element);
        }
    }
    return list;
}

int main(int argc, char **argv) {
    std::cout << "Running data tool with arguments: " << argv[1] << std::endl;

    if (argc <= 1) {
        std::cout << "Re-run program with 1 or more arguments" << std::endl;
        return EXIT_FAILURE;
    }
    const char *file_name = argv[1];
    std::unique_ptr<DataParser> parser(new DataParser());
    if(parser->jsonParser(file_name)) {


        parser->displayData();


        //Average # of parked cars amongst streets
        std::cout << "Average # of parked cars on streets: " << parser->computeAverageParkedCars() << std::endl;

        //Max number of parked cars
        std::vector<TrafficDataObject *> ls = parser->getParkingMax();
        for (auto element : ls) {
            std::cout << "Garage: " << element->getName() << "\tNumber of Parked Cars: " << element->getParkedCars()
                      << std::endl;
        }

        //Find the mode of parked cars

        std::unique_ptr<MemoryTools> mem_tool;
        mem_tool->VirtualMemoryProfile();
        //Clean up memory
        std::cout << "Cleaning up memory" << std::endl;
        parser.reset();
        std::cout << "Program has finished, now exiting" << std::endl;
        return EXIT_SUCCESS;
    }
    else {
        return EXIT_FAILURE;
    }
}