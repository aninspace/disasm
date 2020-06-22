/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:19:25 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/22 16:02:03 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			take_name(char *argv, t_dasm *dasm)
{
	char		*name;
	char		**tmp;
	int			i;

	if (ft_strlen(argv) < 1)
	{
		ft_putstr("no file name\n");
		exit(EXIT_FAILURE);
	}
	tmp = ft_strsplit(argv, '.');
	if (ft_strlen(tmp[0]) > 0)
		name = ft_strjoin(tmp[0], ".s");
	else
		name = ft_strdup(".s");
	ft_free_arr(tmp);
	tmp = ft_strsplit(name, '/');
	i = 0;
	while (tmp[i])
		i++;
	free(name);
	name = ft_strdup(tmp[i - 1]);
	dasm->file_name = ft_strdup(name);
	ft_free_arr(tmp);
	free(name);
}

char			choose_arg_code(t_com *com, int i)
{
	if (com->t_arg[i] == 1)
		return ('r');
	if (com->t_arg[i] == 2)
		return ('%');
	if (com->t_arg[i] == 3)
		return (' ');
	return ('\0');
}

void			fill_operations(t_dasm *dasm, int fd)
{
	int			i;

	while (dasm->com)
	{
		ft_putstr_fd(dasm->com->name, fd);
		ft_putchar_fd(' ', fd);
		i = 0;
		while (i < dasm->com->am_arg)
		{
			ft_putchar_fd(choose_arg_code(dasm->com, i), fd);
			ft_putnbr_fd(dasm->com->arg[i], fd);
			if (i + 1 != dasm->com->am_arg)
				ft_putstr_fd(", ", fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
		dasm->com = dasm->com->next;
	}
}

void			put_operation_in_file(t_dasm *dasm)
{
	int			fd;
	int			i;

	dasm->com = dasm->head;
	fd = open(dasm->file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 3)
	{
		ft_putstr("file wasn't created\n");
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(".name	", fd);
	ft_putendl_fd(dasm->name, fd);
	ft_putstr_fd(".comment	", fd);
	ft_putendl_fd(dasm->comment, fd);
	fill_operations(dasm, fd);
}

int32_t			bytecode_to_int(uint8_t *bytecode, size_t size)
{
	int32_t		result;
	bool		sign;
	int			i;

	result = 0;
	sign = (bool)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
		{
			result += ((bytecode[size - 1] ^ 0xFF) << (i * 8));
			i++;
		}
		else
		{
			result += bytecode[size - 1] << (i * 8);
			i++;
		}
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}
