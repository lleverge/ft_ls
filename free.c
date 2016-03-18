/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:40:39 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/18 11:00:27 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_list(t_elem **head)
{
	t_elem	*current;
	t_elem	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		ft_strdel(&(current->name));
		ft_strdel(&(current->path));
		ft_strdel(&(current->create));
		ft_strdel(&(current->perm));
		ft_strdel(&(current->user));
		ft_strdel(&(current->group));
		ft_strdel(&(current->links));
		ft_strdel(&(current->size));
		ft_strdel(&(current->min));
		ft_strdel(&(current->maj));
		free(current);
		current = next;
	}
	*head = NULL;
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

void		free_pad(t_pad **head)
{
	free(*head);
	*head = NULL;
}

void		free_opt(t_opt **head)
{
	free(*head);
	*head = NULL;
}
