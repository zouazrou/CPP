/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:40:17 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/04 18:09:54 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void    padding(size_t size)
{
    int padding_len;
    
    padding_len = COL_WIDE - size;
    for (int i = 0; i < padding_len; i++)
        std::cout << ' ';
}

static void    print_column(std::string str)
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

static int trim_spaces(std::string &str)
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

static  bool    isDigits(std::string &s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return (false);
    }
    return (true);
}

bool isValidContact(Contact &contact)
{
    if (trim_spaces(contact.fName)
        || trim_spaces(contact.lName)
        || trim_spaces(contact.nickName)
        || trim_spaces(contact.phoneNum)
        || trim_spaces(contact.secret))
    {
        std::cerr << "IS EMPTY FIELD !\n";
        return (false);
    }
    if (isDigits(contact.phoneNum) == false)
    {
        std::cerr << "Error : IS EMPTY FIELD !\n";
        return (false);
    }
    return (true);
}

void    PhoneBook::add(void)
{
    std::cout << "-->first Name: " << std::endl;
    std::getline(std::cin, contact[index].fName);
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
    if (isValidContact(contact[index]) == false)
        return ;
    index = (index+1)%MAX_CONTACT;
    
    if (curr_size != MAX_CONTACT)
        curr_size++;
}


void    PhoneBook::display_contact_table(void)
{
    std::cout << "\n ___________________________________________\n";
    std::cout << "|          |          |          |          |\n";
    std::cout << "|  INDEX   |";
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
}

void    PhoneBook::search(void)
{
    std::string str;
    int         input;
    
    if (!curr_size)
    {
        std::cerr << "Error : PhoneBook is empty!\n";
        return ;
    }
    display_contact_table();
    std::cout << "ENTRE THE CONTACT INDEX TO DISPLAY IT : ";
    std::getline(std::cin, str);
    if (trim_spaces(str) || !isDigits(str))
    {
        std::cerr << "Error : input is not valid\n";
        return ;
    }
    input = atoi(str.c_str());
    if (input < 0 || input >= curr_size)
    {
        std::cerr << "Error : input is not valid\n";
        return ;
    }
    std::cout << "First Name   : " << contact[(index+input)%curr_size].fName << std::endl;
    std::cout << "Last Name    : " << contact[(index+input)%curr_size].lName << std::endl;
    std::cout << "NickName     : " << contact[(index+input)%curr_size].nickName << std::endl;
    std::cout << "Phone Number : " << contact[(index+input)%curr_size].phoneNum << std::endl;
    std::cout << "Secret       : " << contact[(index+input)%curr_size].secret << std::endl;
}

void    PhoneBook::Exit(void)
{
    std::exit(0);
}