//
// Created by joaoped2 on 11/17/23.
//

#include "Harl.hpp"

int checkIndex(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int j = 0; j < 4; j++)
        if (levels[j] == level)
            return (j);
    return (4);
}

void    checkLevel(Harl harl, std::string level) {
    int index = 0;

    index = checkIndex(level);
    switch (index){
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
    }
}

int main(int ac, char **av) {
    Harl harl;

    if (ac == 2)
        checkLevel(harl, av[1]);
    else
        std::cout << "Wrong Arguments" << std::endl;
    return (0);
}