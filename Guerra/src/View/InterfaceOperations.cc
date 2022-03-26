/*
 * InterfaceOperations.cc
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#include <View/InterfaceOperations.h>

namespace view
{
namespace interface_operations
{

unsigned short ask_number(const std::string& question)
{
	unsigned short number{};
	std::cout << question << std::endl;
	std::cin >> number;

	return number;
}

std::string ask_string(const std::string& question)
{
	std::string character_line{};
	std::cout << question << std::endl;
	std::cin >> character_line;

	return character_line;
}

std::vector<std::string> ask_multiple_strings
				(const std::string& question, unsigned short& number_strings)
{
	std::vector<std::string> character_lines{};

	for(unsigned short i = 0; i < number_strings; i++)
	{
		std::string question_with_number{question.c_str() };
		auto i_string = std::to_string(i);
		question_with_number.insert(question_with_number.end(),
									i_string.begin(), i_string.end() );

		auto insertable = ask_string(question);

		character_lines.push_back(insertable);
	}

	return character_lines;
}

}
}
