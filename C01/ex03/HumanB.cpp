/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:23:32 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/20 11:10:54 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    weapon = NULL;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (this->weapon)
    {
        std::cout << this->name
                  << " attacks with their "
                  << this->weapon->getType()
                  << std::endl;
    }
    else
    {
        std::cout << this->name
                    << " doesn't have a Weapon !"
                    << std::endl;
    }
}
