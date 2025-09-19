/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:46:41 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 05:08:48 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

# include <iostream>
# include <ostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <limits>

class ScalarConverter {
	private:
		void printChar(char c, const std::string &literal) const;
		void printInt(int i, const std::string &literal) const;
		void printFloat(float f, const std::string &literal) const;
		void printDouble(double d, const std::string &literal) const;
		void throwIfOutOfCharsRange(const std::string &literal) const;

		bool isPseudoLiteral(const std::string &literal) const;
		bool isChar(const std::string &literal) const;
		bool isInt(const std::string &literal) const;
		bool isFloat(const std::string &literal) const;
		bool isDouble(const std::string &literal) const;

		void fromPseudoLiteral(const std::string &literal) const;
		void fromChar(const std::string &literal) const;
		void fromInt(const std::string &literal) const;
		void fromFloat(const std::string &literal) const;
		void fromDouble(const std::string &literal) const;


	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();

		void convert(const std::string &literal) const;
};

#endif