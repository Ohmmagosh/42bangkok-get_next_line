/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:10 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/19 04:45:00 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		i++;
	return (i);
}

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
	//if (ft_len_nl(s2))
	//	return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	str1 = (char *)malloc(sizeof(char) * i + 1);
	if (!str1)
		return (NULL);
	while (s1  && *s1)
	{
		*str1++ = *s1++;
	}
	while (s2  &&  *s2)
		*str1++ = *s2++;
	*str1 = '\0';
	str1 = str1 - i;
	if (s1)
		free(s1 - j);
//	free(s2);
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
	int	i;

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
	//printf("|strcpy = %s\n|", ret);
	//printf("ret: %p s: %p\n", ret, s);
	return (ret);
}

char	*ft_clear_stash(char *s)
{
	char	*ret;
	int	i;

	i = 0;
	ret = malloc((sizeof(char) * (ft_strlen(s) - ft_len_nl(s))) + 1);
	//printf("alloc size: %lu\n", (sizeof(char) * (ft_strlen(s) - ft_len_nl(s)) + 1));
	if (!ret)
		return (NULL);
	//while (s && *(s + i) != '\0')
	while (s && *(s + i) != '\0' && i < ft_strlen(s) - ft_len_nl(s))
	{
		*(ret + i) = *(s + ft_len_nl(s) + i + 1);
		i++;
	}
	//printf("sth: |ret = %p (%s), s = %p (%s)|\n", ret, ret,s,s);
	if (s)
		free(s);
	*(ret + i) = '\0';
	if (ret[0] == '\0'/* || ret[ft_len_nl(ret)] == '\0'*/)
	{	
		free(ret);
		return (NULL);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*ret;
	int	rd;
	static char	*str[OPEN_MAX];
	char	*buffer;

	rd = 1;
	ret = NULL;
	if (fd < 0 && BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	while (ft_chk_stash(str[fd]) && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd == 0)
			break;
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	free(buffer);
	if (ft_strlen(str[fd]) > 0)
		ret = ft_strcpy(str[fd]);
	else
	{
		free(str[fd]);
		return (NULL);
		//ret = NULL;
	}
	//printf("bef: |ret = %p (%s), s = %p (%s)|\n", ret, ret,str[fd],str[fd]);
	if (ret)
		str[fd] = ft_clear_stash(str[fd]);
	//printf("aft: |ret = %p (%s), s = %p (%s)|\n", ret, ret,str[fd],str[fd]);
	return (ret);
}
/*
int	main(void)
{
	int	fd = 0;
	char	*str;
	fd = open("hello2",O_RDONLY);
	for(int	i = 0; i < 2; i++)
	{
		str = get_next_line(fd);
		printf("%d) result = |%s|", i, str);
		if(str)
			free(str);
	}
	return (0);
}*/
