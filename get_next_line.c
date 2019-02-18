#include "../Libft/libft.h"
#include "get_next_line.h"
#define BUF_SIZE 20

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char		*tmp;
	char			buf[BUF_SIZE + 1];
	char			*str;

	if (!tmp)
		tmp = ft_strnew(1);
	while (!ft_strchr(tmp, '\n') && (ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	*line = ft_strsub(tmp, 0, ft_strnlen(tmp, '\n'));
	tmp = ft_strsub(tmp, ft_strnlen(tmp,'\n') + 1 , ft_strlen(&tmp[ft_strnlen(tmp, '\n')]));
	str = ft_strjoin(*line, tmp);
	ft_putstr(str);
	return (0);
}
