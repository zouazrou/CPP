/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:40:17 by zouazrou          #+#    #+#             */
/*   Updated: 2025/09/18 09:40:49 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


void    PhoneBook::search(void)
{
    for (size_t i = 0; i < index; i++)
    {
        std::cout << "[" << i << "] | ";
        std::cout << contact[i].fName << " | " << contact[i] .lName << " | ";
        std::cout << contact[i].nickName << " | " << contact[i].phoneNum << std::endl;
    }
    
}

void    PhoneBook::add(void)
{
    if (index == 8)
        index = 0;
    /****/
    std::cout << "-->First Name:" << std::endl;
    std::cin >> contact[index].fName;
    /****/
    std::cout << "-->Last Name:" << std::endl;
    std::cin >> contact[index].lName;
    /****/
    std::cout << "-->NickName:" << std::endl;
    std::cin >> contact[index].nickName;
    /****/
    std::cout << "-->Phone Number:" << std::endl;
    std::cin >> contact[index].phoneNum;
    /****/
    std::cout << "-->Your Secret:" << std::endl;
    std::cin >> contact[index].secret;
    /****/
    index++;
}

void    PhoneBook::Exit(void)
{
    std::exit(0);
}