#ifndef ASTP_BF_B_B_DP_BRUTE_FORCE_H
#define ASTP_BF_B_B_DP_BRUTE_FORCE_H

#include <vector>
#include <string>

class Brute_force {

public:
    Brute_force(std::vector<std::vector<int>> graph_matrix);
    void perform_brute_force();
    void show_lowest_path();

    int get_lowest_cost();
    std::string get_lowest_path();

private:
    int current_cost;
    int lowest_cost;
    int num_of_vertices;
    std::vector<int> lowest_path;
    std::vector<std::vector<int>> graph;
    std::vector<int>permutations;

    void prepare_permutations();
};

#endif //ASTP_BF_B_B_DP_BRUTE_FORCE_H
