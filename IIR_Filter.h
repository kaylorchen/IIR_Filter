//
// Created by kaylor on 19/08/08.
//

#ifndef FILTER_IIR_FILTER_H
#define FILTER_IIR_FILTER_H


class IIR_Filter {
public:
    IIR_Filter(float b0, float b1, float b2, float a1, float a2, float gain);
    void filter(short *value, int length);
private:
    float mB0, mB1, mB2, mA1, mA2, mGain;
    float xv[3];
    float yv[3];
};


#endif //FILTER_IIR_FILTER_H
