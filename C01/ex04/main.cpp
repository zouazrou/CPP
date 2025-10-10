/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:09:43 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/10 09:22:53 by zouazrou         ###   ########.fr       */
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
    exit(1);
}

void    ft_replace(std::string filename, std::string oldStr, std::string newStr)
{
    std::string line;
    size_t      startPos;
    size_t      oldStrPos;
    
    if (oldStr.empty())
        ft_perror("Empty oldStr");
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open())
        ft_perror(NULL);
    std::ofstream outFile(filename.append(".replace").c_str());
    if (!outFile.is_open())
        inFile.close(), ft_perror(NULL);
    while (std::getline(inFile, line))
    {
        if (!inFile.eof())
            line.append("\n");
        startPos = 0;
        while ((oldStrPos = line.find(oldStr, startPos)) != std::string::npos)
        {
            outFile << line.substr(startPos, oldStrPos - startPos);
            outFile << newStr;
            startPos = oldStrPos + oldStr.size();            
        }
        outFile << line.substr(startPos, line.length());
    }
    inFile.close();
    outFile.close();
}

int main(int ac, char *av[])
{
    if (ac != 4)
        ft_perror("./exe [namefile] [oldStr] [newStr]");
    ft_replace(av[1], av[2], av[3]);
    return (0);
}
