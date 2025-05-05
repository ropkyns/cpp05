/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:44:25 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/05 15:19:52 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat : Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat : Standart constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &B)
{
	std::cout << "Bureaucrat : Copy constructor called" << std::endl;
	*this = B;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat : destrutor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade() const
{
	return(this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade to high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade to low\n");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &B){
	if (this != &B){
		static_cast<std::string>(_name) = B._name;
		_grade = B._grade;
	}
	return (*this);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade++;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &B)
{
	os << B.getName() << ", bureaucrat grade: " << B.getGrade() << std::endl;
	return (os);
}