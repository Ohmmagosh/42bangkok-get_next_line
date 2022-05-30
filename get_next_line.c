/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:10 by psuanpro          #+#    #+#             */
/*   Updated: 2022/05/30 23:48:13 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	 *get_next_line(int fd)
{
	char	*buff;
	int	readbuffer;
	int	i;

	i = 0;
	buff = malloc(sizeof(char) * 6);
	if (fd < 0)
		return (NULL);
	while (i < 10)
	{
		readbuffer = read(fd, buff, 5);
		printf("%d\n", readbuffer);
		printf("%s\n", buff);
		i++;
	}
	return ("hello welcome1");
}	
