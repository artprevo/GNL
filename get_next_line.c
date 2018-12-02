/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:13:34 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/02 21:37:51 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	return (tmp);
}

static	int		ft_strccpy(char **line, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (!(*line = ft_strnew(i)))
		return (0);
	ft_strncat(*line, str, i);
	return (i);
}

static	int		ft_read(int fd, t_list *list)
{
	int		r;
	char	buf[BUFF_SIZE];

	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (!(list->content = ft_strjoin(list->content, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r < 0)
		return (-1);
	if (r < BUFF_SIZE && !ft_strlen(list->content))
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*list;
	int				r;
	int				i;

	if (fd < 0 || line == NULL)
		return (-1);
	list = ft_file(&file, fd);
	r = ft_read(fd, list);
	if (r == -1 || r == 0)
		return (r);
	i = ft_strccpy(line, list->content);
	if (i < (int)ft_strlen(list->content))
		list->content += (i + 1);
	else
		ft_strclr(list->content);
	return (r);
}
