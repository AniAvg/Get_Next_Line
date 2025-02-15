/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:49:54 by anavagya          #+#    #+#             */
/*   Updated: 2025/02/15 15:20:46 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (temp[0] == '\0')
		{
			if(buff)
				free(buff);
			free(temp);
			return (NULL);
		}
		if (byte_read == -1)
		{
			free(buff);
			free(temp);
			buff = NULL;
			temp = NULL;
			return (NULL);
		}
		temp[byte_read] = '\0';
		buff = ft_strjoin(buff, temp);
		free(temp);
		temp = NULL;
	}
	free(temp);
	temp = NULL;
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
	{
	//	write(1, &buff[i], 1);
		i++;
	}
	if (buff[i] == '\n')
	{
	//	write(1, "g", 1);
		line = ft_substr(buff, 0, i + 1);
	}
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
	static char	*buff = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = read_file(fd, buff);i
	line = get_the_line(buff);
	buff = new_line(buff);
	return (line);
}
/*
#include <fcntl.h>

int main()
{
	int fd = open("gnl.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
//	get_next_line(fd);
	return (0);
}*/
