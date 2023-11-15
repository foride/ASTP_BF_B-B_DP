#ifndef ASTP_BF_B_B_DP_BNB_H
#define ASTP_BF_B_B_DP_BNB_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

class BnB {

public:
    BnB(std::vector<std::vector<int>> graph_matrix);

    std::vector<int> bnb_dfs();
    void bnb_dfs_recursion(std::vector<int> vertices_to_check, std::vector<int> current_route);
    void show_lowest_path();

private:
    std::vector<std::vector<int>> graph;
    std::vector<int> vetexes;
    std::vector<int> upper_bound_path;
    std::vector<std::vector<int>> minimal_spanning_tree;
    std::vector<int> best_route;

    int graph_size;
    int upper_bound_value;

    void available_vertexes();
    int perform_upper_bound();

    int distance(std::vector<int> route, int route_size);
    int greedy_method(int row, std::vector<int> visited_vertexes);
};


#endif //ASTP_BF_B_B_DP_BNB_H
