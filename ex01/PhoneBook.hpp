/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:01:02 by zouazrou          #+#    #+#             */
/*   Updated: 2025/10/04 16:22:56 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP 
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include "Contact.hpp"

# define MAX_CONTACT 3
# define COL_WIDE 10

class PhoneBook : public Contact
{
    public:
        Contact contact[MAX_CONTACT];
        int  index;
        int  curr_size;
        PhoneBook()
        {
            index = 0;
            curr_size = 0;
        }    
        void    add(void);
        void    search(void);
        void    Exit(void);
        
    private:
        void    display_contact_table(void);

};

#endif