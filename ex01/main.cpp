/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:01:00 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/04 14:12:10 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp" 

void    display_promt(std::string &request)
{
    // std::cout << "\n\n=======================\n\n";
    std::cout << "\n$> ";
    std::getline(std::cin, request);
}

int main(void)
{
    PhoneBook   phoneBook;
    std::string request;
    
    std::cout.setf(std::ios::unitbuf);
    while (true)
    {
        display_promt(request);
        if (std::cin.eof())
            break ;
        else if (!request.compare("ADD"))
            phoneBook.add();
        else if (!request.compare("SEARCH"))
            phoneBook.search();
        else if (!request.compare("EXIT"))
            phoneBook.Exit();
    }
    std::cout << "EOF\n";
    return 0;
}
