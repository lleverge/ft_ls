/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:12:00 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/16 13:20:49 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_detect_opt(char *arg, t_opt *options)
{
	int	i;

	i = 0;
	while (arg[++i] != '\0')
	{
		if (arg[i] == 't')
			options->t = 1;
		else if (arg[i] == 'a')
			options->a = 1;
		else if (arg[i] == 'l')
			options->l = 1;
		else if (arg[i] == 'R')
			options->rec = 1;
		else if (arg[i] == 'r')
			options->r = 1;
		else
		{
			opt_error(arg);
			exit(1);
		}
	}
}

void	init_opt(t_opt *options)
{
	options->l = 0;
	options->a = 0;
	options->rec = 0;
	options->r = 0;
	options->t = 0;
}
