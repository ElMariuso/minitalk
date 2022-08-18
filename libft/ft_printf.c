/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:40:44 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/18 11:10:00 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checking(const char	*format, va_list args, int i, int nb_char)
{
	if (ft_check_next_char(format, i) == 1)
	{
		nb_char = ft_check_format(format, args, i, nb_char);
		return (nb_char);
	}
	return (0);
}

int	ft_printf(const char	*format, ...)
{
	va_list	args;
	int		i;
	int		nb_char;

	va_start(args, format);
	i = 0;
	nb_char = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			nb_char = ft_checking(format, args, i, nb_char);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			nb_char++;
			i++;
		}
		if (!format[i])
			break ;
	}
	va_end(args);
	return (nb_char);
}
