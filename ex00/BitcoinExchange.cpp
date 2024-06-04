/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:27:06 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/03 16:03:00 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _file("Default"), _list() {
    filereader();
}

BitcoinExchange::BitcoinExchange(const std::string &file) : _file(file), _list() {
    filereader();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
    (void)cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy) {
    (void)cpy;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}

int is_leap_year(int year) {
    if (year % 4 != 0) {
        return (0);
    }
    else if (year % 100 == 0 && year % 400 != 0) {
        return (0);
    }
    else
        return (1);
}

bool check_digits(const std::string &reader) {
    for (size_t i = 0; reader[i]; ++i) {
        if (!isdigit(reader[i])) {
            std::cout << "Error: bad input => " << reader << std::endl;
            return false;
        }
    }
    return true;
}

bool check_pipes(const std::string &reader) {
    size_t number_pipes = 0;
    for (size_t i = 0; reader[i]; i++) {
        if (reader[i] == '|') {
            number_pipes += 1;
        }
    }
    if (number_pipes == 1)
        return true;
    else {
        std::cout << "Error: bad input => " << reader << std::endl;
        return false;
    }
}

std::string ymd_valRet(const std::string &buffer, size_t pos, size_t npos) {
    std::string year_str = buffer.substr(pos, npos);
    return (year_str);
}

int utils_convert(const std::string &reader, size_t pos, size_t npos) {
    std::string year_str = reader.substr(pos, npos);
    if (!check_digits(year_str))
        return (0);
    int value;
    std::stringstream ss(year_str);
    ss >> value;
    return (value);
}

float value_convert(const std::string &reader, size_t pos, size_t npos) {
    std::string year_str = reader.substr(pos, npos);
    float value;
    std::stringstream ss(year_str);
    ss >> value;
    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return (1001);
    } else if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return (1001);
    }
    return (value);
}

int check_month(const std::string &reader) {
    if (reader[7] != '-') {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    int month = utils_convert(reader, 5, 2);
    if (month < 1 || month > 12) {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    return (month);
}

bool check_day(const std::string &reader, int month, int year) {
    if (!isdigit(reader[8]) || reader[10] != ' ' || reader[11] != '|') {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    int day = utils_convert(reader, 8, 2);
    if (is_leap_year(year) == 1 && month == 2 && day <= 29) {
        return true;
    } else if (is_leap_year(year) == 0 && month == 2 && day <= 28) {
        return true;
    } else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) {
        return true;
    } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) {
        return true;
    } else {
        std::cout << "Error: bad input => " << reader << std::endl;
        return false;
    }
}

int check_year(const std::string &reader) {
    if (reader[4] != '-') {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    std::string year_str = reader.substr(0, 4);  // Extract the first 4 characters (YYYY)
    int year = utils_convert(year_str, 0, 4);
    if (year < 2009) {
        std::cout << "Error: bad input => " << reader << std::endl;
        return (0);
    }
    return (year);
}

int check_value(const std::string &reader) {
    float value = value_convert(reader, 13, 1000);
    return (value);
}

void BitcoinExchange::parse_data(const std::string &buffer) {
    std::vector<std::string>::const_iterator it = this->_list.begin();

    while (it != this->_list.end()) {
        std::string input_value = ymd_valRet(*it, 0, 10);
        std::cout << "Input Value: " << input_value << std::endl;
        break;
    }
    std::string data_value = ymd_valRet(buffer, 0, 10);
}

void BitcoinExchange::calculate_value() {
    std::ifstream openfile("data.csv");

    size_t i = 0;
    std::string buffer;
    while(std::getline(openfile, buffer)) {
        if (i != 0) {
            parse_data(buffer);
            break;
        } else
            i++;
    }
    openfile.close();
}

int available_database() {
    std::ifstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1002);
    }
    file.close();
    return (0);
}

int BitcoinExchange::available_file() {
    std::ifstream file(this->_file.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return (1002);
    }
    file.close();
    return (0);
}

void printVector(const std::vector<std::string> &vec) {
    std::vector<std::string>::const_iterator it = vec.begin();

    while (it != vec.end()) {
        std::cout << *it << std::endl;
        ++it;
    }
}

void BitcoinExchange::filereader() {
    if (available_database() == 1002)
        return;
    else if (available_file() == 1002)
        return ;
    std::ifstream openfile(this->_file.c_str());
    size_t i = 0;
    std::string reader;
    while(std::getline(openfile, reader)) {
        if (i != 0) {
            if (check_pipes(reader)) {
                if (check_year(reader) != 0) {
                    int year = check_year(reader);
                    if (check_month(reader) != 0) {
                        int month = check_month(reader);
                        if (check_day(reader, month, year)) {
                            if(check_value(reader) != 1001) {
                                this->_list.push_back(reader);
                            }
                        }
                    }
                }

            }
        }
        else
            i++;
    }
    openfile.close();
    calculate_value();
    printVector(this->_list);
}