/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:25:17 by sbouheni          #+#    #+#             */
/*   Updated: 2023/12/01 03:24:58 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int number;
		static const int fractional_bits = 8;
	public:
		Fixed();	//Default constructor
		~Fixed();	//Destructor
		Fixed(const Fixed& other);	//Copy constructor
		Fixed(const int number);	//Int constructor
		Fixed(const float number);	//Float constructor
		Fixed& operator=(const Fixed& other);	//Copy assignment Operator

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator << (std::ostream& out, const Fixed& fixed);

#endif
