/*
 * GmockMain.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: scottbae37
 */



#include "gmock/gmock.h"

int main(int argc, char* args[]){
	::testing::InitGoogleMock(&argc, args);
	return RUN_ALL_TESTS();
}
