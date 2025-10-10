/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:53:51 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/10 10:57:55 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

#include <iostream>
#define NUM_FUN 4

class Harl
{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
        void    noFunc(void);
        
    public:
        Harl(/* args */);
        ~Harl();
        void        (Harl::*arrayFuns[NUM_FUN + 1])(void);
        std::string nameFunctions[NUM_FUN];
        void        complain( std::string level );
};

#endif
