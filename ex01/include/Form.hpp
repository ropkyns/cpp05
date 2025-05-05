/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:38:18 by palu              #+#    #+#             */
/*   Updated: 2025/05/05 17:33:37 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
private:
	const		std::string _name;
	bool		_isSigned;
	const int	_signGrade;
	const int	_execGrade;
public:
	Form();
	~Form();
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &F);
	Form &operator=(const Form &F);

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

std::ostream& operator<<(std::ostream &os, const Bureaucrat &other);


#endif