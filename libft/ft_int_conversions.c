/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:44:29 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/21 19:10:49 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_8bit_binary_to_int(char	*bin)
{
	int	i;
	int	quotient;
	int	count;

	i = 0;
	quotient = 128;
	count = 0;
	while (bin[i] != '\0')
	{
		bin[i] -= 48;
		if (bin[i] == 1)
			count += quotient;
		quotient = quotient / 2;
		i++;
	}
	return (count);
}
