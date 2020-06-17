/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:41:45 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/17 15:51:57 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
#define DISASM_H

# include "op.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>
# include "./libft.h"
# include "dop.h"
# define ARG_TYPE	(int[]){0, 1, 1, 1, 1, 1, 1 ,1, 0, 1, 1, 0, 1, 1, 0, 1};
# define AM_ARG		(int[]){1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};
# define SIZE_DIR	(int[]){4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};

typedef struct			s_com
{
	t_op				*op;
	char				*name;
	char				**arg;
	struct s_com		*next;
}						t_com;


typedef struct			s_dasm
{
	t_com				*com;
	char				*name;
	char				*comment;
	int					size;
	uint8_t				*code;
	int					in;
}						t_dasm;

int						bytecode_to_int(unsigned char *s, int size);
void					parse_all(int argc, char **argv, t_dasm *dasm);
t_dasm					*init_dasm();

#endif
