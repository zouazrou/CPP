/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:01:02 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/02 17:12:31 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP 
# define PHONEBOOK_HPP

# 
# include "Contact.hpp"

class PhoneBook : public Contact
{
    public:
        Contact contact[8];
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