/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:43:51 by mniemaz           #+#    #+#             */
/*   Updated: 2025/09/25 11:58:28 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer {
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& other);
	public:
		static Data* deserialize(uintptr_t raw);
		static uintptr_t serialize(Data* ptr);
};

#endif