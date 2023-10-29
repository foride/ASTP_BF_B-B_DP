#include "Brute_force.h"
#include <climits>
#include <algorithm>
#include <iostream>

Brute_force::Brute_force(std::vector<std::vector<int>> graph_matrix) {

    this->graph = graph_matrix;
    this->num_of_vertices = graph_matrix.size();
    this->lowest_cost = INT_MAX;
    this->current_cost = 0;

    this->lowest_path = std::vector<int>(this->num_of_vertices,0);
    prepare_permutations();
}

// Wykonuje przeglad zupelny
void Brute_force::perform_brute_force() {

    do {
        current_cost = 0;
        current_cost += graph[0][permutations[0] + 1];
        for (int i = 0; i < num_of_vertices - 2; ++i) {
            current_cost += graph[(permutations[i] + 1)][(permutations[i + 1] + 1)];
        }
        current_cost += graph[permutations.back() + 1][0];

        if (current_cost < lowest_cost) {
            this->lowest_cost = current_cost;
            this->lowest_path = permutations;


        }

    } while (std::next_permutation(permutations.begin(), permutations.end()));
}

// Drukuje na konsole najmniej kosztujaca sciezke i jej wartosc
void Brute_force::show_lowest_path() {

    if (lowest_cost != INT_MAX)
    {
        std::cout << "Brute force shortest path: \n";
        std::cout << "0 -> ";
        for (int i = 0; i < this->num_of_vertices - 1; i++)
        {
            std::cout << (lowest_path[i] + 1) << " -> ";
        }
        std::cout << "0\n";
        std::cout << "Cost = " << lowest_cost << "\n";
    }
}

int Brute_force::get_lowest_cost() {
    return this->lowest_cost;
}

std::string Brute_force::get_lowest_path() {

    std::string lowest_path_s = "0 -> ";
    for (int i = 0; i < this->num_of_vertices - 1; i++)
    {
        lowest_path_s +=  std::to_string((lowest_path[i] + 1))+ " -> ";
    }
    lowest_path_s += "0";

    return lowest_path_s;
}

void Brute_force::prepare_permutations() {

    for (int i = 0; i < num_of_vertices - 1; ++i) {
        permutations.push_back(i);
    }
}
