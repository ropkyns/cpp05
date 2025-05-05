/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:38:39 by palu              #+#    #+#             */
/*   Updated: 2025/05/05 17:45:36 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(3), _execGrade(3)
{
	std::cout << "Form : Default constructor called" << std::endl;
}


Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw GradeTooHighException();
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw GradeTooLowException();
	std::cout << "Form : Constructor called" << std::endl;
}

Form::Form(const Form &F)
{
	*this = F;
	std::cout << "Form : Copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form : Destructor called" << std::endl;
}

Form &Form::operator=(const Form &F)
{
	return (*this);
}