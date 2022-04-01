# Piscine 42 - Aout 2020
```
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Piscine - Aout 2020                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrkcyrk                                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 09:00:00                      #+#    #+#             */
/*   Updated: 2020/08/28 18:00:00                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Voici tous mes codes effectués durant ma piscine de 42 Paris.

![scores globaux](https://github.com/Cyrkcyrk/Piscine42/blob/master/Scores%20globaux.png?raw=true)

Je n'ai malheureusement pas eu le temps durant cette piscine de valider a 100% l'intégralitée des modules que j'ai fait, aussi c'est pourquoi certains ne sont pas à 100%.

- Le c04ex4 est probablement due à une mauvaise gestion du int minimum (comme je le multiplie par -1, ca peut poser problème).
- Le c08ex05 est due à une correction trop tardive faite en fin de piscine (donc fatigué) ou je putnbr une string et putstr un nombre.
- Le c13ex06 est du a une mauvaise analyse de ma récursivitée et un mauvais parcours de mon arbre. Rappeller `btree_level_count` à la place des `right` et `left` dans les deux fonctions respective réparerai probablement l'erreur.
- Le c13ex07 ne passe pas la moulinettes, et je n'ai pas encore eu le temps d'essayer de comprendre pourquoi.
- Le shell01ex07 ne passe pas la moulinette, et le shell01ex08 n'a simplement pas été fait.
- Le BSQ est fonctionnel, mais nous n'avons pas eu le temps de trouver les créneaux de corrections avant la fin de la piscine pour nous faire corriger. Aussi, nous ne saurons probablement jamais si il aurait passé la moulinette ou pas.

PS pour les piscineux: ca ne sert à rien de copier/coller ce code (ou d'autres) depuis internet. En plus de ne pas apprendre ni comprendre, vous risquez juste un beau -42 et d'être inccapable de refaire l'exercice en examens (et vous vous doutez bien que c'est un critère regardé). Je le met à disposition pour aider à la compréhension des exercices et algorithmes, pas pour aider à tricher, donc ne soyez pas stupide ;)

## Liste des exercices:
```
Shell00
	00 :	Z
	01 :	testShell00
	02 :	Owi, encore...
	03 :	Connecte-moi!
	04 :	midLS
	05 :	GiT commit
	06 :	gitignore
	07 :	diff
	08 :	clean
	09 :	Illusions, not tricks, Michael...

Shell01
	00 :	Exam machine
	01 :	print_groups
	02 :	find_sh
	03 :	count_files
	04 :	MAC
	05 :	Can you create it?
	06 :	Skip
	07 :	r_dwssap
	08 :	add_chelou

C00:
	00 :	ft_putchar
	01 :	ft_print_alphabet
	02 :	ft_print_reverse_alphabet
	03 :	ft_print_numbers
	04 :	ft_is_negative
	05 :	ft_print_comb
	06 :	ft_print_comb2
	07 :	ft_putnbr
	08 :	ft_print_combn

C01
	00 :	ft_ft
	01 :	ft_ultimate_ft
	02 :	ft_swap
	03 :	ft_div_mod
	04 :	ft_ultimate_div_mod
	05 :	ft_putstr
	06 :	ft_strlen
	07 :	ft_rev_int_tab
	08 :	ft_sort_int_tab

C02
	00 :	ft_strcpy
	01 :	ft_strncpy
	02 :	ft_str_is_alpha
	03 :	ft_str_is_numeric
	04 :	ft_str_is_lowercase
	05 :	ft_str_is_uppercase
	06 :	ft_str_is_printable
	07 :	ft_strupcase
	08 :	ft_strlowcase
	09 :	ft_strcapitalize
	10 :	ft_strlcpy
	11 :	ftèputstr_non_printable
	12 :	ft_print_memory

C03
	00 :	ft_strcmp
	01 :	ft_strncmp
	02 :	ft_strcat
	03 :	ft_strncat
	04 :	ft_strstr
	05 :	ft_strlcat

C04
	00 :	ft_strlen
	01 :	ft_putstr
	02 :	ft_putnbr
	03 :	ft_atoi
	04 :	ft_putnbr_base
	05 :	ft_atoi_base

C05
	00 :	ft_iterative_factorial
	01 :	ft_recursive_factorial
	02 :	ft_iterative_power
	03 :	ft_recursive_power
	04 :	ft_fibonacci
	05 :	ft_sqrt
	06 :	ft_is_prime
	07 :	ft_find_next_prime
	08 :	Les dix dames

C06
	00 :	ft_print_program_name
	01 :	ft_print_params
	02 :	ft_rev_params
	03 :	ft_sort_params

C07
	00 :	ft_strdup
	01 :	ft_range
	02 :	ft_ultimate_range
	03 :	ft_strjoin
	04 :	ft_convert_base
	05 :	ft_split

C08
	00 :	ft.h
	01 :	ft_boolean.h
	02 :	ft_abs.h
	03 :	ft_point.h
	04 :	ft_strs_to_tab
	05 :	ft_show_tab

C09
	00 :	libft
	01 :	Makefile
	02 :	ft_split

C10
	00 :	display_file
	01 :	cat
	02 :	tail
	03 :	hexdump

C11
	00 :	ft_foreach
	01 :	ft_map
	02 :	ft_any
	03 :	ftècount_if
	04 :	ft_is_sort
	05 :	do-op
	06 :	ft_sort_string_tab
	07 :	ft_advanced_sort_string_tab

C12
	00 :	ft_create_elem
	01 :	ft_list_push_front
	02 :	ft_list_size
	03 :	ft_list_last
	04 :	ft_list_push_back
	05 :	ft_list_push_strs
	06 :	ft_list_clear
	07 :	ft_list_at
	08 :	ft_list_reverse
	09 :	ft_list_foreach
	10 :	ft_list_foreach_if
	11 :	ft_list_find
	12 :	ft_list_remove_if
	13 :	ft_list_merge
	14 :	ft_list_sort
	15 :	ft_list_reverse_fun
	16 :	ft_sorted_list_invert
	17 :	ft_sorted_list_merge

C13
	00 :	btree_create_node
	01 :	btree_apply_prefix
	02 :	btree_apply_infix
	03 :	btree_apply_suffix
	04 :	btree_insert_data
	05 :	btree_search_item
	06 :	btree_level_count
	07 :	btree_apply_by_level
```
