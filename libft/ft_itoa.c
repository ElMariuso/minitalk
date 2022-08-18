/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:20:42 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:47:52 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_size(int n)
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

static void	itoa_loop(int i, int size, long num, char *nc)
{
	while (num != 0)
	{
		nc[size - i++] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	long	num;
	char	*nc;

	i = 0;
	size = ft_get_size(n);
	num = n;
	nc = (char *) malloc (size + 1 * sizeof(char));
	if (!nc)
		return (0);
	if (n == 0)
		nc[0] = '0';
	else if (num < 0)
	{
		nc[i] = '-';
		num *= -1;
	}
	i++;
	itoa_loop(i, size, num, nc);
	nc[size] = '\0';
	return (nc);
}
