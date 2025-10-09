/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:09:43 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/09 21:49:38 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

void    ft_perror(const char *msg)
{
    std::cerr   << "Error: "; 
    if (!msg)
        std::cerr << std::strerror(errno) << std::endl;
    else
        std::cerr << msg << std::endl;
    exit (1);
}

int main(int ac, char *av[])
{
    std::string inFileName;
    std::string outFileName;
    std::string line;
    std::string oldStr;
    std::string newStr;
    size_t      startPos;
    size_t      oldStrPos;
    
    if (ac != 4)
        ft_perror("./exe [namefile] [oldStr] [newStr]");
    inFileName = av[1];
    oldStr = av[2];
    newStr = av[3];
    if (oldStr.empty())
        ft_perror("Empty oldStr");
    std::ifstream inFile(inFileName.c_str());
    if (!inFile.is_open())
        ft_perror(NULL);
    std::ofstream outFile(inFileName.append(".replace").c_str());
    if (!outFile.is_open())
        ft_perror(NULL);
    while (std::getline(inFile, line))
    {
        startPos = 0;
        while ((oldStrPos = line.find(oldStr, startPos)) != std::string::npos)
        {
            outFile << line.substr(startPos, oldStrPos - startPos);
            outFile << newStr;
            startPos += oldStrPos + newStr.size();            
            // oldStrPos = line.find(oldStr, startPos);
        }        
    }
    
    inFile.close();
    outFile.close();
        
    return (0);
}
