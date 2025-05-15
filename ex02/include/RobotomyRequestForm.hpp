/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:54:49 by palu              #+#    #+#             */
/*   Updated: 2025/05/15 17:22:05 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string _target;

	public :
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &R);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &R);

		std::string getTarget() const;
		void execute(const Bureaucrat &B) const;

};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm &R);

#endif