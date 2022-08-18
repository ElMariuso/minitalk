/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:08:22 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/18 11:11:26 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_next_char(const char	*format, int i)
{
	int		j;
	char	*all_formats;

	j = 0;
	all_formats = "cspdiuxX%";
	while (all_formats[j] != '\0')
	{
		if (format[i + 1] == all_formats[j])
			return (1);
		j++;
	}
	return (0);
}
