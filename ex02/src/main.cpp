/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:34:42 by mniemaz           #+#    #+#             */
/*   Updated: 2025/09/25 12:42:39 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	int random = rand() % 3;

	if (random == 0) {
		std::cout << "Generated instance of A" << std::endl;
		return new A();
	} else if (random == 1) {
		std::cout << "Generated instance of B" << std::endl;
		return new B();
	} else {
		std::cout << "Generated instance of C" << std::endl;
		return new C();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Identified type: A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Identified type: B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Identified type: C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Identified type: A" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Identified type: B" << std::endl;
		return;
	} catch (std::exception&) {}

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Identified type: C" << std::endl;
		return;
	} catch (std::exception&) {}

	std::cout << "Unknown type" << std::endl;
}

int main() {
	srand((time(0)));

	Base* base = generate();

	identify(base);
	identify(*base);

	delete base;

	return 0;
}



