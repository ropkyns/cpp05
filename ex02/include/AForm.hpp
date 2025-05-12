/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:38:18 by palu              #+#    #+#             */
/*   Updated: 2025/05/12 17:39:33 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const		std::string _name;
	bool		_isSigned;
	const int	_signGrade;
	const int	_execGrade;
public:
	AForm();
	~AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &F);
	AForm &operator=(const AForm &F);

	int			getSignGrade() const;
	int			getExecGrade() const;
	bool		getIsSigned() const;
	std::string	getName() const;
	void		beSigned(Bureaucrat &B);

	class GradeTooHighException : public std::exception
	{
		public :
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const AForm &F);


#endif