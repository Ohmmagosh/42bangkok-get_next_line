/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 04:03:40 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/20 04:03:55 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd)
{
	int			rd;
	char		*ret;
	char		*buffer;
	static char	*str[OPEN_MAX];

	rd = 1;
	ret = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	while (ft_chk_stash(str[fd]) && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd <= 0)
			break ;
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	free(buffer);
	if (ft_strlen(str[fd]) > 0)
		ret = ft_strcpy(str[fd]);
	else
		free(str[fd]);
	str[fd] = ft_clear_stash(str[fd]);
	return (ret);
}
