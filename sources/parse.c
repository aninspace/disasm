/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:32:46 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/22 13:29:40 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			parse_code(int fd, t_dasm *dasm)
{
	uint8_t		*buf;
	int			size;

	buf = ft_memalloc(dasm->code_size);
	size = read(fd, buf, dasm->code_size);
	if (size != dasm->code_size)
	{
		ft_putstr("code has a wrong size\n");
		exit(EXIT_FAILURE);
	}
	dasm->code = buf;
}

void			parse_all(int argc, char **argv, t_dasm *dasm)
{
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(ft_strstr(argv[1], ".cor")))
		{
			ft_putstr("file has a wrong expansion\n");
			exit(EXIT_FAILURE);
		}
		parse_magic(fd);
		parse_name(fd, dasm);
		parse_null(fd);
		parse_code_size(fd, dasm);
		parse_comment(fd, dasm);
		parse_null(fd);
		parse_code(fd, dasm);
	}
	else
	{
		ft_putstr("too many arguments\n");
		exit(EXIT_FAILURE);
	}
}
