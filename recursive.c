/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:11:05 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/18 16:27:18 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_count_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int				ft_count_dir(t_elem *elem)
{
	int	i;

	i = 0;
	while (elem)
	{
		if (elem->is_dir)
			i++;
		elem = elem->next;
	}
	return (i);
}

void			ft_put_css(char c, char *s1, char *s2)
{
	ft_putchar(c);
	ft_putstr(s1);
	ft_putstr(s2);
}

char			*ft_add_slash(char *path)
{
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_strjoin(path, "/");
	return (path);
}

void			ft_recursive(t_elem *elem, t_opt *opt, int nb_dir)
{
	char			**all_dir;
	int				i;

	i = 0;
	if (!(all_dir = (char **)malloc(sizeof(char *) * nb_dir + 1)))
		exit(1);
	while (elem)
	{
		if (elem->is_dir == 1)
		{
			if (opt->a == 0 && elem->name[0] != '.')
			{
				all_dir[i] = ft_strdup(ft_add_slash(elem->path));
				i++;
			}
			else if (opt->a == 1 && REAL_DIR(elem->name))
			{
				all_dir[i] = ft_strdup(ft_add_slash(elem->path));
				i++;
			}
		}
		elem = elem->next;
	}
	all_dir[i] = NULL;
	ft_list(all_dir, opt);
}
