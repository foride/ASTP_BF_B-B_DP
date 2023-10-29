#ifndef ASTP_BF_B_B_DP_MENU_H
#define ASTP_BF_B_B_DP_MENU_H

#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include "Graph.h"
#include "Brute_force.h"
#include "Time_measure.h"
#include "Data_generator.h"

class Menu {

public:
    void show_menu();

private:
    bool is_digit(std::string input);


};

#endif //ASTP_BF_B_B_DP_MENU_H
