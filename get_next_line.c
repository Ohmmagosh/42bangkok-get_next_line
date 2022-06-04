/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:10 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/04 18:57:03 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	 *get_next_line(int fd)
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
}	
