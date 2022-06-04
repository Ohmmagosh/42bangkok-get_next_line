/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:39 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/04 19:01:46 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 1
#endif

typedef struct s_line
{
	char	*buffer;
	char	*buff1;
	int	fd;
	int	start;
	int	last;
}	t_line;

char	*get_next_line(int fd);



#endif
