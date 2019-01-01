#include <stdio.h>
#include "example_tcMain.h"
#include "example_algorithm1.h"


int main() {
    printf("Hello, World!\n");
    return 0;
}
void printfBjs(){
    printf("Call compute function in algorithm1\n");
    printf("%lf\n", computeDistanceLatLong(3.11, 3.22));
}

int getVer(int input){
    return input > 0 ? 1 : 0;
}


