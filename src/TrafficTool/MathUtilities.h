//
// Created by johnm on 8/29/2019.
//

#ifndef TRAFFIC_PROGRAM_MATHUTILITIES_H
#define TRAFFIC_PROGRAM_MATHUTILITIES_H


#include <type_traits>
#include <math.h>
#include <float.h>
#include <boost/sort/spreadsort/spreadsort.hpp>
/**
 * Computes the average value over the given set
 * @tparam Container Container Template type for container
 * @param list Set to compute average of
 * @return Average of the provided set
 */
template<typename Container>
static double computeAverage(Container list) {
    //static_assert(std::is_same<typename Container::value_type, double>::value, "Please enter only doubles!");
    double final_value = 0.0;
    int list_size = 0;
    for (auto element : list) {
        final_value += element;
        list_size++;
    }

    final_value = final_value / list_size;

    return final_value;
}

/**
 * Finds max element in a generic container
 * @tparam Container Template type for container
 * @param list Set to find maximum element in
 * @return Max element in the set/container
 */
template<typename Container>
static double findMax(Container list) {
    //Minimum val
    double max = DBL_MIN;
    for (auto element : list) {
        if (element >= max) {
            //Set new val
            max = element;
        }
    }
    return max;
}
template<typename Container>
static double findMin(Container list) {
    //Minimum val
    double min = DBL_MAX;
    for (auto element : list) {
        if (element <= min) {
            //Set new val
            min = element;
        }
    }
    return min;
}

template<typename Container>
static double findMode(Container list) {
    double mode =0;
    int count =0;

    //Perform spreadsort on the list || Provided by Boost::sort::spreadsort
    boost::sort::spreadsort::spreadsort(&list);




}
#endif //TRAFFIC_PROGRAM_MATHUTILITIES_H
