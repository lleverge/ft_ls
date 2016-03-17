/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:25:02 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/17 11:21:02 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define REAL_DIR(x) (ft_strcmp(x, "..") != 0 && ft_strcmp(x, ".") != 0)
# define TIMENSEC st_mtimespec.tv_nsec

typedef struct		s_opt
{
	int				l;
	int				a;
	int				rec;
	int				r;
	int				t;
}					t_opt;

typedef struct		s_pad
{
	size_t			links;
	size_t			uid;
	size_t			gid;
	size_t			size;
	size_t			min;
	size_t			maj;
}					t_pad;

typedef struct		s_elem
{
	char			*path;
	char			*name;
	long long		modif_last;
	char			*create;
	int				blocks;
	char			*perm;
	char			*links;
	char			*user;
	char			*group;
	int				is_dir;
	int				count;
	char			*size;
	dev_t			device;
	char			*min;
	char			*maj;
	int				nsec;
	struct s_elem	*next;
}					t_elem;

typedef struct stat	t_stat;

void				ft_error_rights(char *path);
void				rep_in_tab(char **tab, char **rep_tab);
int					count_rep(char **tab);
int					count_elem(t_elem *list);
void				ft_sort_tab(char **tab);
int					read_param(char *param);
void				error_in_tab(char **tab, char **error_tab);
void				ft_manage_error(char **tab);
int					count_error(char **tab);
void				ft_put_css(char c, char *s1, char *s2);
void				free_tab(char **tab);
void				ft_list(char **tab, t_opt *opt);
char				**arg_in_tab(int argc, char **argv);
char				*ft_lastword(char *s);
char				*ft_get_time(const long *f_time);
char				*remove_slash(char *name);
char				*ft_get_pathname(t_elem *elem, char *path);
void				ft_put_link(char *path);
void				free_list(t_elem **head);
void				free_pad(t_pad **head);
void				free_opt(t_opt **head);
char				*ft_add_slash(char *path);
int					ft_count_dir(t_elem *elem);
void				ft_recursive(t_elem *elem, t_opt *opt, int nb_dir);
void				ft_print_majmin(t_elem *list);
t_elem				*ft_index_list(t_elem *elem);
t_elem				*ft_sort_rev(t_elem *elem);
void				opt_error(char *s);
void				ft_detect_opt(char *arg, t_opt *options);
void				init_opt(t_opt *options);
void				no_file_dir(char *fname);
void				ft_padding(t_elem **elem, t_pad *pad);
int					count_blocks(t_elem *list, t_opt *options);
void				print_infos(t_elem *list, t_opt *options);
t_elem				*ft_sort_time(t_elem *elem);
t_elem				*ft_sort_ascii(t_elem *elem);
t_elem				*info_in_list(t_elem *start, char *fname, char *path);
char				*ft_rights(char *perm, int i, t_stat *stat);
char				*ft_perm(t_stat *stat);
t_elem				*ft_create_list(t_elem *list, char *path);
void				get_infos(char *fname, t_elem *tmp, t_stat stat);
t_elem				*ft_elem_swap(t_elem *elem1, t_elem *elem2);
void				display_l(t_elem *list, t_opt *opt);
void				ft_display_file(t_elem *elem, t_opt *options,
							t_pad *pad);
void				ft_display_rep(t_elem *elem, char *rep_name, t_opt *options,
									t_pad *pad);
void				display_error(char **tab);
#endif
