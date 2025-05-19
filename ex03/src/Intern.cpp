/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:43:38 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/19 16:08:13 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

Intern::Intern()
{
	std::cout << "Intern : Default constructor called" << std::endl;
}

Intern::Intern(const Intern &I)
{
	*this = I;
	std::cout << "Intern : Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &I)
{
	if (this == &I)
		return (*this);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern : Destructor called" << std::endl;
}

static AForm *createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *createPresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	FormType forms[3] = {
		{"ShrubberyCreationForm", createShrubbery},
		{"RobotomyRequestForm", createRobotomy},
		{"PresidentialPardonForm", createPresidential}
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern create " << forms[i].name << std::endl;
			return (forms[i].function(formTarget));
		}
	}
	std::cerr << "This form does not exist, try \"ShrubberyCreationForm\", \"RobotomyRequestForm\" or \"PresidentialPardonForm\"" << std::endl;
	return (NULL);
}

