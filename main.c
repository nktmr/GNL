#include "../Libft/libft.h"
#include "get_next_line.h"

int main(int ac, char **av)
{
	int	fd;
	char		**line;

	if(!(line = (char**)malloc(sizeof(char*) * 2)))
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, line);
	return(0);
}
