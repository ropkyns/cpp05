/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:29:16 by paulmart          #+#    #+#             */
/*   Updated: 2025/06/03 10:30:40 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat				bureaucrat1("bureaucrat1", 130);
	Bureaucrat				bureaucrat2("bureaucrat2", 40);
	Bureaucrat				bureaucrat3("bureaucrat3", 5);
	ShrubberyCreationForm	shrubbery("test");
	RobotomyRequestForm		robotomy("test");
	PresidentialPardonForm	presidential("test");
	AForm					*form = new ShrubberyCreationForm("test");
	std::cout << std::endl;

	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	std::cout << bureaucrat3 << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << presidential << std::endl;

	try
	{
		bureaucrat1.signForm(shrubbery);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		bureaucrat1.executeForm(shrubbery);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		bureaucrat2.signForm(robotomy);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bureaucrat2.executeForm(robotomy);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		bureaucrat3.signForm(presidential);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		bureaucrat3.executeForm(presidential);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	delete form;
	return (0);
}
