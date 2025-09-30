/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:54:15 by mniemaz           #+#    #+#             */
/*   Updated: 2025/09/25 12:14:00 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {

	Data data;
	data.str = "Hello, World!";
	data.num = 42;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data to uintptr_t: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data: str = " << deserializedData->str 
			  << ", num = " << deserializedData->num << std::endl;

	std::cout << "Original data address: \t\t" << &data << std::endl;
	std::cout << "Deserialized data address: \t" << deserializedData << std::endl;

	return 0;
}