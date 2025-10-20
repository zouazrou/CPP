/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:24:00 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/20 10:51:59 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie   *Zombie::zombieHorde(int N, std::string name)
{
    Zombie  *zombies = NULL;

    if (N < 1)
        return (NULL);
    zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombies[i].setter(name);
    }
    return (zombies);
}
