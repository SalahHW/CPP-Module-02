/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:25:17 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/28 19:02:07 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int number;
		static const int fractional_bits = 8;
	public:
		Fixed();	//Default constructor
		~Fixed();	//Destructor
		Fixed(const Fixed& other);	//Copy constructor
		Fixed& operator=(const Fixed& other);	//Copy assignment Operator
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
