/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:33 by joaoped2          #+#    #+#             */
/*   Updated: 2023/11/02 15:47:23 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Contact {

	private:
		std::string Firstname;
		std::string Lastname;
		std::string Nickname;
		std::string Phonenumber;
		std::string DarkestSecret;
	public:
		Contact( void );
		~Contact ( void );
};
