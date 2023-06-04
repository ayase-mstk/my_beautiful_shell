/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:35:42 by mahayase          #+#    #+#             */
/*   Updated: 2023/05/30 19:32:47 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strstr(char const *charset, char to_find)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == to_find)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_startpoint(char const *str, char const *charset)
{
	size_t	i;

	i = 0;
	while (ft_strstr(charset, str[i]) != 0 && str[i])
		i++;
	return (i);
}

static size_t	ft_endpoint(char const *str, char const *charset)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (ft_strstr(charset, str[i]) == 1)
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*trim;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(set))
		return (ft_strdup((char *)s1));
	start = ft_startpoint(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_endpoint(s1, set);
	trim = ft_strndup(&s1[start], end - start);
	if (trim == NULL)
		return (NULL);
	return (trim);
}
