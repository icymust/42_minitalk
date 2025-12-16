/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:16:17 by mmustone          #+#    #+#             */
/*   Updated: 2025/08/05 11:15:44 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		dst_pos;
	int		s1_len;
	int		s2_len;
	int		i;

	dst = check(s1, s2);
	if (dst)
		return (dst);
	dst_pos = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	dst = malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	while (i < s1_len)
		dst[dst_pos++] = s1[i++];
	i = 0;
	while (i < s2_len)
		dst[dst_pos++] = s2[i++];
	dst[dst_pos] = '\0';
	return (dst);
}
