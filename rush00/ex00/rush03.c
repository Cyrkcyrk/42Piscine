/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:41:22 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/09 19:35:08 by abaudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef long long t_i64;
void	ft_putchar(char c);

void	ft_print_line(t_i64 x, char left, char middle, char right)
{
	ft_putchar(left);
	if (x > 1)
	{
		while (x-- > 2)
			ft_putchar(middle);
		ft_putchar(right);
	}
	ft_putchar('\n');
}

void	rush(t_i64 x, t_i64 y)
{
	if (x > 0 && y > 0)
	{
		ft_print_line(x, 'A', 'B', 'C');
		if (y > 1)
		{
			while (y-- > 2)
				ft_print_line(x, 'B', ' ', 'B');
			ft_print_line(x, 'A', 'B', 'C');
		}
	}
}
