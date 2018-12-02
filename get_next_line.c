/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:13:34 by artprevo          #+#    #+#             */
/*   Updated: 2018/12/02 22:40:17 by artprevo         ###   ########.fr       */
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

static char		*ft_strdup_free(char *content, int r)
{
	char	*tmp;

	tmp = content;
	content = ft_strdup(content + r);
	free(tmp);
	return (content);
}

static	char	*ft_strndup(char *s, int n)
{
	char	*r;
	int		i;

	i = 0;
	if (!(r = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	if (r == NULL)
		return (NULL);
	while (i < n)
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*list;
	int				r;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	list = ft_file(&file, fd);
	while (!ft_strchr(list->content, '\n') && (r = read(fd, buf, BUFF_SIZE)))
		list->content = ft_strnjoin(list->content, buf, r);
	r = 0;
	while (((char *)list->content)[r] && ((char *)list->content)[r] != '\n')
		r++;
	*line = ft_strndup(list->content, r);
	if (((char *)list->content)[r] == '\n')
		r++;
	list->content = ft_strdup_free(list->content, r);
	if (!r)
		return (0);
	return (1);
}
