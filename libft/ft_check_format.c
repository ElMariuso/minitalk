/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:56:28 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/18 11:11:36 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_format(const char	*format, va_list args, int i, int nb_char)
{
	if (format[i + 1] == 'c')
		nb_char = ft_c_displaying(args, nb_char);
	else if (format[i + 1] == 's')
		nb_char = ft_s_displaying(args, nb_char);
	else if (format[i + 1] == 'p')
		nb_char = ft_p_displaying(args, nb_char);
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		nb_char = ft_d_and_i_displaying(args, nb_char);
	else if (format[i + 1] == 'u')
		nb_char = ft_u_displaying(args, nb_char);
	else if (format [i + 1] == 'x')
		nb_char = ft_x_displaying(args, nb_char);
	else if (format[i + 1] == 'X')
		nb_char = ft_x_up_displaying(args, nb_char);
	else if (format[i + 1] == '%')
		nb_char = ft_percent_displaying(nb_char);
	return (nb_char);
}
