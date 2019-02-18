#include "../Libft/libft.h"

#define BUF_SIZE 10

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*tmp;
	char			buf[BUF_SIZE + 1];
	
	tmp = ft_strnew(1);
	while (!ft_strchr(tmp, '\n') && (ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	*line = ft_strsub(tmp, 0, '\n'); 
	ft_putstr(*line);
	return (0);
}
