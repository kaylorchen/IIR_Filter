//
// Created by Kaylor on 19/08/08.
//

#include <iostream>
#include "IIR_Filter.h"

IIR_Filter::IIR_Filter(float b0, float b1, float b2, float a1, float a2, float gain)
{
    mB0 = b0;
    mB1 = b1;
    mB2 = b2;
    mA1 = a1;
    mA2 = a2;
    mGain = gain;
    xv[0] = 0;
    xv[1] = 0;
    xv[2] = 0;
    yv[0] = 0;
    yv[1] = 0;
    yv[2] = 0;
//    std::cout << mB0 << std::endl;
//    std::cout << mB1 << std::endl;
//    std::cout << mB2 << std::endl;
//    std::cout << mA1 << std::endl;
//    std::cout << mA2 << std::endl;
//    std::cout << mGain << std::endl;
//    std::cout << "******"<< std::endl;
}

void IIR_Filter::filter(short *value, int length) {
    for (int i = 0; i < length; ++i) {
        xv[0] = xv[1]; xv[1] = xv[2];
        xv[2] = (*(value + i))*mGain;
        yv[0] = yv[1]; yv[1] = yv[2];;
        yv[2] = mB0*xv[2] + mB1*xv[1] + mB2*xv[0]- mA1* yv[1] - mA2*yv[0];
        *(value + i) = yv[2];
    }
}