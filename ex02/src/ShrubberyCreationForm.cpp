/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:51 by palu              #+#    #+#             */
/*   Updated: 2025/05/15 16:27:40 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 135, 147), _target("Default")
{
	std::cout << "ShrubberyCreationForm : Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 135, 147), _target(target)
{
	std::cout << "ShrubberyCreationForm : Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &S) : AForm("ShrubberyCreationForm", 135, 147)
{
	*this = S;
	std::cout << "ShrubberyCreationForm : Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm : Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &S)
{
	if (this == &S)
		return (*this);
	this->_target = S._target;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &S)
{
	os << "ShrubberyCreationForm : " << S.getName() << " grade to sign is " << S.getSignGrade() << std::endl
	<< "and  grade to execute is " << S.getExecGrade() << std::endl;
	return (os);
}
