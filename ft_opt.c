/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:12:00 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/18 16:39:18 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_perm(char *name)
{
	t_stat	stat;
	t_elem	*tmp;

	if (!(tmp = (t_elem *)malloc(sizeof(t_elem))))
		exit(1);
	if (lstat(name, &stat) <= 0)
		get_infos(name, tmp, stat);
	if (tmp->perm[0] == 'd' && (tmp->perm[1] == '-' || tmp->perm[4] == '-'))
	{
		ft_error_rights(name);
		return (-1);
	}
	else
		return (0);
}

void	ft_detect_opt(char *arg, t_opt *options)
{
	int	i;

	i = 0;
	while (arg[++i] != '\0')
	{
		if (!(ft_strcmp("", arg)))
			ft_check_void_av();
		else if (arg[i] == 't')
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
