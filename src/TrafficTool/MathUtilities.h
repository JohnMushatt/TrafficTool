//
// Created by johnm on 8/29/2019.
//

#ifndef TRAFFIC_PROGRAM_MATHUTILITIES_H
#define TRAFFIC_PROGRAM_MATHUTILITIES_H


#include <type_traits>

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


#endif //TRAFFIC_PROGRAM_MATHUTILITIES_H
