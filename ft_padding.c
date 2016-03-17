/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 13:04:43 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/13 14:54:23 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_init_pad(t_pad *pad)
{
	pad->links = 0;
	pad->uid = 0;
	pad->gid = 0;
	pad->size = 0;
	pad->min = 0;
	pad->maj = 0;
}

static char		*ft_add_space(char *s, int max)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = max - (int)ft_strlen(s);
	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	if (j > 0)
	{
		while (i < max)
		{
			while (i < j)
				tmp[i++] = ' ';
			k = 0;
			while (i < max)
				tmp[i++] = s[k++];
			i++;
		}
		return (tmp);
	}
	else
		return (s);
}

static void		ft_set_padding(t_elem **elem, t_pad *pad)
{
	t_elem *tmp;

	tmp = *elem;
	while (tmp)
	{
		tmp->links = ft_add_space(tmp->links, pad->links);
		tmp->user = ft_add_space(tmp->user, pad->uid);
		tmp->group = ft_add_space(tmp->group, pad->gid);
		tmp->size = ft_add_space(tmp->size, pad->size);
		if (tmp->min && tmp->maj)
		{
			tmp->min = ft_add_space(tmp->min, pad->min);
			tmp->maj = ft_add_space(tmp->maj, pad->maj);
		}
		tmp = tmp->next;
	}
}

void			ft_padding(t_elem **elem, t_pad *pad)
{
	t_elem	*tmp;

	tmp = *elem;
	ft_init_pad(pad);
	while (tmp->next)
	{
		if (pad->links < ft_strlen(tmp->next->links))
			pad->links = ft_strlen(tmp->next->links);
		if (pad->uid < ft_strlen(tmp->next->user))
			pad->uid = ft_strlen(tmp->next->user);
		if (pad->gid < ft_strlen(tmp->next->group))
			pad->gid = ft_strlen(tmp->next->group);
		if (pad->size < ft_strlen(tmp->next->size))
			pad->size = ft_strlen(tmp->next->size);
		if (pad->min < ft_strlen(ft_itoa(minor(tmp->next->device))))
			pad->min = ft_strlen(ft_itoa(minor(tmp->next->device)));
		if ((pad->maj < ft_strlen(ft_itoa(major(tmp->next->device)))))
			pad->maj = ft_strlen(ft_itoa(major(tmp->next->device)));
		tmp = tmp->next;
	}
	ft_set_padding(elem, pad);
}
