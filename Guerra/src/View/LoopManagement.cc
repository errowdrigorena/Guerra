/*
 * Loop_management.cc
 *
 *  Created on: Feb 17, 2022
 *      Author: iban
 */
#include <View/LoopManagement.h>

#include <iostream>

std::string option_selector(std::vector<std::string> options)
{
	auto option{0 };
	std::string desired_option{};

	auto show_options = [](std::vector<std::string> options)
			{
				for(std::size_t i = 0; i < options.size(); i++)
				{
					std::cout << i+1 << " " << options[i] << std::endl;
				}
			};

	do
	{
		show_options(options);
		option = operations::ask_value<int>("Introduzca opción");
		operations::check_number("Introduzca un número positivo", option);
	}while( option > options.size() );

	desired_option = options.at(option - 1);

	return desired_option;
}

std::string option_management(std::vector<std::string> options, std::string tip)
{
	std::cout << tip;
	options.push_back("salir");

	auto selected_option = option_selector(options);

	return selected_option;
}

