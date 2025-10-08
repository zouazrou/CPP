/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:09:43 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/08 16:49:40 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char *av[])
{
    std::string filename;
    std::string s1;
    std::string s2;
    
    if (ac != 4)
    {
        std::cerr << "Error: Number of parameter must true"
                  << std::endl;
        return (EXIT_FAILURE);
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    std::ofstream myFile(filename);
    myFile.close();
        
    return (EXIT_SUCCESS);
}
