/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:44:25 by paulmart          #+#    #+#             */
/*   Updated: 2025/04/23 23:20:20 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else
			_grade = grade;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
}

Bureaucrat::~Bureaucrat()
{
	
}

const std::string Bureaucrat::getName() const
{
	return(this->_name);
}

const int Bureaucrat::getGrade() const
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

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		static_cast<std::string>(_name) = other._name;
		_grade = other._grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << other.getName() << ", bureaucrat grade: " << other.getGrade() << std::endl;
	return (os);
}