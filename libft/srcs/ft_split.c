/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahayase <mahayase@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:34:15 by mahayase          #+#    #+#             */
/*   Updated: 2023/06/04 15:56:12 by mahayase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcount(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static size_t	ft_cntsize(char	const *str, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (!str)
		return (cnt);
	while (str[i] != '\0' && i < ft_strlen(str))
	{
		start = i;
		end = start + ft_strcount(&str[i], c);
		if (end > start)
			cnt++;
		i = end + 1;
	}
	return (cnt);
}

static char	**ft_freeall(char **strarr, char const *s)
{
	size_t	i;

	i = 0;
	while (strarr[i])
	{
		if (!s)
			break ;
		free(strarr[i]);
		i++;
	}
	if (strarr)
		free(strarr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strarr;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	strarr = (char **)malloc(sizeof(char *) * (ft_cntsize(s, c) + 1));
	if (strarr == NULL)
		return (NULL);
	while (s[i] != '\0' && i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > j)
			strarr[k++] = ft_strndup(&s[j], i - j);
		if (strarr[k - 1] == NULL)
			return (ft_freeall(strarr, s));
	}
	strarr[k] = NULL;
	return (strarr);
}

// ver. deliminator is string
// static size_t	ft_checkdelim(char c, char *delim)
// {
// 	size_t	i;

// 	i = 0;
// 	while (delim[i] != '\0')
// 	{
// 		if (c == delim[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static size_t	ft_strcount(char const *str, char *delim)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (str[i] != '\0')
// 	{
// 		j = 0;
// 		while (delim[j] != '\0')
// 		{
// 			if (str[i] == delim[j])
// 				return (i);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (i);
// }

// static size_t	ft_cntsize(char	const *str, char *delim)
// {
// 	size_t	i;
// 	size_t	start;
// 	size_t	end;
// 	size_t	cnt;

// 	i = 0;
// 	cnt = 0;
// 	if (!str)
// 		return (cnt);
// 	while (str[i] != '\0' && i < ft_strlen(str))
// 	{
// 		start = i;
// 		end = start + ft_strcount(&str[i], delim);
// 		if (end > start)
// 			cnt++;
// 		i = end + 1;
// 	}
// 	return (cnt);
// }

// static char	**ft_freeall(char **strarr, char const *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (strarr[i])
// 	{
// 		if (!s)
// 			break ;
// 		free(strarr[i]);
// 		i++;
// 	}
// 	if (strarr)
// 		free(strarr);
// 	return (NULL);
// }

// char	**ft_split(char const *s, char *delim)
// {
// 	char	**strarr;
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	strarr = (char **)malloc(sizeof(char *) * (ft_cntsize(s, delim) + 1));
// 	if (strarr == NULL)
// 		return (NULL);
// 	while (s[i] != '\0' && i < ft_strlen(s))
// 	{
// 		while (ft_checkdelim(s[i], delim))
// 			i++;
// 		j = i;
// 		while (!ft_checkdelim(s[i], delim) && s[i] != '\0')
// 			i++;
// 		if (i > j)
// 			strarr[k++] = ft_strndup(&s[j], i - j);
// 		if (strarr[k - 1] == NULL)
// 			return (ft_freeall(strarr, s));
// 	}
// 	strarr[k] = NULL;
// 	return (strarr);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "ls -l|wc -c";
// 	char delim[] = " |";

// 	char **strarr = ft_split(str, delim);
// 	while (*strarr)
// 	{
// 		printf("%s\n", *strarr);
// 		strarr++;
// 	}
// 	return (0);
// }