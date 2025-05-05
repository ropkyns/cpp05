/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:22:15 by palu              #+#    #+#             */
/*   Updated: 2025/05/02 17:18:30 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Michael = Bureaucrat("Michael Scott", 1);
		Michael.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Jim = Bureaucrat("Michael Scott", 150);
		Jim.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Jim = Bureaucrat("Michael Scott", 2);
		Jim.incrementGrade();
		std::cout << "I'm now the regional manager !" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}