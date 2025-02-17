/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:57:26 by anavagya          #+#    #+#             */
/*   Updated: 2025/02/17 16:29:35 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_str(char *s1, char *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
}

char	*read_file(int fd, char *buff)
{
	char	*temp;
	int		byte_read;

	byte_read = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (byte_read != 0 && !(ft_strchr(buff, '\n')))
	{
		byte_read = read(fd, temp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free_str(buff, temp);
			return (NULL);
		}
		temp[byte_read] = '\0';
		buff = ft_strjoin(buff, temp);
	}
	free_str(temp, NULL);
	return (buff);
}

char	*get_the_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff || *buff == '\0')
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		line = ft_substr(buff, 0, i + 1);
	else
		line = ft_substr(buff, 0, i);
	return (line);
}

char	*new_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	line = ft_substr(buff, i + 1, ft_strlen(buff) - i);
	free(buff);
	buff = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line;

	if (fd > OPEN_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	buff[fd] = read_file(fd, buff[fd]);
	line = get_the_line(buff[fd]);
	buff[fd] = new_line(buff[fd]);
	return (line);
}
