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
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <string>
# include <limits>

class ScalarConverter {
	private:
		static void printChar(char c, const std::string &literal);
		static void printInt(int i, const std::string &literal);
		static void printFloat(float f);
		static void printDouble(double d);
		static void throwIfOutOfCharsRange(const std::string &literal);

		static bool isPseudoLiteral(const std::string &literal);
		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);

		template<typename T>
		static T convertToT(const std::string &literal);

		static void fromPseudoLiteral(const std::string &literal);
		static void fromChar(const std::string &literal);
		static void fromInt(const std::string &literal);
		static void fromFloat(const std::string &literal);
		static void fromDouble(const std::string &literal);

		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};

#endif