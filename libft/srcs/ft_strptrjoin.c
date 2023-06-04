/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strptrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:22:14 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/28 13:22:15 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strptrjoin(char **s1, char**s2)
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strptrlen(s1) + ft_strptrlen(s2);
	p = (char **)malloc(sizeof(char *) * (size + 1));
	if (p == NULL)
		return (NULL);
	while (s1[j])
		p[i++] = s1[j++];
	j = 0;
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = NULL;
	return (p);
}
