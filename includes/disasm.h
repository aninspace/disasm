/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:41:45 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/18 20:02:21 by anastasiase      ###   ########.fr       */
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

typedef struct			s_com
{
	char				*name;
	int					*arg;
	uint8_t				args_typ;
	int					*t_arg;
	bool				type;
	int					am_arg;
	int					dir_size;
	struct s_com		*next;
}						t_com;


typedef struct			s_dasm
{
	t_com				*com;
	char				*name;
	char				*comment;
	int					code_size;
	uint8_t				*code;
	char				*file_name;
	int					in;
	t_com				*head;
}						t_dasm;

int						bytecode_to_int(unsigned char *s, int size);
void					parse_all(int argc, char **argv, t_dasm *dasm);
t_dasm					*init_dasm();
t_com					*init_new_node();
void					transfer_operation(t_dasm *dasm);
bool					init_command(uint8_t op, t_com **com);
char					**init_arg(int len);
void					take_name(char *argv, t_dasm *dasm);
void					put_operation_in_file(t_dasm *dasm);

#endif
