/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:30:35 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/28 19:54:21 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int 	i = 0;
	int		err = 1;
	char	*line;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr("open fail.\n");
			return (0);
		}
		while ((err = get_next_line(fd, &line)) == 1)
		{
			if (err == -1)
			{
				ft_putstr("get next line fail.\n");
				return (0);
			}
			i++;
			ft_putnbr(err);
			ft_putstr(" : err\n");
			ft_putstr(line);
			ft_putstr(" : line\n Passage numero ");
			ft_putnbr(i);
			ft_putstr("\n\n");
			free(line);
		}
		close(fd);
	}
	return (0);
}
