#ifndef ASTP_BF_B_B_DP_DYNAMIC_PROGRAMMING_H
#define ASTP_BF_B_B_DP_DYNAMIC_PROGRAMMING_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

class Dynamic_programming {

public:

    Dynamic_programming(std::vector<std::vector<int>> graph_matrix);

    std::vector<int> dp();

    int dp_recursion(int mask, int current_vertex);
    void show_lowest_path();
    std::vector<int> get_path();
    std::string get_path_string();

private:

    int instance_size;

    std::vector<std::vector<int>> parents_memory;

    std::vector<std::vector<int>> matrix;

    int IMAX = INT_MAX;

    int visited_all{};

    std::vector<std::vector<int>> dp_memory;
    std::vector<int> best_route;
    int lowest_path_cost{};

};


#endif //ASTP_BF_B_B_DP_DYNAMIC_PROGRAMMING_H