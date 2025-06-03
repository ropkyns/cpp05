/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:22:15 by palu              #+#    #+#             */
/*   Updated: 2025/06/03 10:37:40 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main(void)
{
	Intern Mathis;
	Bureaucrat Romain ("Romain", 2);
	AForm *form = Mathis.makeForm("am I the GOAT", "Romain");
	std::cout << std::endl;
	if (!form)
	{
		form = Mathis.makeForm("PresidentialPardonForm", "Romain");
	}
	try
	{
		Romain.incrementGrade();
		Romain.signForm(*form);
		Romain.executeForm(*form);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Romain.incrementGrade();
		Romain.executeForm(*form);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete form;
	return (0);
}
