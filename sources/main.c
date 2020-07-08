/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:09:31 by anastasiase       #+#    #+#             */
/*   Updated: 2020/07/08 19:58:17 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int			main(int argc, char **argv)
{
	t_dasm	*dasm;

	dasm = init_dasm();
	parse_all(argc, argv, dasm);
	transfer_operation(dasm);
	take_name(argv[argc - 1], dasm);
	put_operation_in_file(dasm);
}
