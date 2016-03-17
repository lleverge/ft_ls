/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 09:38:40 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/17 10:33:42 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*int						count_elem(t_elem *list)
{
	int	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
	}*/

t_elem					*ft_elem_swap(t_elem *elem1, t_elem *elem2)
{
	elem1->next = elem2->next;
	elem2->next = elem1;
	return (elem2);
}

t_elem					*ft_sort_ascii(t_elem *elem)
{
	if (elem == NULL)
		return (NULL);
	if (elem->next != NULL && ft_strcmp(elem->name, elem->next->name) > 0)
		elem = ft_elem_swap(elem, elem->next);
	elem->next = ft_sort_ascii(elem->next);
	if (elem->next != NULL && ft_strcmp(elem->name, elem->next->name) > 0)
	{
		elem = ft_elem_swap(elem, elem->next);
		elem->next = ft_sort_ascii(elem->next);
	}
	return (elem);
}

t_elem					*ft_sort_rev(t_elem *elem)
{
	if (elem == NULL)
		return (NULL);
	if (elem->next != NULL && elem->count < elem->next->count)
		elem = ft_elem_swap(elem, elem->next);
	elem->next = ft_sort_rev(elem->next);
	if (elem->next != NULL && elem->count < elem->next->count)
	{
		elem = ft_elem_swap(elem, elem->next);
		elem->next = ft_sort_rev(elem->next);
	}
	return (elem);
}

t_elem					*ft_sort_time(t_elem *elem)
{
	if (!elem)
		return (NULL);
	if (!elem->next)
		return (elem);
	if (elem->modif_last < elem->next->modif_last)
		elem = ft_elem_swap(elem, elem->next);
	else if (elem->modif_last == elem->next->modif_last)
		if (elem->nsec < elem->next->nsec)
			elem = ft_elem_swap(elem, elem->next);
	elem->next = ft_sort_time(elem->next);
	if (elem->modif_last < elem->next->modif_last)
	{
		elem = ft_elem_swap(elem, elem->next);
		elem->next = ft_sort_time(elem->next);
	}
	else if (elem->modif_last == elem->next->modif_last)
	{
		if (elem->nsec < elem->next->nsec)
		{
			elem = ft_elem_swap(elem, elem->next);
			elem->next = ft_sort_time(elem->next);
		}
	}
	return (elem);
}
