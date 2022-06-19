/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:04:19 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/20 04:04:37 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_len_nl(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && *(s + i) != '\0')
	{	
		if (*(s + i) == '\n')
		{	
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	size_t	i;
	size_t	j;

	j = ft_strlen(s1);
	i = (ft_strlen(s1) + ft_strlen(s2));
	str1 = (char *)malloc(sizeof(char) * i + 1);
	if (!str1)
		return (NULL);
	while (s1 && *s1)
		*str1++ = *s1++;
	while (s2 && *s2)
		*str1++ = *s2++;
	*str1 = '\0';
	str1 = str1 - i;
	if (s1)
		free(s1 - j);
	return (str1);
}

int	ft_chk_stash(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && *(s + i))
	{	
		if (*(s + i) == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strcpy(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((sizeof(char) * ft_len_nl(s)) + 1);
	if (!ret)
		return (NULL);
	while (ft_len_nl(s) - i)
	{
		*(ret + i) = *(s + i);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_clear_stash(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((sizeof(char) * (ft_strlen(s) - ft_len_nl(s))) + 1);
	if (!ret)
		return (NULL);
	while (s && *(s + i) != '\0' && i < ft_strlen(s) - ft_len_nl(s))
	{
		*(ret + i) = *(s + ft_len_nl(s) + i);
		i++;
	}
	if (s)
		free(s);
	*(ret + i) = '\0';
	if (ret[0] == '\0')
	{	
		free(ret);
		return (NULL);
	}
	return (ret);
}
