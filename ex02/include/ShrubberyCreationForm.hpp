/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:50:46 by paulmart          #+#    #+#             */
/*   Updated: 2025/05/16 16:37:17 by paulmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string _target;

	public :
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &S);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &S);

		std::string getTarget() const;
		void	execute(Bureaucrat const &B) const;

};

#endif