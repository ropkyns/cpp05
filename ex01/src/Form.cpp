/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:38:39 by palu              #+#    #+#             */
/*   Updated: 2025/05/06 19:03:01 by palu             ###   ########.fr       */
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

Form::Form(const Form &F) : _isSigned(false), _signGrade(F._signGrade), _execGrade(F._execGrade)
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

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

std::string Form::getName() const
{
	return (_name);
}

void Form::beSigned(Bureaucrat &B)
{
	if (B.getGrade() <= _signGrade)
	{	_isSigned = true;
		std::cout << B.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << B.getName() << " couldn't sign " << this->getName() << " because ";
		throw GradeTooLowException();
	}
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &os, const Form &F)
{
	os << "Form : " << F.getName() << " grade to sign is " << F.getSignGrade() << std::endl
	<< "and  grade to execute is " << F.getExecGrade() << std::endl;
	return (os);
}