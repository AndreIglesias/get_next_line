/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:26:40 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/01 00:50:36 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		func(char *line, char *pitcher)
{
	if (line && ft_strlen(line) <= 0)
	{
		free(pitcher);
		return (0);
	}
	return (1);
}

void	reading(char **line, int fd)
{
	static char *pitcher;

	*line = NULL;
	pitcher = NULL;
	while (get_next_line2(fd, line, &pitcher) == 1 && func(*line, pitcher))
	{
		ft_putendl(*line);
		free(*line);
		*line = NULL;
	}
	if (*line)
		free(*line);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	reading(&line, fd);
	if (argc == 2)
		close(fd);
}
