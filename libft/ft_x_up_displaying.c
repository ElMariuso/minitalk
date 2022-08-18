/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_up_displaying.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:44:22 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/18 11:08:30 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*format_toupper(char	*tmp_format)
{
	int	i;

	i = 0;
	while (tmp_format[i])
	{
		tmp_format[i] = ft_toupper(tmp_format[i]);
		i++;
	}
	return (tmp_format);
}

int	ft_x_up_displaying(va_list args, int nb_char)
{
	unsigned int	arg;
	int				len;
	char			*tmp_format;

	arg = va_arg(args, unsigned int);
	if (arg == 0)
	{
		write(1, "0", 1);
		return (nb_char + 1);
	}
	tmp_format = ft_u_int_to_hexa(arg);
	if (!tmp_format)
		return (0);
	len = ft_strlen(tmp_format);
	tmp_format = format_toupper(tmp_format);
	write(1, tmp_format, len);
	free(tmp_format);
	return (nb_char + len);
}
