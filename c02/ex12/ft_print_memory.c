/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckasyc <ckasyc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:42:37 by ckasyc            #+#    #+#             */
/*   Updated: 2020/08/13 18:42:58 by ckasyc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_str(char *c, int size)
{
	int i;

	i = -1;
	while (i++ < size - 1)
	{
		if (c[i] >= ' ' && c[i] <= '~')
			write(1, &c[i], 1);
		else
			write(1, ".", 1);
	}
}

char	*ft_base_hex(unsigned long long nbr, char *ret, int size, int pos)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr / 16 > 0 && pos < size)
		ft_base_hex(nbr / 16, ret, size, pos + 1);
	ret[size - pos] = base[nbr % 16];
	return (ret);
}

void	ft_print_addr(void *addr)
{
	int		i;
	char	adresse[16];

	i = -1;
	while (i++ < 16)
		adresse[i] = '0';
	ft_base_hex((unsigned long long)addr, adresse, 16, 0);
	i = -1;
	ft_print_str(adresse, 16);
}

void	afficher_ligne(void *addr, int size)
{
	int		i;
	char	buffer[30];

	ft_print_addr(addr);
	ft_print_str(": ", 2);
	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_print_str(ft_base_hex(*(char*)addr, buffer, 1, 0), 2);
		else
			ft_print_str(" ", 1);
		if (i % 2 == 1)
			ft_print_str(" ", 1);
		i++;
		addr++;
	}
	addr -= 16;
	i = 0;
	ft_print_str((char*)addr, size);
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;

	i = size;
	while (i > 16)
	{
		afficher_ligne(addr, 16);
		i -= 16;
		addr += 16;
	}
	afficher_ligne(addr, size % 16);
	addr -= size - (size % 16);
	return (addr);
}

int main()
{
	char str[] = "Bonjour les aminches\r\n\tc  est fou\ttout\tce qu on peut faire avec\r\n\tprint_memory\n\n\tlol.lol \n";
	ft_print_memory(str, 92);
}
