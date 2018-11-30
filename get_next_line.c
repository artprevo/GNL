/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:13:34 by artprevo          #+#    #+#             */
/*   Updated: 2018/11/30 19:41:04 by artprevo         ###   ########.fr       */
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

static	int		ft_read(int fd, char *buf, char **line, t_list *list)
{
	int		r;
	char	*tmp;

	list->content = ft_strdup("");
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		buf[r] = '\0';
		if (!(tmp = ft_strjoin(list->content, buf)))
			return (-1);
		free(list->content);
		list->content = tmp;
		if (ft_strchr(buf, '\n'))
				break ;
	}
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
	char			*buf;

	if (!line)
		return (-1);
	list = ft_file(&file, fd);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	buf[0] = 0;
	*line = ft_strnew(1);
	r = ft_read(fd, buf, line, list);
	i = ft_strccpy(line, list->content);
	if (i < (int)ft_strlen(list->content))
		list->content += (i + 1);
	else
		ft_strclr(list->content);
	return (r);
}
