/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:57:19 by palu              #+#    #+#             */
/*   Updated: 2025/05/15 17:02:31 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "RobotomyRequestForm : Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm : Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &R) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = R;
	std::cout << "RobotomyRequestForm : Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm : Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &R)
{
	if (this == &R)
		return (*this);
	this->_target = R._target;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm &R)
{
	os << "RobotomyRequestForm : " << R.getName() << " grade to sign is " << R.getSignGrade() << std::endl
	<< "and  grade to execute is " << R.getExecGrade() << std::endl;
	return (os);
}
