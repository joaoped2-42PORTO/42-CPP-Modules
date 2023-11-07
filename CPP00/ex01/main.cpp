/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:03:22 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/02 14:20:24 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <unistd.h>

void	menu( void ) {
	std::cout << "ADD | Add contact to the Phonebook" << std::endl;
	std::cout << "SEARCH | Search for a contact" << std::endl;
	std::cout << "EXIT | Exit the program" << std::endl;
}

int	main()
{
	Phonebook	pb;
	std::string	Input;

	std::cout << "\033[2J\033[H";
	while (1) {
		menu();
		std::getline(std::cin, Input);
		if (Input == "ADD")
            pb.AddContact();
		else if (Input == "SEARCH")
			pb.SearchList();
		else if (Input == "EXIT")
			break ;
		else
			std::cout << "Wrong Input!" << std::endl;
	}
	return (0);
}
