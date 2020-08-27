/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 12:25:16 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/23 22:08:46 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CK_DICT_H
# define CK_DICT_H

# include "structs.h"

/*
**		file.c
*/
int		dict_len_file(char *path);
char	*dict_to_str(char *path);
char	**parse_dict_file(char *path);
/*
**		parse_line.c
*/
int		check_if_followed_zero(char *str, int len_trip);
void	parse_number(t_key *dict, char *str);
t_key	*parse_dict_strs(char **strs);
/*
**		parse_key_str.c
*/
int		nb_start_at(char *str);
int		is_line_valid(char *str);
int		key_start_pos(char *str);
int		key_len(char *str, int start);
char	*parse_key(char *str);
/*
**		dict.c
*/
int		dict_nb_key(char **strs);
t_key	*parse_dict(char *path);
/*
**		dict_free.c
*/
void	ft_free_strs(char **strs);
void	ft_free_tab_key(t_key *tab);
void	ft_free_dict(t_key *tab);
/*
**		Autre
*/
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);

int		valid_table(char **tbl);

#endif
