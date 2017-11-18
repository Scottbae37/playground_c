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

