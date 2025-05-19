/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:57:19 by palu              #+#    #+#             */
/*   Updated: 2025/05/16 16:28:42 by paulmart         ###   ########.fr       */
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

void RobotomyRequestForm::execute(Bureaucrat const &B) const
{
	std::srand(std::time(0));
	if (this->getIsSigned() == true)
	{
		if (B.getGrade() <= this->getExecGrade())
		{
			std::cout << "🤖 BRRRR BRRRR RRRB 🤖" << std::endl;
			int i = rand() % 2;
			if (i == 0)
			{
				std::cout << "🤖 Form : " << getTarget() << " has been robotomized 🤖" << std::endl;
			}
			else
			{
				std::cout << "🤖 Form : " << getTarget() << " has failed robotomisation 🤖" << std::endl;
			}
		}
		else
			throw GradeTooLowException();
	}
	else 
		throw FormNotSigned();
}

