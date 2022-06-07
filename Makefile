# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 23:03:15 by psuanpro          #+#    #+#              #
#    Updated: 2022/06/08 00:59:40 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC	= *.c 

CC	= gcc -Wall -Wextra -Werror
RM	= rm -rf


swp:
	$(RM) *.swp *.gch *.c.swp .*.swp
norm:
	norminette .

gcc:
	$(CC) $(SRC)
	./a.out

push:
	./git.sh

pull:
	git pull

.PHONY: gcc push pull swp norm
