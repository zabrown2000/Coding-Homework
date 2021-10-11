//3/10/21
//#include <iostream>
#include<stdio.h>
#include "Math.h"


int main()    //a c++ function, has things c doesn't have, ::, cout, <<
{
    //std::cout << "Hello World!\n";
    printf("Hello World!\n");
    //if run WITH debugging it closes right away, so put break point so can see result, or run without debugging
    //change setting by tools->options->debugging->general->uncheck auto close at end of program
    
    //before call max need to know what to do, so document
    int m = Max(10, 3); //as use it, documnetation shows up
    return 0;
}

//changed to .c and now have to fix code to be c