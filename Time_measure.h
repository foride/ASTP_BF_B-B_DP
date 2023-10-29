#ifndef ASTP_BF_B_B_DP_TIME_MEASURE_H
#define ASTP_BF_B_B_DP_TIME_MEASURE_H

class Time_measure {

public:
    Time_measure(int num_of_tests);

    long long test_brute_force_random_matrices(int matrix_size);
    long long test_brute_force(std::vector<std::vector<int>> matrix);
private:
    int num_of_tests;

};

#endif //ASTP_BF_B_B_DP_TIME_MEASURE_H
