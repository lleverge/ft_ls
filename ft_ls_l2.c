/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:12:50 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/17 18:27:10 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_l(t_elem *list, t_opt *opt, t_pad *pad)
{
	if (!list)
		return ;
	while (list)
	{
		if (opt->a == 1)
		{
			ft_padding(&list, pad);
			print_infos(list, opt);
			ft_putchar('\n');
		}
		else
		{
			if (list->name[0] != '.')
			{
				ft_padding(&list, pad);
				print_infos(list, opt);
				ft_putchar('\n');
			}
		}
		list = list->next;
	}
}

void		ft_print_majmin(t_elem *list)
{
	if (list->perm[0] == 'b' || list->perm[0] == 'c')
	{
		ft_putstr(list->maj);
		ft_putstr(", ");
		ft_putstr(list->min);
		ft_putstr(" ");
	}
	else
		ft_putstr(list->size);
}

void		ft_put_link(char *path)
{
	char	buffer[1024];
	int		ret;

	ret = readlink(path, buffer, 1023);
	if (ret == -1)
		return ;
	buffer[ret] = '\0';
	ft_putstr(" -> ");
	ft_putstr(buffer);
}

t_elem		*ft_index_list(t_elem *elem)
{
	t_elem	*tmp;
	int		i;

	tmp = elem;
	i = 0;
	while (tmp)
	{
		tmp->count = i;
		i++;
		tmp = tmp->next;
	}
	return (elem);
}

char		*ft_get_pathname(t_elem *elem, char *path)
{
	char	*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		elem->path = ft_strjoin(elem->name, "/");
		ft_strdel(&tmp);
	}
	else
		elem->path = ft_strjoin(path, elem->name);
	return (path);
}
