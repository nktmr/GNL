/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfelissa <dfelissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:55:34 by dfelissa          #+#    #+#             */
/*   Updated: 2019/02/22 18:56:28 by dfelissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "get_next_line.h"

int main(int ac, char **av)
{
	int	fd;
	char	*line;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		ft_putendl(line);
	return(0);
}
