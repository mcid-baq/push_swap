/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:12:30 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/02/21 12:47:11 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	count_words(char const *str, char c)
{
	int	counter;
	int	trigger;

	counter = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			counter++;
			trigger = 1;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (counter);
}

static char	*split_word(const char *str, int first, int last)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((last - first + 1) * sizeof(char));
	while (first < last)
		word[i++] = str[first++];
	word[i] = '\0';
	return (word);
}

static char	**splitting(char **split, char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		first;

	i = 0;
	j = 0;
	first = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && first < 0)
			first = i;
		else if ((str[i] == c || i == ft_strlen(str)) && first >= 0)
		{
			split[j++] = split_word(str, first, i);
			first = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	char	**split;

	if (!str)
		return (0);
	split = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	return (splitting(split, str, c));
}
