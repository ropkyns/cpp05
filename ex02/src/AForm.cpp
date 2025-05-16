/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:38:39 by palu              #+#    #+#             */
/*   Updated: 2025/05/16 16:15:08 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(3), _execGrade(3)
{
	std::cout << "AForm : Default constructor called" << std::endl;
}


AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw GradeTooHighException();
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw GradeTooLowException();
	std::cout << "AForm : Constructor called" << std::endl;
}

AForm::AForm(const AForm &F) : _isSigned(false), _signGrade(F._signGrade), _execGrade(F._execGrade)
{
	*this = F;
	std::cout << "AForm : Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm : Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &F)
{
	if (this == &F)
		return (*this);
	return (*this);
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

std::string AForm::getName() const
{
	return (_name);
}

void AForm::beSigned(Bureaucrat &B)
{
	if (B.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return ("Form not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &F)
{
	os << "Form : " << F.getName() << " grade to sign is " << F.getSignGrade() << std::endl
	<< "and grade to execute is " << F.getExecGrade() << std::endl;
	return (os);
}
