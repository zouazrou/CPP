/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:13:43 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/08 12:35:11 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){}

Weapon::Weapon(void) : type("NO WEAPON"){}

const std::string &Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(std::string newType)
{
    this->type = newType;
}