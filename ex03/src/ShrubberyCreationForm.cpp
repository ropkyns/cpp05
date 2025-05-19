/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:51 by palu              #+#    #+#             */
/*   Updated: 2025/05/16 16:15:23 by paulmart         ###   ########.fr       */
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

void ShrubberyCreationForm::execute(Bureaucrat const &B) const
{
	if (this->getIsSigned() == true)
	{
		if (B.getGrade() <= this->getExecGrade())
		{
			std::ofstream outfile(this->getTarget().append("_shruberry").c_str());
			outfile << "          &&& &&  & &&" << std::endl;
			outfile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
			outfile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
			outfile << "   &() &\\/&|()|/&\\/ '%' & ()" << std::endl;
			outfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
			outfile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
			outfile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
			outfile << "     &&     \\|||" << std::endl;
			outfile << "             |||" << std::endl;
			outfile << "             |||" << std::endl;
			outfile << "             |||" << std::endl;
			outfile << "       , -=-~  .-^- _" << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else 
		throw FormNotSigned();
}

