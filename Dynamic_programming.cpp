#include <iostream>
#include <utility>
#include "Dynamic_programming.h"

Dynamic_programming::Dynamic_programming(std::vector<std::vector<int>> graph_matrix) {
    this->graph = std::move(graph_matrix);
    //this->graph_size = graph_matrix.size();
    //this->lowest_cost_path = INT_MAX;


}

int Dynamic_programming::perform_dp(int k, std::vector<int> unvisited, std::string current_path) {

    int local_lowest = INT_MAX;
    int path_cost;

    if (unvisited.empty()) {
        return graph[0][k];
    }

    if (calculated_path_cost_map.find(current_path) != calculated_path_cost_map.end()) {
        path_cost = calculated_path_cost_map[current_path];
        if (local_lowest > path_cost) {
            local_lowest = path_cost;
        }
        return local_lowest;
    }

    for (const int& vertex: unvisited) {
        std::string path = "g(";
        std::vector<int> temp;
        path += std::to_string(vertex);
        path += ", {";
        for (const int& number: unvisited) {
            if (vertex != number) {
                temp.push_back(number);
                path += std::to_string(number);
                path += ",";
            }
        }
        path += "})";

        path_cost =  perform_dp(vertex, temp, path);
        calculated_path_cost_map[path] = path_cost;
        path_cost += graph[vertex][k];

        if (local_lowest > path_cost) {
            local_lowest = path_cost;
        }
    }

    return local_lowest;
}

std::unordered_map<std::string, int> Dynamic_programming::get_calulated_path_cost_map() {
    return calculated_path_cost_map;
}


