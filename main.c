/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:24:16 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/16 16:46:27 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*info_in_list(t_elem *start, char *fname, char *path)
{
	t_stat		stat;
	t_elem		*tmp;
	t_elem		*voyager;

	tmp = (t_elem *)malloc(sizeof(t_elem));
	voyager = start;
	if (lstat(path, &stat) <= 0)
	{
		get_infos(fname, tmp, stat);
		if (getpwuid(stat.st_uid) != NULL)
			tmp->user = ft_strdup(getpwuid(stat.st_uid)->pw_name);
		else
			tmp->user = ft_strdup("");
		if (getgrgid(stat.st_gid) != NULL)
			tmp->group = ft_strdup(getgrgid(stat.st_gid)->gr_name);
		else
			tmp->group = ft_strdup("");
	}
	tmp->path = path;
	if (start == NULL)
		return (tmp);
	while (voyager->next)
		voyager = voyager->next;
	voyager->next = tmp;
	return (start);
}

void		ft_display_rep(t_elem *list, char *r_name, t_opt *opt, t_pad *pad)
{
	if (!list)
		return ;
	list = ft_sort_ascii(list);
	if (opt->t == 1)
		list = ft_sort_time(list);
	list = ft_index_list(list);
	if (opt->r == 1)
		list = ft_sort_rev(list);
	ft_putstr(remove_slash(r_name));
	ft_putstr(":\n");
	if (opt->l == 1)
	{
		ft_putstr("total ");
		ft_putnbr(count_blocks(list, opt));
		ft_putchar('\n');
		ft_padding(&list, pad);
	}
	display_l(list, opt);
	if (opt->rec == 1)
		ft_recursive(list, opt, ft_count_dir(list));
}

void		ft_display_file(t_elem *list, t_opt *options, t_pad *pad)
{
	if (list == NULL)
		return ;
	list = ft_sort_ascii(list);
	if (options->t == 1)
		list = ft_sort_time(list);
	list = ft_index_list(list);
	if (options->r == 1)
		list = ft_sort_rev(list);
	if (options->l == 1)
		ft_padding(&list, pad);
	display_l(list, options);
}

t_elem		*ft_create_list(t_elem *list, char *path)
{
	DIR				*ret;
	struct dirent	*elem;

	ret = opendir(path);
	elem = readdir(ret);
	while (elem)
	{
		list = info_in_list(list, elem->d_name, ft_strjoin(path, elem->d_name));
		elem = readdir(ret);
	}
	closedir(ret);
	return (list);
}

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tab;
	t_opt	*options;

	i = 0;
	j = 0;
	options = NULL;
	if (!(options = (t_opt *)malloc(sizeof(t_opt))))
		return (-1);
	init_opt(options);
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			ft_detect_opt(argv[i], options);
	}
	tab = arg_in_tab(argc, argv);
	ft_list(tab, options);
	//free_tab(tab);
	return (0);
}
