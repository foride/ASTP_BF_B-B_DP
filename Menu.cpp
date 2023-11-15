#include "Menu.h"
#include "Dynamic_programming.h"
#include "BnB.h"

void Menu::show_menu() {
    std::vector<std::vector<int>> init_vector;
    Data_generator generator;
    Graph graph(init_vector);

    std::string fromFile;
    std::string choice_s;

    while (true) {
        std::cout << "Problem komiwojazera rozwiazywany metoda B&B i DP.\nAutor: Michal Lewandowski #264458\n\n";
        std::cout << "0 - Wyjdz z programu\n";
        std::cout << "1 - Wczytaj macierz z pliku\n";
        std::cout << "2 - Wygeneruj macierz\n";
        std::cout << "3 - Wyswietl ostatnio wczytana z pliku lub wygenerowana macierz\n";
        std::cout << "4 - Uruchom algorytm podzialu i ograniczen (B&B) dla ostatnio wczytanej lub wygenerowanej macierzy i wyswietl wyniki\n";
        std::cout << "5 - Uruchom algorytm programowania dynamicznego (DP) dla ostatnio wczytanej lub wygenerowanej macierzy i wyswietl wyniki\n";
        std::cout << ">";

        std::cin >> choice_s;
        while (!is_digit(choice_s)) {
            std::cout << "Podany ciag znakow nie jest liczba!\nWpisz liczbe\n>";
            std::cin >> choice_s;
        }
        int choice = std::stoi(choice_s);

        switch (choice) {
            case 0:
                exit(0);
            case 1:

                std::cout << "Podaj nazwe pliku do wczytania\n>";
                std::cin >> choice_s;
                graph.readGraph(choice_s);

                break;
            case 2:
                std::cout << "Podaj wielkosc macierzy (rozmiar N)\n>";
                std::cin >> choice_s;
                while (!is_digit(choice_s)) {
                    std::cout << "Podany ciag znakow nie jest liczba!\nWpisz liczbe\n>";
                    std::cin >> choice_s;
                }
                graph.setGraph(generator.generate_data(atoi(choice_s.c_str())));
                break;
            case 3:

                graph.printGraph();
                break;
            case 4:
            {
                Dynamic_programming dp(graph.getGraph());
                auto start = std::chrono::high_resolution_clock::now();
                dp.dp();
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                std::cout << "Czas wykonywania algorytmu: " << duration.count() << " mikrosekund" << "\n";
                dp.show_lowest_path();
                break;
            }
            case 5:
            {
                BnB bnb(graph.getGraph());
                auto start = std::chrono::high_resolution_clock::now();
                bnb.bnb_dfs();
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                std::cout << "Czas wykonywania algorytmu: " << duration.count() << " mikrosekund" << "\n";
                bnb.show_lowest_path();

            }
                break;
            default:
                std::cout << "Program nie zawiera funkcji dla podanej liczby!\n";
                break;
        }
    }

}

bool Menu::is_digit(std::string input) {

    for (int i = 0; i<input.size(); i++) {
        if (isdigit(input[i]) == false) {
            return false;
        }
    }
    return true;

}