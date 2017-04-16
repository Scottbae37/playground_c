/*
 * GitTest.c
 *
 *  Created on: Apr 16, 2017
 *      Author: scottbae37
 */


#include <stdio.h>
#include "../include/GitTest.h"

int main(int argc, char*args[])
{
	funcA();
	funcAA();
	funcB();
	return 0;
}

void funcA()
{
	printf("funcA() called\n");
}

void funcAA(){
	printf("funcAA() called\n");
}

void funcB()
{
	printf("funcBB() called\n");
}
