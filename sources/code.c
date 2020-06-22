/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:46:53 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/22 15:55:22 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void				check_arg_type(t_dasm *dasm)
{
	int				i;

	i = 0;
	while (i < dasm->com->am_arg)
	{
		if (dasm->com->t_arg[i] != 1 && dasm->com->t_arg[i] != 2
		&& dasm->com->t_arg[i] != 3)
		{
			ft_putstr("wrong arg type\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void				transfer_arg_type(t_dasm *dasm)
{
	int				arg_code;
	int				i;

	i = 0;
	dasm->com->args_typ = dasm->code[dasm->in];
	dasm->com->t_arg = (int *)malloc(sizeof(int) * dasm->com->am_arg);
	if (dasm->com->am_arg >= 1)
	{
		arg_code = (dasm->com->args_typ & 0xC0) >> 6;
		dasm->com->t_arg[i] = arg_code;
		i++;
	}
	if (dasm->com->am_arg >= 2)
	{
		arg_code = (dasm->com->args_typ & 0x30) >> 4;
		dasm->com->t_arg[i] = arg_code;
		i++;
	}
	if (dasm->com->am_arg >= 3)
	{
		arg_code = (dasm->com->args_typ & 0xC) >> 2;
		dasm->com->t_arg[i] = arg_code;
		i++;
	}
}

void				transfer_arg(t_dasm *dasm, int i)
{
	size_t			size;
	char			*tmp;

	if (dasm->com->type == false)
	{
		dasm->com->t_arg = (int *)malloc(sizeof(int) * dasm->com->am_arg);
		dasm->com->t_arg[i] = 2;
		check_arg_type(dasm);
	}
	if (dasm->com->t_arg[i] == 1)
		size = 1;
	if (dasm->com->t_arg[i] == 2)
		size = dasm->com->dir_size;
	if (dasm->com->t_arg[i] == 3)
		size = 2;
	dasm->com->arg[i] = bytecode_to_int(&dasm->code[dasm->in], size);
	dasm->in += size;
}

void				init_arg_type(t_dasm *dasm)
{
	int				i;

	i = 0;
	if (dasm->com->type == true)
	{
		dasm->in++;
		transfer_arg_type(dasm);
		check_arg_type(dasm);
	}
	dasm->in++;
	while (i < dasm->com->am_arg)
	{
		if (i == 0)
			dasm->com->arg = (int *)malloc(sizeof(int) * dasm->com->am_arg);
		transfer_arg(dasm, i);
		i++;
	}
}

void				transfer_operation(t_dasm *dasm)
{
	int				i;

	dasm->in = 0;
	while (dasm->in < dasm->code_size)
	{
		i = 0;
		if (dasm->com)
		{
			dasm->com->next = init_new_node();
			dasm->com = dasm->com->next;
		}
		else
			dasm->com = init_new_node();
		if (!dasm->head)
			dasm->head = dasm->com;
		if (!(init_command(dasm->code[dasm->in], &dasm->com)))
		{
			ft_putstr("wrong operation\n");
			exit(EXIT_FAILURE);
		}
		printf("name %s\n", dasm->com->name);
		init_arg_type(dasm);
	}
}
