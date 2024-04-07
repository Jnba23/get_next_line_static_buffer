/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:39 by asayad            #+#    #+#             */
/*   Updated: 2024/01/13 11:43:10 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*line;
	int		l;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		line = ft_strdup(s2, ft_strlen(s2) - 1);
		return (free(s2), line);
	}
	if (!s2)
		return (s1);
	l = ft_strlen(s1) + ft_strlen(s2);
	line = malloc ((l + 1) * sizeof(char));
	if (!line)
		return (free(s1), free(s2), NULL);
	line = ft_strlcpy(s1, s2, line, l);
	return (free(s1), free(s2), line);
}

char	*ft_strlcpy(char *s1, char *s2, char *line, int l)
{
	int		i;
	int		j;

	i = -1;
	j = ft_strlen(s2);
	while (++i < l - j)
		line[i] = s1[i];
	while (--j >= 0)
		line[i + j] = s2[j];
	line[l] = '\0';
	return (line);
}

char	*check_nl(char *buff)
{
	char	*line;
	int		i;
	int		l;

	if (!buff || !buff[0])
		return (NULL);
	l = ft_strlen(buff);
	i = ft_strchr(buff, 10);
	if (i == -2)
		return (NULL);
	if (i >= 0)
	{
		line = ft_strdup(buff, i);
		set_buff(buff, i);
		return (line);
	}
	else
	{
		line = ft_strdup(buff, l - 1);
		set_buff(buff, i);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][(size_t)BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (ft_strchr(buff[fd], 10) >= 0)
		return (check_nl(buff[fd]));
	line = check_nl(buff[fd]);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff[fd], BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buff[fd][bytes_read] = '\0';
		if (bytes_read > 0)
			line = ft_strjoin(line, check_nl(buff[fd]));
		if (bytes_read == 0 || ft_strchr(line, 10) >= 0)
			break ;
	}
	return (line);
}
