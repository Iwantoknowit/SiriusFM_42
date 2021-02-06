//
//  main.cpp
//  Sirius
//
//  Created by Кирилл Мосиевич on 05.02.2021.
//

#include <iostream>
#include "DiffusionGBM.h"
#include "DiffusionOU.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    DiffusionGBM *gbm = new DiffusionGBM(1,1);
    DiffusionOU *ou = new DiffusionOU(1,1,1);
    double test = gbm -> mu(1,1);
    test = ou ->mu(1, 1);
    printf("%f \n",test);
    
    delete gbm;

    return 0;
}
