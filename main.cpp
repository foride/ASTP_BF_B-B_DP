#include "Menu.h"
#include "Graph.h"
#include "Dynamic_programming.h"

int main() {

    //Menu menu;
    //menu.show_menu();
    std::vector<std::vector<int>> g1;
    std::vector<int> g2;
    Graph graph(g1);
    graph.readGraph("../test_matrices/11x11.txt");
    graph.printGraph();
    Dynamic_programming dp(graph.getGraph());
    for (int i = 1; i < 11; i++) {
        g2.push_back(i);
    }
    int value;
    value = dp.perform_dp(0, g2, "");
    std::cout << value;
    std::unordered_map<std::string, int> x;
    x = dp.get_calulated_path_cost_map();
    for (const auto& pair: x) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}