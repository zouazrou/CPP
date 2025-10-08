/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:23:40 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/08 12:35:41 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    Weapon      *weapon;
    public:
        std::string name;
        
        HumanB(std::string name);
        
        void        attack(void);
        void    setWeapon(Weapon &weapon);
};

#endif