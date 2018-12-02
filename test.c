/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:29:11 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/02 19:26:46 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main()
{
	int fd;
	char buf[128];
	int size;
	int	i;
	char *str;
	int j;
	char **tab;
	t_data *data;
	
	if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
		return (-1);
	j = 0;
	size = 0;
	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	size = read(fd, buf, 127);
	data->nb = fd;
	while (buf[i] != '\n')
		i++;
	str = ft_strnew((size_t)i);
	while (j < i)
	{
		str[j] = buf[j];
		j++;
	}
	data->save_buf = str;
	data->is_read = 1;
	buf[size] = 0;
	write (1, data->save_buf, i);
	printf("\n%d", data->nb);
	close(fd);
	return (0);
}
