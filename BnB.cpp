#include "BnB.h"

BnB::BnB(std::vector<std::vector<int>> graph_graph) {

    this->graph = graph_graph;
    this->graph_size = graph.size();
    available_vertexes();
    upper_bound_path.push_back(0);
    upper_bound_value = perform_upper_bound();

}


int BnB::perform_upper_bound() {

    upper_bound_value = greedy_method(0,vetexes);
    return upper_bound_value;
}

int BnB::greedy_method(int row, std::vector<int> unvisited_vertexes) {

    if (unvisited_vertexes.size() == 1) {
        upper_bound_path.push_back(0);
        return graph[row][0];
    }
    int lowest_cost = INT_MAX;
    int index;
    for (int i = 0; i < graph.size(); i++) {
        if ((lowest_cost > graph[row][i]) && row != i) {
            auto it = std::find(unvisited_vertexes.begin(), unvisited_vertexes.end(), i);
            if (it != unvisited_vertexes.end()) {
                lowest_cost = graph[row][i];
                index = i;
            }

        }
    }
    upper_bound_path.push_back(index);
    unvisited_vertexes.erase(std::remove(unvisited_vertexes.begin(), unvisited_vertexes.end(), row), unvisited_vertexes.end());
    lowest_cost += greedy_method(index, unvisited_vertexes);
    return lowest_cost;
}

void BnB::available_vertexes() {

    for (int i = 0; i < graph.size(); i++) {
        vetexes.push_back(i);
    }

}


std::vector<int> BnB::bnb_dfs() {

    std::vector<int> vertices_to_check;

    for (int i = 1; i < graph_size; i++) {
        vertices_to_check.push_back(i);
    }

    std::vector<int> route;

    route.push_back(0);

    bnb_dfs_recursion(vertices_to_check, route);

    for (int i = 0; i < graph_size; i++) {
        best_route[i] = best_route[i];
    }

    return best_route;

}

void BnB::bnb_dfs_recursion(std::vector<int> vertices_to_check, std::vector<int> current_route) {

    std::vector<int> next_route = current_route;
    std::vector<int> next_vertices_to_check = vertices_to_check;

    int lower_bound=0, min_in_row=0;

    if (vertices_to_check.size() > 0) {
        for (int i = 0; i < vertices_to_check.size(); i++) {
            next_route.push_back(vertices_to_check[i]);
            next_vertices_to_check.erase(next_vertices_to_check.begin() + i);


            for (int j = 0; j < next_route.size() - 1; j++) {
                lower_bound += graph[next_route[j]][next_route[j + 1]];
            }


            if (next_vertices_to_check.size() > 0) {
                min_in_row = graph[next_route[next_route.size() - 1]][next_vertices_to_check[0]];

                for (int j = 0; j < vertices_to_check.size(); j++) {
                    if ((min_in_row > graph[next_route[next_route.size() - 1]][vertices_to_check[j]]) && (graph[next_route[next_route.size() - 1]][vertices_to_check[j]] != -1)) {
                        min_in_row = graph[next_route[next_route.size() - 1]][vertices_to_check[j]];
                    }
                }

                lower_bound += min_in_row;
            }

            for (int j = 0; j < next_vertices_to_check.size(); j++) {
                min_in_row = graph[next_vertices_to_check[j]][0];
                for (int k = 0; k < next_vertices_to_check.size(); k++) {
                    if ((graph[next_vertices_to_check[j]][next_vertices_to_check[k]] < min_in_row) && graph[next_vertices_to_check[j]][next_vertices_to_check[k]] != -1) {
                        min_in_row = graph[next_vertices_to_check[j]][next_vertices_to_check[k]];
                    }
                }
                lower_bound += min_in_row;
            }

            if (lower_bound < upper_bound_value) {
                bnb_dfs_recursion(next_vertices_to_check, next_route);
            }


            next_route = current_route;
            next_vertices_to_check = vertices_to_check;
            lower_bound = 0;
        }
    }
    else {

        lower_bound = distance(current_route, current_route.size());

        if (lower_bound < upper_bound_value) {
            upper_bound_value = lower_bound;
            best_route = current_route;
        }
    }

}

int BnB::distance(std::vector<int> route, int route_size) {

    int sum = 0;

    for (int i = 0; i < route_size-1; i++) {
        sum += graph[route[i]][route[i+1]];
    }
    sum += graph[route[route_size - 1]][route[0]];

    return sum;

}

void BnB::show_lowest_path() {

    std::cout << "BNB shortest path: \n";
    for (int i = 0; i < this->graph_size; i++) {
        std::cout << (best_route[i]) << " -> ";
    }
    std::cout << "0\n";
    std::cout << "Cost = " << upper_bound_value << "\n";

}
