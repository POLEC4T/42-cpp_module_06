/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:12:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/19 01:43:41 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av) {
	ScalarConverter sc;

	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <literal>" << std::endl;
		return 1;
	}

	sc.convert(av[1]);
	return 0;
}