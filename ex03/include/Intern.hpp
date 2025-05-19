/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:43:22 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/19 15:10:35 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"

// 

class Intern
{
	private:
		typedef AForm *(*FormCreator)(const std::string);
		struct FormType 
		{
			std::string name;
			FormCreator function;
		};

	public:
		Intern();
		~Intern();
		Intern(const Intern &I);
		Intern &operator=(const Intern &I);

		AForm	*makeForm(std::string formName, std::string formTarget);
};


#endif