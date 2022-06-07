/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:39 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/08 04:00:17 by psuanpro         ###   ########.fr       */
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
/*
typedef struct s_line
{

}	t_line;
*/
char	*get_next_line(int fd);
int     check_line(char *s);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t  ft_strlen(const char *s);
char    *ret_str(char *s);
size_t  ft_len_nl(char *s);

#endif
