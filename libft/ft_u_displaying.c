/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_displaying.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:33:27 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/18 11:08:54 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_u_displaying(va_list args, int nb_char)
{
	unsigned int	arg;
	int				len;
	char			*tmp_format;

	arg = va_arg(args, unsigned int);
	tmp_format = ft_utoa(arg);
	if (!tmp_format)
		return (0);
	len = ft_strlen(tmp_format);
	write(1, tmp_format, len);
	free(tmp_format);
	return (nb_char + len);
}
