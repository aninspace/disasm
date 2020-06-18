/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:20:49 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/18 13:49:25 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_dasm			*init_dasm()
{
	t_dasm		*dasm;

	if (!(dasm = (t_dasm *)malloc(sizeof(t_dasm))))
	dasm->com = NULL;
	dasm->code = NULL;
	dasm->comment = NULL;
	dasm->name = NULL;
	dasm->code_size = 0;
	dasm->in = 0;
	return (dasm);
}

t_com			*init_new_node()
{
	t_com		*node;

	if (!(node = (t_com *)malloc(sizeof(t_com))))
		exit(EXIT_FAILURE);
	node->arg = NULL;
	node->name = NULL;
	node->next = NULL;
	node->t_arg = NULL;
	return (node);
}

char			**init_arg(int len)
{
	char		**arg;

	if (!(arg = (char **)malloc(sizeof(char *) * len + 1)))
		exit(EXIT_FAILURE);
	return (arg);
}

bool			init_command(uint8_t op, t_com **com)
{
	if (op >= 0x01 && op <= 0x10)
	{
		if (op == 0x01)
		{
			(*com)->name = ft_strdup("live");
			(*com)->type = false;
			(*com)->am_arg = 1;
			(*com)->dir_size = 4;
		}
		if (op == 0x02)
		{
			// printf("hello\n");
			(*com)->name = ft_strdup("ld");
			(*com)->type = true;
			(*com)->am_arg = 2;
			(*com)->dir_size = 4;
		}
		if (op == 0x03)
		{
			(*com)->name = ft_strdup("st");
			(*com)->type = true;
			(*com)->am_arg = 2;
			(*com)->dir_size = 4;
		}
		if (op == 0x04)
		{
			(*com)->name = ft_strdup("add");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 4;
		}
		if (op == 0x05)
		{
			(*com)->name = ft_strdup("sub");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 4;
		}
		if (op == 0x06)
		{
			(*com)->name = ft_strdup("and");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 4;
		}
		if (op == 0x07)
		{
			(*com)->name = ft_strdup("or");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 4;
		}
		if (op == 0x08)
		{
			(*com)->name = ft_strdup("xor");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 4;
		}
		if (op == 0x09)
		{
			(*com)->name = ft_strdup("zjmp");
			(*com)->type = false;
			(*com)->am_arg = 1;
			(*com)->dir_size = 2;
		}
		if (op == 0x0a)
		{
			(*com)->name = ft_strdup("ldi");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 2;
		}
		if (op == 0x0b)
		{
			(*com)->name = ft_strdup("sti");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 2;
		}
		if (op == 0x0c)
		{
			(*com)->name = ft_strdup("fork");
			(*com)->type = false;
			(*com)->am_arg = 1;
			(*com)->dir_size = 2;
		}
		if (op == 0x0d)
		{
			(*com)->name = ft_strdup("lld");
			(*com)->type = true;
			(*com)->am_arg = 2;
			(*com)->dir_size = 4;
		}
		if (op == 0x0e)
		{
			(*com)->name = ft_strdup("lldi");
			(*com)->type = true;
			(*com)->am_arg = 3;
			(*com)->dir_size = 2;
		}
		if (op == 0x0f)
		{
			(*com)->name = ft_strdup("lfork");
			(*com)->type = false;
			(*com)->am_arg = 1;
			(*com)->dir_size = 2;
		}
		if (op == 0x10)
		{
			(*com)->name = ft_strdup("aff");
			(*com)->type = true;
			(*com)->am_arg = 1;
			(*com)->dir_size = 4;
		}
		return (true);
	}
	return (false);
}