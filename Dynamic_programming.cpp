#include "Dynamic_programming.h"


Dynamic_programming::Dynamic_programming(std::vector<std::vector<int>> graph_matrix)
{
    this->matrix = graph_matrix;
    this->instance_size = matrix.size();

}

std::vector<int> Dynamic_programming::dp() {

    std::vector<int> route;

    visited_all = (1 << instance_size) - 1;

    for (int i = 0; i < (1 << instance_size); i++) {
        for (int j = 0; j < instance_size; j++) {
            route.push_back(-1);
        }
        dp_memory.push_back(route);
        parents_memory.push_back(route);
        route.clear();
    }


    lowest_path_cost = dp_recursion(1, 0);
    best_route = get_path();

    return best_route;

}

int Dynamic_programming::dp_recursion(int mask, int current_vertex) {

    if (mask == visited_all) {
        return matrix[current_vertex][0];
    }

    if (dp_memory[mask][current_vertex] != -1) {
        return dp_memory[mask][current_vertex];
    }

    int cost = IMAX;

    for (int city = 0; city < instance_size; city++) {

        if ((mask & (1 << city)) == 0) {

            int current_cost = matrix[current_vertex][city] + dp_recursion(mask | (1 << city), city);
            cost = std::min(cost, current_cost);

            if (current_cost == cost) {
                dp_memory[mask][current_vertex] = cost;
                parents_memory[mask][current_vertex] = city;
            }
        }
    }

    return cost;
}

std::vector<int> Dynamic_programming::get_path()
{
    std::vector<int> lowest_route;
    int current_vertex = 0;
    int mask = 1;

    lowest_route.push_back(current_vertex);


    while (mask != visited_all) {
        current_vertex = parents_memory[mask][current_vertex];
        lowest_route.push_back(current_vertex);
        mask = mask | (1 << current_vertex);
    }

    return lowest_route;
}

void Dynamic_programming::show_lowest_path() {


    std::cout << "Dynamic programming shortest path: \n";
    for (int i = 0; i < this->instance_size; i++) {
        std::cout << (best_route[i]) << " -> ";
    }
    std::cout << "0\n";
    std::cout << "Cost = " << lowest_path_cost << "\n";

}

std::string Dynamic_programming::get_path_string() {

    std::string path;
    for (int i = 0; i < this->instance_size; i++) {

        path += std::to_string((best_route[i]));
        path += " -> ";
    }
    path += "0";

    return path;
}
