/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:55:27 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/04 21:08:58 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
    announce();
}

Zombie* newZombie( std::string name )
{

}

Zombie* Zombie::newZombie( std::string name )
{
    
}
/*
* This function creates a zombie,
* names it, and makes it announce itself
*/
void    Zombie::randomChump( std::string name )
{
    
}