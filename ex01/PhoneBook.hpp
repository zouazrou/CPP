/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:01:02 by zouazrou          #+#    #+#             */
/*   Updated: 2025/09/17 18:13:17 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP 
# define PHONEBOOK_HPP

#include "header.hpp"

class PhoneBook : public Contact
{
    public:
        Contact contact[8];
        size_t  index;
        bool    isFull;
    PhoneBook()
    {
        index = 0;
        isFull = false;
    }    
    void    add(void);
    void    search(void);
    void    Exit(void);
};

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
    exit(EXIT_SUCCESS);
}

#endif