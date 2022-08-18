/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:49:12 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/24 16:40:02 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_int_to_hexa(int c)
{
	if (c > 0)
		return (ft_int_to_hexa_pos(c));
	else if (c < 0)
		return (ft_int_to_hexa_neg(c));
	return (0);
}

char	*ft_u_int_to_hexa(unsigned int c)
{
	return (ft_int_to_hexa_pos(c));
}

char	*ft_void_to_hexa(unsigned long int c)
{
	return (ft_int_to_hexa_pos((unsigned long int)c));
}
