#include "Data_generator.h"

void Data_generator::generateDataToFile(int min, int max, int cities) {
    int val;
    int self_city_index = 0;

    std::random_device rd; // non-deterministic generator
    std::mt19937 gen(rd()); // random engine seeded with rd()
    std::uniform_int_distribution<> dist(min, max);
    std::ofstream outfile("../data13.txt");


    if (outfile.is_open()) { // Check if the file is opened successfully
        for (int q = 0; q < cities; q++) {
//            outfile << "   ";
            for (int i = 0; i < self_city_index; i++) {
                val = dist(gen); // pass the generator to the distribution
                if (val < min)
                    min = val;
                if (val > max)
                    max = val;
                outfile << std::setw(15) << std::right << val; // Write to the file
            }

            //putting -1 on diagonal
            outfile << std::setw(15) << std::right << "-1";
            for (int i = self_city_index; i < (cities - 1); i++) {
                val = dist(gen); // pass the generator to the distribution
                if (val < min)
                    min = val;
                if (val > max)
                    max = val;
                outfile << std::setw(15) << std::right << val; // Write to the file
            }




            outfile << std::endl;
            self_city_index++;
        }

        outfile.close(); // Close the file stream
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }


}

std::vector<std::vector<int>> Data_generator::generate_data(int matrix_size) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 200);
    std::vector<std::vector<int>>  temp_matrix(matrix_size, std::vector<int>(matrix_size, 0));

    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            if (i == j) {
                temp_matrix[i][j] = -1;
            } else {
                temp_matrix[i][j] = random(gen);
            }
        }
    }

    return temp_matrix;
}