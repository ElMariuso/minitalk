/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:48:27 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/22 18:53:01 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_size(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	utoa_loop(int i, int size, unsigned long num, char *nc)
{
	while (num != 0)
	{
		nc[size - i++] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_utoa(unsigned int n)
{
	int				i;
	int				size;
	unsigned int	num;
	char			*nc;

	i = 0;
	size = ft_get_size(n);
	num = n;
	nc = (char *) malloc (size + 1 * sizeof(char));
	if (!nc)
		return (0);
	if (n == 0)
		nc[0] = '0';
	i++;
	utoa_loop(i, size, num, nc);
	nc[size] = '\0';
	return (nc);
}
