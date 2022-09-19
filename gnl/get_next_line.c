/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:38:18 by tmerida-          #+#    #+#             */
/*   Updated: 2022/03/08 18:35:58 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strdup(char *str)
{
	int i;
	char *dupl;
	int len;

	i = 0;
	len = ft_strlen(str);
	dupl = malloc(len + 1);
	if (!dupl)
	{
		return (NULL);
	}
	while (str[i])
	{
		dupl[i] = str[i];
		i++;
	}
	dupl[i] = 0;
	return (dupl);
}

char *get_next_line(int fd)
{
	char buffer;
	char rtn[7000000];
	int i;
	int num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	num = read(fd, &buffer, 1);
	while(num > 0)
	{
		rtn[i++] = buffer;
		if (buffer == '\n')
			break ;
		num = read(fd, &buffer, 1);
	}
	rtn[i] = 0;
	if (num <= 0 && i == 0)
		return (0);
	return (ft_strdup(rtn));
}


