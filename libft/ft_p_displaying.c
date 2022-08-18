/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_displaying.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:25:04 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/18 11:09:40 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p_displaying(va_list args, int nb_char)
{
	void	*arg;
	int		len;
	char	*tmp_format;

	arg = va_arg(args, void *);
	tmp_format = ft_void_to_hexa((unsigned long int)arg);
	if (!tmp_format)
		return (0);
	len = ft_strlen(tmp_format);
	write(1, "0x", 2);
	write(1, tmp_format, len);
	free(tmp_format);
	return (nb_char + len + 2);
}
