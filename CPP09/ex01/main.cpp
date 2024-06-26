/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:21:36 by joaoped2          #+#    #+#             */
/*   Updated: 2024/06/05 12:04:57 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, const char **av) {
    if (ac == 2)
        RPN rpn(av);
    else
        std::cout << "Error" << std::endl;
}