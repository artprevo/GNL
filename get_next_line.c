/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:13:34 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/11 16:29:50 by artprevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	if (file)
	{
		while (tmp)
		{
			if ((int)tmp->content_size == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", fd);
	tmp->content_size = fd;
	ft_lstadd(file, tmp);
	return (tmp);
}

static char		*ft_strnjoin(char *s1, char *s2, int r)
{
	char	*join;
	int		diff;
	char	*tmp;

	tmp = s1;
	diff = ft_strlen(s2) - r;
	if (!s1 || !s2 || !(join = ft_strnew(ft_strlen(s1) + ft_strlen(s2) - diff)))
		return (NULL);
	ft_strcat(join, s1);
	ft_strncat(join, s2, r);
	free(tmp);
	return (join);
}

static char		*ft_free(char *content, int r, char *buf)
{
	char	*tmp;

	tmp = content;
	content = ft_strdup(content + r);
	free(tmp);
	free(buf);
	return (content);
}

static int		ft_fill(char **content, char *str)
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
	if (!(*content = ft_strnew(i + 1)))
		return (0);
	ft_strncat(*content, str, i);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*list;
	int				r;
	char			*buf;

	if ((!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1)))) \
			|| read(fd, buf, 0) < 0 || fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	list = ft_file(&file, fd);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		if (!(list->content = ft_strnjoin(list->content, buf, r)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r < BUFF_SIZE && !ft_strlen(list->content))
		return (0);
	r = ft_fill(line, list->content);
	if (r < (int)ft_strlen(list->content))
		list->content = ft_free(list->content, r + 1, buf);
	else
		ft_strclr(list->content);
	return (1);
}
