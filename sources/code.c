/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 17:46:53 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/18 20:15:14 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void				transfer_arg_type(t_dasm *dasm)
{
	int				arg_code;
	int				i = 0;

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
	int				size;
	char			*tmp;

	if (dasm->com->type == false)
	{
		dasm->com->t_arg = (int *)malloc(sizeof(int) * dasm->com->am_arg);
		dasm->com->t_arg[i] = 2;
	}
	if (dasm->com->t_arg[i] == 1)
		size = 1;
	if (dasm->com->t_arg[i] == 2)
		size = dasm->com->dir_size;
	if (dasm->com->t_arg[i] == 3)
		size = 2;
	tmp = ft_itoa(bytecode_to_int(&dasm->code[dasm->in], size));
	dasm->com->arg[i] = ft_atoi(tmp);
	dasm->in += size;
}

void				transfer_operation(t_dasm *dasm)
{
	int				i;

	dasm->in = 0;
	printf("index size %d %d\n", dasm->in, dasm->code_size);
	while (dasm->in < dasm->code_size)
	{
		i = 0;
		dasm->com = init_new_node();
		if (!(init_command(dasm->code[dasm->in], &dasm->com)))
		{
			ft_putstr("wrong operation\n");
			exit(EXIT_FAILURE);
		}
		printf("name %s\n", dasm->com->name);
		if (dasm->com->type == true)
		{
			dasm->in++;
			transfer_arg_type(dasm);
		}
		dasm->in++;
		while (i < dasm->com->am_arg)
		{
			if (i == 0)
				dasm->com->arg = (int *)malloc(sizeof(int) * dasm->com->am_arg);
			transfer_arg(dasm, i);
			i++;
		}
		dasm->com = dasm->com->next;
	}
}