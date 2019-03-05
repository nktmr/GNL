/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfelissa <dfelissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:54:38 by dfelissa          #+#    #+#             */
/*   Updated: 2019/02/22 22:16:23 by dfelissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "get_next_line.h"
#define BUFF_SIZE 100000

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char		*str[_SC_OPEN_MAX];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	
	if (fd < 0 || line == NULL || BUFF_SIZE == 0 || fd > _SC_OPEN_MAX
			|| read(fd, "", 0))
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(1);
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
	}
	if (ft_strlen(str[fd]) == 0)
		return (0);
	*line = ft_strsub(str[fd], 0, ft_strnlen(str[fd], '\n'));
	tmp = ft_strsub(str[fd], ft_strnlen(str[fd],'\n') + 1 ,
			ft_strlen(&str[fd][ft_strnlen(str[fd], '\n')]));
	ft_strdel(&str[fd]);
	str[fd] = tmp;
	return (1);
}
