//
// Created by Juanito on 18/12/2023.
//

#include "Animal.hpp"

Animal::Animal() : type("Default") {
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(std::string type) : type(type){
    std::cout << "Animal Parameter Constructor Called" << std::endl;
}

Animal::Animal(const Animal &cpy) {
    *this = cpy;
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
    this->type = animal.type;
    std::cout << "Animal Copy assignment operator called" << std::endl;
}

std::string Animal::getType() const {
    return (this->type);
}

void Animal::setType(std::string type) {
    this->type = type;
}

const void Animal::makeSound() {
    std::cout << "Random Alien Sound" << std::endl;
}