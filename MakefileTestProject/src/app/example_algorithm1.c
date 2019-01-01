//
// Created by scottbae37 on 8/28/17.
//

#include "example_algorithm1.h"
double computeDistanceLatLong(double lat, double longi){
#define UNKOWN_ERR 0
    if(longi == 0)
        return UNKOWN_ERR;
    return lat > 0 ? 1.1: 2.2;

}

int computeA(MyStruct_t* data){
    return data->lat > 0 ? 1: 0;
}

