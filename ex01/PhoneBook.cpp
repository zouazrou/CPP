/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:40:17 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/04 12:34:08 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void padding(size_t size)
{
    int padding_len;
    
    padding_len = 10 - size;
    for (int i = 0; i < padding_len; i++)
        std::cout << ' ';
}

void    print_column(std::string str)
{
    if (str.length() <= 10)
    {
        std::cout << str;
        padding(str.length());
    }
    else
        std::cout << str.substr(0, 9) << '.';
    std::cout << "|";
}

int trim_spaces(std::string &str)
{
    size_t i = 0;
    
    while (i < str.length() && !isspace(str[i]))
        i++;
    str = str.erase(0, i);
    if (str.empty())
        return (1);
    return (0);
}
void    PhoneBook::search(void)
{
    // int i = index;
    std::cout << "\n|  index   |";
    std::cout << "first name|";
    std::cout << "last name |";
    std::cout << " Nickname |";
    for (int i = 0; i < index; i++)
    {
        std::cout << "\n|__________|__________|__________|__________|\n";
        std::cout << "|" << i << "         |";
        print_column(contact[i].fName);
        print_column(contact[i].lName);
        print_column(contact[i].nickName);
        i = (i+1) % MAX_CONTACT;
    }
    std::cout << "\n|__________|__________|__________|__________|\n";
}

void    PhoneBook::add(void)
{
    if (index == MAX_CONTACT)
        index = 0;
    /****/
    std::cout << "-->First Name:" << std::endl;
    std::getline(std::cin, contact[index].fName);
    if (trim_spaces(contact[index].fName))
    {
        std::cerr << "IS EMPTY FIELD !\n";
        return ;
    }
    /****/
    std::cout << "-->Last Name:" << std::endl;
    std::getline(std::cin, contact[index].lName);
    /****/
    std::cout << "-->NickName:" << std::endl;
    std::getline(std::cin, contact[index].nickName);
    /****/
    std::cout << "-->Phone Number:" << std::endl;
    std::getline(std::cin, contact[index].phoneNum);
    /****/
    std::cout << "-->Your Secret:" << std::endl;
    std::getline(std::cin, contact[index].secret);
    /****/
    index = (index + 1) % MAX_CONTACT;
}

void    PhoneBook::Exit(void)
{
    std::exit(0);
}