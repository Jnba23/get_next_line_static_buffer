/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:52:51 by asayad            #+#    #+#             */
/*   Updated: 2024/01/13 02:01:51 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	set_buff(char *buff, int i);
char	*check_nl(char *buff);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s, int i);
int		ft_strchr(char *s, char c);
int		ft_strlen(char *s);
char	*ft_strlcpy(char *s1, char *s2, char *line, int l);

#endif