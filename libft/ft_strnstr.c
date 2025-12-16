/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:15:42 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/04 10:32:30 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < loc)
	{
		n = 0;
		while (haystack[i + n] != '\0' && haystack[i + n] == needle[n] && i
			+ n < loc)
		{
			if (needle[n + 1] == '\0')
				return ((char *)&haystack[i]);
			++n;
		}
		++i;
	}
	return (NULL);
}
