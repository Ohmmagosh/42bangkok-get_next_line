/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:39:39 by psuanpro          #+#    #+#             */
/*   Updated: 2022/06/20 04:08:21 by psuanpro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_len_nl(char *s);
int		ft_strlen(char *s);
int		ft_chk_stash(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *s);
char	*ft_clear_stash(char *s);
char	*get_next_line(int fd);

#endif
