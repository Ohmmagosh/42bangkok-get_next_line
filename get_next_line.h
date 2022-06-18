/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:39 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/18 01:43:06 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 5
# endif

int     ft_len_nl(char *s);
char    *ft_strjoin(char *s1, char  *s2);
int     ft_chk_stash(char *s);
char    *ft_strcpy(char *s);
char    *ft_clear_stash(char *s);
char    *get_next_line(int fd);
int     ft_strlen(char *s);
#endif
