#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

#include "BnB.h"

BnB::BnB(std::vector<std::vector<int>> graph_matrix) {

    this->graph = graph_matrix;
    available_vertexes();
    upper_bound_path.push_back(0);
    upper_bound_value = perform_upper_bound();
    lower_bound_value = perform_lower_bound();

    std::cout << "lower bound: " << lower_bound_value << "\n";
    std::cout << "upper bound: " << upper_bound_value << "\n";

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

int BnB::perform_lower_bound() {

    int n = graph.size();
    std::vector<std::vector<int>> mst(n, std::vector<int>(n, 0)); // Initialize MST matrix with zeros
    std::vector<int> key(n, INT_MAX); // Key values used to pick minimum weight edge in cut
    std::vector<bool> inMST(n, false); // To represent set of vertices included in MST

    // Start with the first node
    key[1] = 0;
    int mstCost = 0; // Total cost of MST

    // Construct MST with (n-1) edges
    for (int count = 0; count < n; ++count) {
        // Find the minimum key vertex from the set of vertices not yet included in MST
        int u = -1;

        for (int i = 0; i < n; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        // Include the picked vertex in MST
        inMST[u] = true;
        if (key[u] != 0) {
            mstCost += key[u];
        }
        // Add the key value to MST cost

        // Update key values according to the chosen vertex
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                mst[u][v] = graph[u][v];
                mst[v][u] = graph[v][u];
            }
        }
    }
    minimal_spanning_tree = mst;
    return mstCost;

}


