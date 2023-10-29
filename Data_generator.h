#ifndef ASTP_BF_B_B_DP_DATA_GENERATOR_H
#define ASTP_BF_B_B_DP_DATA_GENERATOR_H


#include <vector>
#include <iostream>
#include <random>
#include <iomanip>
#include <fstream>

class Data_generator {

public:
    void generateDataToFile(int min, int max, int cities);
    std::vector<std::vector<int>> generate_data(int matrix_size);
};


#endif //ASTP_BF_B_B_DP_DATA_GENERATOR_H
