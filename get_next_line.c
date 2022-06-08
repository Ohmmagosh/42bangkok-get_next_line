/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:10 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/09 03:00:32 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_len_nl(char *s)
{
	int	i;

	i = 0;
	while (*s != '\n' && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char	*ret_str(char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_len_nl(s);
	str = malloc(sizeof(char) * (len + 2));
	while (i < len && *(s + i) != '\n' && *(s + i) != '\0')
	{
		*(str + i) = *(s + i);
		i++;
	}
	if (*(s + i) == '\n')
		*(str + i) = '\n';
//	else if (*(s + i) == '\0')
//		*(str + i) = '\0';
	return (str);
}

int     check_line(char *s)
{
	if (!s)
		return (0);
        while (*s)
        {
                if (*s == '\n' )
                        return (1);
                s++;
        }
        return (0);

}

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

	if (!s1 && !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	str1 = (char *)malloc(sizeof(char) * i + 1);
	if (!str1)
		return (NULL);
	while (s1 && *s1)
		*str1++ = *s1++;
	while (*s2)
		*str1++ = *s2++;
	*str1 = '\0';
	str1 = str1 - i;
	return ((char *)str1);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*str;
	char	*ret;

	buffer = malloc(BUFFER_SIZE + 1);
	//buffer = read(fd, buffer, BUFFER_SIZE);
	//str = "";
	while (!check_line(str) && read(fd, buffer, BUFFER_SIZE))
	{
		//read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer);
	//	printf("%s", str);
	//	ret = ret_str(str);	
	}
	ret = ret_str(str);	
	//for (size_t i = 0; i < ft_strlen(); i++)
	//{
	//	printf("%d %c\n",ret[i], ret[i]);
	//}
	return (ret);
}
