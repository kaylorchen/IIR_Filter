#include <iostream>
#include "fstream"
#include "IIR_Filter.h"
static void lowpassfilter(short *value, int length);
static void highpassfilter(short *value, int length);
int main() {
    std::ifstream  inputfile;
    std::ofstream outputfile;
    std::string tmp;
    short buffer;

    IIR_Filter lowpass(1, 2, 1, -1.85214648539594, 0.862348626030081,0.00255053515853629);  // Fs = 48000, Fc=800
    IIR_Filter highpass(1, -2, 1, -1.9629800893893394, 0.96365298422370527,0.9816582684032612); // Fs=48000, Fc=200
    inputfile.open("../record-before.txt",std::ios::in);
    outputfile.open("../result.txt",std::ios::out);
    while (!inputfile.eof())
    {
        getline(inputfile, tmp);
        buffer = atoi(tmp.c_str());
        lowpass.filter(&buffer,1);
        highpass.filter(&buffer,1);
        outputfile << buffer << std::endl;
    }
    inputfile.close();
    outputfile.close();
    return 0;
}
