/*
 * InterfaceOperations.h
 *
 *  Created on: Feb 11, 2022
 *      Author: iban
 */

#ifndef VIEW_INTERFACEOPERATIONS_H_
#define VIEW_INTERFACEOPERATIONS_H_

#include <limits>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

namespace view
{
namespace interface_operations
{

template<typename T>
T ask_value(const std::string& question);

template<typename First, typename Second>
std::pair<First, Second> ask_pair(const std::string& question);

template<typename T>
std::vector<T> ask_multiple_values
(const std::string& question, const std::size_t number_values,
						std::function<T(std::string& question)> callback);

template<typename T>
void check_number(const std::string& warning, T& number);

unsigned short ask_number(const std::string& question);

std::string ask_string(const std::string& question);

std::vector<std::string> ask_multiple_strings
				(const std::string& question, unsigned short& number_strings);


template<typename T>
T ask_value(const std::string& question)
{
	T asked_value{};
	std::cout << question << std::endl;
	std::cin >> asked_value;

	return asked_value;
}

template<typename First, typename Second>
std::pair<First, Second> ask_pair(const std::string& question)
{
	std::pair<First, Second> asked_value{};
	std::cout << question << std::endl;
	std::cin >> asked_value.first;
	std::cin >> asked_value.second;

	return asked_value;
}

template<typename T>
std::vector<T> ask_multiple_values
				(const std::string& question, const std::size_t number_values,
						std::function<T(std::string& question)> callback)
{
	std::vector<T> asked_values{};

	for(std::size_t i = 1; i <= number_values; i++)
	{
		std::string question_with_number{question.c_str() };
		auto i_string = std::to_string(i);
		question_with_number.insert(question_with_number.end(),
									i_string.begin(), i_string.end() );

		T insertable_value = callback(question_with_number);
		asked_values.push_back(insertable_value);
	}

	return asked_values;
}

template<typename T>
void check_number(const std::string& warning, T& number)
{
	while ( std::cin.good() == false || number < 1 )
	{
	    std::cin.clear();
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	    number = ask_number(warning);
	}
}

}
}

#endif /* VIEW_INTERFACEOPERATIONS_H_ */
