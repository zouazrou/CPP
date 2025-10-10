/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:52:19 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/10 11:30:45 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char *av[])
{
    Harl    robot;

    if (ac != 2)
    {
        std::cerr << "Error : Put one of the four levels : ('DEBUG', 'INFO', 'WARNING', 'ERROR')"
                  << std::endl;
        return (1);
    }
    robot.complain(av[1]);    
    return 0;
}
