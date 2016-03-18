/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:19:26 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/18 13:15:19 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				read_param(char *param)
{
	DIR		*dir;
	t_stat	st;

	if ((dir = opendir(param)))
	{
		closedir(dir);
		return (1);
	}
	else if (!stat(param, &st))
		return (0);
	else
		return (-1);
}

void			ft_sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*swap;

	i = 0;
	j = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[j + 1] != 0)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				swap = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}

static t_elem	*ft_manage_files(char **tab, t_elem *flist)
{
	int		i;
	t_elem	*tmp;
	t_stat	stat;

	tmp = NULL;
	i = 0;
	while (tab[i] && tab[i] != 0)
	{
		if (!(tmp = (t_elem *)malloc(sizeof(t_elem))))
			exit(1);
		if (lstat(tab[i], &stat) <= 0)
			get_infos(tab[i], tmp, stat);
		if (tmp->perm[0] == 'd' && tmp->perm[1] == '-')
			ft_error_rights(tab[i]);
		else if (read_param(tab[i]) == 0)
			flist = info_in_list(flist, tab[i], tab[i]);
		i++;
	}
	return (flist);
}

static void		ft_manage_rep(char **tab, t_elem *rlist, t_opt *opt, t_pad *pad)
{
	int		i;
	int		count;
	char	**rep_tab;

	i = 0;
	count = count_rep(tab);
	rep_tab = NULL;
	if (!count)
		return ;
	if (!(rep_tab = (char **)malloc(sizeof(char *) * (count + 1))))
		exit(1);
	rep_in_tab(tab, rep_tab);
	sort_arg(rep_tab, opt);
	while (rep_tab[i] != NULL)
	{
		rlist = ft_create_list(rlist, ft_add_slash(rep_tab[i]));
		ft_repname(rep_tab[i], ft_count_tab(tab), opt);
		if (opt->l == 1)
			count_blocks(&rlist, opt);
		ft_display_rep(rlist, opt, pad);
		free_list(&rlist);
		i++;
	}
	if (rep_tab[0])
		free_tab(rep_tab);
}

void			ft_list(char **tab, t_opt *opt)
{
	t_elem	*file_list;
	t_elem	*rep_list;
	t_pad	*pad;

	pad = NULL;
	if (!(file_list = (t_elem *)malloc(sizeof(t_elem))) ||
		!(rep_list = (t_elem *)malloc(sizeof(t_elem))) ||
		!(pad = (t_pad *)malloc(sizeof(t_pad))))
		exit(1);
	file_list = NULL;
	rep_list = NULL;
	ft_manage_error(tab);
	file_list = ft_manage_files(tab, file_list);
	if (file_list)
	{
		ft_display_file(file_list, opt, pad);
		free_list(&file_list);
		ft_putchar('\n');
	}
	ft_manage_rep(tab, rep_list, opt, pad);
	free_pad(&pad);
}
