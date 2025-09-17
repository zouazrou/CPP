/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:00:56 by zouazrou          #+#    #+#             */
/*   Updated: 2025/09/17 16:18:32 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP  

# include "header.hpp"

class Contact
{
    public:
        std::string fName; 
        std::string lName; 
        std::string nickName;
        std::string phoneNum;
        std::string secret;
};

#endif