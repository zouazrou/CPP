/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:52:19 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/10 11:18:41 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
    Harl robot;
     
    robot.complain("DEBUG");
    robot.complain("INFO");
    robot.complain("WARNING");
    robot.complain("ERROR");
    robot.complain("");
    return 0;
}
