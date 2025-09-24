/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:01:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 05:09:14 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::throwIfOutOfCharsRange(const std::string &literal) const {
	double value;
	try {
		value = convertToT<double>(literal);
	} catch (...) {
		throw std::out_of_range("overflow");
	}
	if (value < -128 || value > 127) {
		throw std::out_of_range("overflow");
	}
}

void ScalarConverter::printChar(char c, const std::string &literal) const {
	std::cout << "char: ";
	try {
		throwIfOutOfCharsRange(literal);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return;
	}
	if (c < 32 || c == 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}
void ScalarConverter::printInt(int i, const std::string &literal) const {
	try {
		int value = convertToT<int>(literal);
		(void)value;
	} catch (...) {
		std::cout << "int: overflow" << std::endl;
		return;
	}
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f) const {
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) const {
	std::cout << "double: " << std::setprecision(1) << std::fixed << d << std::endl;
}

bool ScalarConverter::isChar(const std::string &literal) const {
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal) const {
	if (literal.empty())
		return false;
	for (size_t i = 0; i < literal.length(); ++i) {
		if (!std::isdigit(literal[i]) && !(i == 0 && (literal[i] == '-' || literal[i] == '+')))
			return false;
	}
	return true;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal) const {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	return false;
}

bool ScalarConverter::isFloat(const std::string &literal) const {
	if (literal.empty())
		return false;
	if (literal[literal.length() - 1] != 'f')
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	if (literal.find('.') != literal.rfind('.'))
		return false;
	for (size_t i = 0; i < literal.length() - 1; ++i) {
		if (!std::isdigit(literal[i]) && literal[i] != '.' && !(i == 0 && (literal[i] == '-' || literal[i] == '+')))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &literal) const {
	if (literal.empty()) 
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	if (literal.find('.') != literal.rfind('.'))
		return false;
	for (size_t i = 0; i < literal.length(); ++i) {
		if (!std::isdigit(literal[i]) && literal[i] != '.' && !(i == 0 && (literal[i] == '-' || literal[i] == '+')))
			return false;
	}
	return true;
}

void ScalarConverter::fromPseudoLiteral(const std::string &literal) const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (literal == "+inf" || literal == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (literal == "-inf" || literal == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::fromChar(const std::string &literal) const {
	printChar(literal[0], literal);
	printInt(static_cast<int>(literal[0]), literal);
	printFloat(static_cast<float>(literal[0]));
	printDouble(static_cast<double>(literal[0]));
}

template <typename T>
T ScalarConverter::convertToT(const std::string &literal) const {
	if (isChar(literal))
		return static_cast<T>(literal[0]);
	T value;
	std::stringstream ss(literal);
	ss >> value;
	if (ss.fail()) {
		throw std::exception();
	}
	return (value);
}

void ScalarConverter::fromInt(const std::string &literal) const {
	int intValue;
	try {
		intValue = convertToT<int>(literal);
	} catch (...) {
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: impossible (int overflow)" << std::endl;
		std::cout << "double: impossible (int overflow)" << std::endl;
		return;
	}
	printChar(static_cast<char>(intValue), literal);
	printInt(intValue, literal);
	printFloat(static_cast<float>(intValue));
	printDouble(static_cast<double>(intValue));
}

void ScalarConverter::fromFloat(const std::string &literal) const {
	float floatValue;
	try {
		floatValue = convertToT<float>(literal);
	} catch (...) {
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	printChar(static_cast<char>(floatValue), literal);
	printInt(static_cast<int>(floatValue), literal);
	printFloat(floatValue);
	printDouble(static_cast<double>(floatValue));
}

void ScalarConverter::fromDouble(const std::string &literal) const {
	double doubleValue;
	try {
		doubleValue = convertToT<double>(literal);
	} catch (...) {
		std::cout << "char: overflow" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	printChar(static_cast<char>(doubleValue), literal);
	printInt(static_cast<int>(doubleValue), literal);
	printFloat(static_cast<float>(doubleValue));
	printDouble(doubleValue);
}


void ScalarConverter::convert(const std::string &literal) const {
	if (isPseudoLiteral(literal))
		fromPseudoLiteral(literal);
	else if (isChar(literal))
		fromChar(literal);
	else if (isInt(literal))
		fromInt(literal);
	else if (isFloat(literal))
		fromFloat(literal);
	else if (isDouble(literal))
		fromDouble(literal);
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
}