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

void ScalarConverter::printChar(char c) const {
	std::cout << "char: ";
	try {
		if (c < 0 || c > 127)
			std::cout << "impossible" << std::endl;
		else if (c < 32 || c == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::printInt(int i) const {
	std::cout << "int: ";
	try {
		std::cout << i << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::printFloat(float f) const {
	std::cout << "float: ";
	try {
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::printDouble(double d) const {
	std::cout << "double: ";
	try {
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	} catch (...) {
		std::cout << "impossible" << std::endl;
	}
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
	if (literal.back() != 'f')
		return false;
	if (literal.find('.') == std::string::npos)
		return false;
	std::string floatLiteral = literal.substr(0, literal.length() - 1);
	std::istringstream iss(floatLiteral);
	float f;
	iss >> f;
	return iss.eof() && !iss.fail();
}

bool ScalarConverter::isDouble(const std::string &literal) const {
	if (literal.empty()) 
		return false;
	std::istringstream iss(literal);
	double d;
	iss >> d;
	return iss.eof() && !iss.fail();
}
void ScalarConverter::fromPseudoLiteral(const std::string &literal) const {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	printFloat(std::stof(literal));
	printDouble(std::stod(literal));
}

void ScalarConverter::fromChar(const std::string &literal) const {
	printChar(literal[0]);
	printInt(static_cast<int>(literal[0]));
	printFloat(static_cast<float>(literal[0]));
	printDouble(static_cast<double>(literal[0]));
}

void ScalarConverter::fromInt(const std::string &literal) const {
	int intValue;
	try {
		intValue = std::stoi(literal);
	} catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	printChar(static_cast<char>(intValue));
	printInt(intValue);
	printFloat(static_cast<float>(intValue));
	printDouble(static_cast<double>(intValue));
}

void ScalarConverter::fromFloat(const std::string &literal) const {
	float floatValue;
	try {
		floatValue = std::stof(literal);
	} catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	printChar(static_cast<char>(floatValue));
	printInt(static_cast<int>(floatValue));
	printFloat(floatValue);
	printDouble(static_cast<double>(floatValue));
}

void ScalarConverter::fromDouble(const std::string &literal) const {
	int doubleValue;
	try {
		doubleValue = std::stod(literal);
	} catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	printChar(static_cast<char>(doubleValue));
	printInt(static_cast<int>(doubleValue));
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
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
}