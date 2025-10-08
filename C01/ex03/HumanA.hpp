/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:23:23 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/08 12:13:00 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        /* data */
    public:
        std::string name;
        Weapon      &weapon;
        
        HumanA(std::string name, Weapon &weapon); 
        // ~HumanA();
        
        void        attack(void);
};



#endif