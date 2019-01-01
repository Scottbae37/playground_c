//
// Created by scottbae37 on 8/28/17.
//

#ifndef CMAKE_TEST_PROJECT_COMPUTEDISTANCELANLONG_H
#define CMAKE_TEST_PROJECT_COMPUTEDISTANCELANLONG_H

typedef struct{
    double lat;
    double longi;
} MyStruct_t;


double computeDistanceLatLong(double lat, double longi);
int computeA(MyStruct_t* data);
#endif //CMAKE_TEST_PROJECT_COMPUTEDISTANCELANLONG_H
