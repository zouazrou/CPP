/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:01:00 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/02 17:11:20 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp" 

void    display_promt(void)
{
    std::cout << "\n=======================================";
    std::cout << "=======================\n\n" << std::flush;
    std::cout << "$>" << std::flush;
}
int main(void)
{
    PhoneBook   phoneBook;
    std::string command;

    while ('X')
    {
        display_promt();
        std::cin >> command;
        if (!command.compare("ADD"))
        {
            std::cout << command << std::endl;
            phoneBook.add();
        }
        else if (!command.compare("SEARCH"))
        {
            std::cout << command << std::endl;
            phoneBook.search();
        }
        else if (!command.compare("EXIT"))
        {
            std::cout << command << std::endl;
            phoneBook.Exit();
        }
    }
    return 0;
}
