/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:53:30 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/10 11:52:59 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl()
{
    arrayFuns[0] = &Harl::debug;
    nameFunctions[0] = "DEBUG";
    arrayFuns[1] = &Harl::info;
    nameFunctions[1] = "INFO";
    arrayFuns[2] = &Harl::warning;
    nameFunctions[2] = "WARNING";
    arrayFuns[3] = &Harl::error;
    nameFunctions[3] = "ERROR";
    arrayFuns[NUM_FUN] = &Harl::noFunc;
}

Harl::~Harl()
{}
        
void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::noFunc(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level)
{
    int i;
    
    i = 0;
    while (i < NUM_FUN && level.compare(nameFunctions[i]))
        i++;
    switch (i) {
        case (0):
            std::cout << "[" << nameFunctions[i] << "]" << std::endl;
            (this->*arrayFuns[i++])();
            // fall through
        case (1):
            std::cout << "[" << nameFunctions[i] << "]" << std::endl;
            (this->*arrayFuns[i++])();
            // fall through
        case (2):
            std::cout << "[" << nameFunctions[i] << "]" << std::endl;
            (this->*arrayFuns[i++])();
            // fall through
        case (3):
            std::cout << "[" << nameFunctions[i] << "]" << std::endl;
            (this->*arrayFuns[i++])();
            break;
        default:
            (this->*arrayFuns[i])();
    }
}
