/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:41:01 by sbouheni          #+#    #+#             */
/*   Updated: 2023/12/01 18:10:41 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = number << this->fractional_bits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(number * (1 << this->fractional_bits));
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->number = src.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->number);
}

void Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->number / (1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
	return (this->number >> this->fractional_bits);
}

Fixed Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

std::ostream& operator << (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator==(const Fixed& fixed) const
{
	if (this->getRawBits() == fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	if (this->getRawBits() != fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>(const Fixed& fixed) const
{
	if (this->getRawBits() > fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& fixed) const
{
	if (this->getRawBits() < fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	if (this->getRawBits() >= fixed.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	if (this->getRawBits() <= fixed.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	Fixed result(this->toFloat() + fixed.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	Fixed result(this->toFloat() - fixed.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	Fixed result(this->toFloat() * fixed.toFloat());
	return (result);
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	Fixed result(this->toFloat() / fixed.toFloat());
	return (result);
}

Fixed& Fixed::operator++(void)
{
	this->number++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->number--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}
