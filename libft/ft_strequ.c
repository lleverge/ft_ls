/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:26:35 by lleverge          #+#    #+#             */
/*   Updated: 2015/11/24 17:41:29 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s2++;
		s1++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}