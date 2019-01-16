/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:05:34 by cmelara-          #+#    #+#             */
/*   Updated: 2018/12/06 17:00:35 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	str_len;
	char			*substr;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (!(substr = ft_strnew(len)))
		return (NULL);
	while (i < len && s[start])
		substr[i++] = s[start++];
	substr[len] = '\0';
	return (substr);
}
