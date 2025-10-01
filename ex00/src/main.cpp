/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:12:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/10/01 10:12:50 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av) {
	if (ac == 2) {
		ScalarConverter::convert(av[1]);
		return 0;
	}

	std::string tests[] = {
		"a",
		"z",
		"0",
		"9",
		"42",
		"-42",
		"4.2f",
		"-4.2f",
		"4.2",
		"-4.2",
		"nan",
		"+inf",
		"-inf",
		"nanf",
		"+inff",
		"-inff",
		"hello",
		"-2147483648",
		"2147483647",
		"2147483648",
		"-2147483649",
	};

	size_t i = 0;
	while (i < sizeof(tests) / sizeof(tests[0])) {
		std::cout << "Test " << i + 1 << ": \"" << tests[i] << "\"" << std::endl << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << "------------------------" << std::endl;
		i++;
	}

	return 0;
}
