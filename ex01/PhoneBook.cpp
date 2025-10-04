/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:40:17 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/04 16:26:09 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    padding(size_t size)
{
    int padding_len;
    
    padding_len = COL_WIDE - size;
    for (int i = 0; i < padding_len; i++)
        std::cout << ' ';
}

void    print_column(std::string str)
{
    if (str.length() <= COL_WIDE)
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
    int i;
    int l;
    
    i = 0;
    l = str.length() - 1;
    while (i < (int)str.length() && isspace(str[i]))
        i++;
    while (l >= 0 && isspace(str[l]))
        l--;
    str.erase(l+1);
    str.erase(0, i);
    if (str.empty())
        return (1);
    return (0);
}

bool    isPhoneNum(std::string &s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return (false);
    }
    return (true);
}


void    PhoneBook::add(void)
{
    /****/
    std::cout << "-->first Name:" << std::endl;
    std::getline(std::cin, contact[index].fName);
    if (trim_spaces(contact[index].fName))
    {
        std::cerr << "IS EMPTY FIELD !\n";
        return ;
    }
    /****/
    std::cout << "-->Last Name:" << std::endl;
    std::getline(std::cin, contact[index].lName);
    if (trim_spaces(contact[index].lName))
    {
        std::cerr << "IS EMPTY FIELD !\n";
        return ;
    }
    /****/
    std::cout << "-->NickName:" << std::endl;
    std::getline(std::cin, contact[index].nickName);
    if (trim_spaces(contact[index].nickName))
    {
        std::cerr << "IS EMPTY FIELD !\n";
        return ;
    }
    /****/
    std::cout << "-->Phone Number:" << std::endl;
    std::getline(std::cin, contact[index].phoneNum);
    if (trim_spaces(contact[index].phoneNum))
    {
        std::cerr << "IS EMPTY FIELD !\n";
        return ;
    }
    if (isPhoneNum(contact[index].phoneNum) == false)
    {
        std::cerr << "PHONE-NUM MUST HAS ONLY DIGITS !\n";
        return ;
    }
    /****/
    std::cout << "-->Your Secret:" << std::endl;
    std::getline(std::cin, contact[index].secret);
    if (trim_spaces(contact[index].secret))
    {
        std::cerr << "IS EMPTY FIELD !\n";
        return ;
    }
    index = (index+1)%MAX_CONTACT;
    
    if (curr_size != MAX_CONTACT)
        curr_size++;
    std::cout << "next-idx->" << index << " :curr-size->" << curr_size << std::endl;
}

#include <unistd.h>

// void    PhoneBook::display_contact_table(void)
// {
//     std::cout << "\n|  INDEX   |";
//     std::cout << "first name|";
//     std::cout << "last name |";
//     std::cout << " Nickname |";
//     int i = (index) % curr_size;
//     int j;
//     for (j = 0; j < curr_size; j++)
//     {
//         std::cout << "\n|__________|__________|__________|__________|\n";
//         std::cout << "|" << j << "         |";
//         print_column(contact[i].fName);
//         print_column(contact[i].lName);
//         print_column(contact[i].nickName);
//         i = (i+1) % curr_size;
//     }
//     std::cout << "\n|__________|__________|__________|__________|\n";
// }
void    PhoneBook::search(void)
{
    
    std::cout << "\n|  INDEX   |";
    std::cout << "first name|";
    std::cout << "last name |";
    std::cout << " Nickname |";
    int i = (index) % curr_size;
    int j;
    for (j = 0; j < curr_size; j++)
    {
        std::cout << "\n|__________|__________|__________|__________|\n";
        std::cout << "|" << j << "         |";
        print_column(contact[i].fName);
        print_column(contact[i].lName);
        print_column(contact[i].nickName);
        i = (i+1) % curr_size;
    }
    std::cout << "\n|__________|__________|__________|__________|\n";
    std::cout << "ENTRE THE CONTACT INDEX TO DISPLAY IT : ";
    std::cin >> j;
    if (!std::cin || j < 0 || j >= curr_size)
    {
        std::cerr << "Error : input is not valid\n";
        return ;
    }
    std::cout << "First Name   : " << contact[(i+j)%curr_size].fName << std::endl;
    std::cout << "Last Name   : " << contact[(i+j)%curr_size].lName << std::endl;
    std::cout << "NickName     : " << contact[(i+j)%curr_size].nickName << std::endl;
    std::cout << "Phone Number : " << contact[(i+j)%curr_size].phoneNum << std::endl;
    std::cout << "Secret       : " << contact[(i+j)%curr_size].secret << std::endl;
}

void    PhoneBook::Exit(void)
{
    std::exit(0);
}