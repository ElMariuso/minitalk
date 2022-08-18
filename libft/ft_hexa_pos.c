/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:40:33 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/24 16:42:23 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*fill_hexa(char *hexa, unsigned long int c, char *base, int count)
{
	while (c != 0)
	{
		hexa[count] = base[c % 16];
		c = c / 16;
		count--;
	}
	return (hexa);
}

char	*ft_int_to_hexa_pos(unsigned long int c)
{
	char				*hexa;
	char				*base;
	unsigned long int	t;
	int					count;

	base = "0123456789abcdef";
	t = c;
	count = 1;
	while (t >= 16)
	{
		t = t / 16;
		count++;
	}
	hexa = (char *) malloc ((count + 1) * sizeof(char));
	if (!hexa)
		return (NULL);
	if (c == 0)
		hexa[0] = '0';
	hexa[count] = '\0';
	count--;
	return (fill_hexa(hexa, c, base, count));
}
