/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:01:02 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/03 19:02:38 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP 
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

# define MAX_CONTACT 8

class PhoneBook : public Contact
{
    public:
        Contact contact[MAX_CONTACT];
        int  index;
        bool    isFull;
    PhoneBook()
    {
        index = 0;
        isFull = false;
    }    
    void    add(void);
    void    search(void);
    void    Exit(void);
};

#endif