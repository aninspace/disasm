/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:32:46 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/17 12:05:42 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			parse_magic(int fd)
{
	uint8_t		buf[4];
	int			size;
	int			res;

	size = read(fd, &buf, 4);
	if (size == -1 && size < 4)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	res = bytecode_to_int(buf, 4);
	printf("%d\n", res);
	if (res != COREWAR_EXEC_MAGIC)
	{
		ft_putstr("Wrong magic number\n");
		exit(EXIT_FAILURE);
	}
}

void			parse_name(int fd, t_dasm *dasm)
{
	char		buf[PROG_NAME_LENGTH];
	int			size;

	size = read(fd, &buf, PROG_NAME_LENGTH);
	if (size == -1)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	dasm->name = ft_strdup(buf);
	printf("%s\n", dasm->name);
}

void			parse_null(int fd)
{
	uint8_t		buf[4];
	int			size;
	int			res;

	size = read(fd, &buf, 4);
	if (size == -1 && size < 4)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	res = bytecode_to_int(buf, 4);
	if (res != 0)
	{
		ft_putrstr("no null\n");
		exit(EXIT_FAILURE);
	}
	printf("null %d\n", res);
}

void			parse_code_size(int fd, t_dasm *dasm)
{
	uint8_t		buf[4];
	int			size;
	int			res;

	size = read(fd, &buf, 4);
	if (size == -1 && size < 4)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	res = bytecode_to_int(buf, 4);
	printf("%d\n", res);
	if (res > CHAMP_MAX_SIZE)
	{
		ft_putstr("Wrong champion code size\n");
		exit(EXIT_FAILURE);
	}
	dasm->size = res;
}

void			parse_comment(int fd, t_dasm *dasm)
{
	char		buf[COMMENT_LENGTH];
	int			size;

	size = read(fd, &buf, COMMENT_LENGTH);
	if (size == -1)
	{
		ft_putstr("Couldn't read the file\n");
		exit(EXIT_FAILURE);
	}
	dasm->comment = ft_strdup(buf);
	printf("%s\n", dasm->comment);
}

void			parse_code(int fd, t_dasm *dasm)
{
	uint8_t		buf[dasm->size];
	int			size;

	size = read(fd, &buf, dasm->size);
	if (size != dasm->size)
	{
		ft_putstr("code has a wrong size\n");
		exit(EXIT_FAILURE);
	}
	dasm->code = buf;
	printf("code %d\n", dasm->code[324]);
}

void			parse_all(int argc, char **argv, t_dasm *dasm)
{
	int fd;
	
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
}