/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_neg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:31:53 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/18 11:43:37 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_binary(char *bin)
{
	int	i;

	i = 0;
	while (bin[i] != '\0')
	{
		if (bin[i] == '0')
			bin[i] = '1';
		else if (bin[i] == '1')
			bin[i] = '0';
		i++;
	}
	return (bin);
}

char	neg_hexa_first(char *bin)
{
	char	first_char;
	char	*base;
	int		temp;

	base = "0123456789abcdef";
	temp = 0;
	if (bin[0] == '1')
		temp += 2 * 2 * 2;
	if (bin[1] == '1')
		temp += 2 * 2;
	if (bin[2] == '1')
		temp += 2;
	if (bin[3] == '1')
		temp++;
	first_char = base[temp];
	return (first_char);
}

char	neg_hexa_second(char *bin)
{
	char	second_char;
	char	*base;
	int		temp;

	base = "0123456789abcdef";
	temp = 0;
	if (bin[4] == '1')
		temp += 2 * 2 * 2;
	if (bin[5] == '1')
		temp += 2 * 2;
	if (bin[6] == '1')
		temp += 2;
	if (bin[7] == '1')
		temp++;
	second_char = base[temp];
	return (second_char);
}

char	*ft_int_to_hexa_neg(int c)
{
	char	*hexa;
	char	*bin;
	int		temp;

	hexa = (char *) malloc (3 * sizeof(char));
	if (!hexa)
		return (NULL);
	bin = ft_int_to_8bit_binary(c);
	if (!bin)
		return (NULL);
	bin = ft_reverse_binary(bin);
	temp = ft_8bit_binary_to_int(bin) + 1;
	free(bin);
	bin = ft_int_to_8bit_binary(temp);
	hexa[0] = neg_hexa_first(bin);
	hexa[1] = neg_hexa_second(bin);
	hexa[2] = '\0';
	free(bin);
	return (hexa);
}
