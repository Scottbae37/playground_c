/******************************************************************************
 *   Autonomous Vehicle Technology Lab, LG ELECTRONICS INC., SEOUL, KOREA
 *   Copyright(c) 2017 by LG Electronics Inc.
 *
 *   All rights reserved. No part of this work may be reproduced, stored in a
 *   retrieval system, or transmitted by any means without prior written
 *   Permission of LG Electronics Inc.
 *****************************************************************************/
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
