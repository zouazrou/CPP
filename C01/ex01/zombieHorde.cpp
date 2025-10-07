/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:24:00 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/07 16:34:26 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie   *Zombie::zombieHorde(int N, std::string name)
{
    Zombie  *zombies = NULL;

    zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombies[i].setter(name);
    }
    return (zombies);
}
