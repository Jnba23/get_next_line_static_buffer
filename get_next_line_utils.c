/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:54:41 by asayad            #+#    #+#             */
/*   Updated: 2024/01/12 03:14:31 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-2);
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s, int i)
{
	char	*r;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	r = malloc(i + 2);
	if (!r)
		return (NULL);
	while (j <= i)
	{
		r[j] = s[j];
		j++;
	}
	r[j] = '\0';
	return (r);
}

void	set_buff(char *buff, int i)
{
	int	j;
	int	k;
	int	l;

	if (!buff)
		return ;
	j = -1;
	k = 0;
	l = ft_strlen(buff) - i + 1;
	if (i >= 0)
	{
		while (k < l && buff[i + 1])
		{
			buff[k] = buff[i + 1];
			k++;
			i++;
		}
		buff[k] = '\0';
	}
	else if (i < 0)
	{
		while (buff[++j])
			buff[j] = '\0';
	}
}
