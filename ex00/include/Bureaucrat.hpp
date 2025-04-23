/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palu <palu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:44:35 by paulmart          #+#    #+#             */
/*   Updated: 2025/04/23 23:20:34 by palu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &);
		const std::string	getName() const;
		const int			getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

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