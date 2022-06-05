/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:10 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/05 15:05:10 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	str1 = (char *)malloc(sizeof(char) * i + 1);
	if (!str1)
		return (NULL);
	while (*s1)
		*str1++ = *s1++;
	while (*s2)
		*str1++ = *s2++;
	*str1 = '\0';
	str1 = str1 - i;
	return ((char *)str1);
}

/*char	 *get_next_line(int fd)
{
	t_line	test;
	int	i;
	int	readbuffer;
	i = 0;	
	test.buffer = malloc(10);

	test.buff1 = malloc(sizeof(char) * 6);
	if (fd < 0 || !test.buff1)
		return (NULL);
	while (i < 10)
	{
		readbuffer = read(fd, test.buff1, BUFFER_SIZE);
		printf("%d\n", readbuffer);
		printf("%s\n", test.buff1);
		i++;
	}
	return ("hello welcome");
} */













