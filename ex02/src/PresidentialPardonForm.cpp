/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:19:23 by palu              #+#    #+#             */
/*   Updated: 2025/05/15 18:06:05 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "PresidentialPardonForm : Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm : Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &P) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = P;
	std::cout << "PresidentialPardonForm : Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm : Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &P)
{
	if (this == &P)
		return (*this);
	this->_target = P._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &P)
{
	os << "PresidentialPardonForm : " << P.getName() << " grade to sign is " << P.getSignGrade() << std::endl
	<< "and  grade to execute is " << P.getExecGrade() << std::endl;
	return (os);
}
