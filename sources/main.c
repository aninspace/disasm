/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:09:31 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/22 15:37:46 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int			main(int argc, char **argv)
{
	t_dasm	*dasm;

	dasm = init_dasm();
	printf("index %d\n", dasm->in);
	parse_all(argc, argv, dasm);
	transfer_operation(dasm);
	take_name(argv[argc - 1], dasm);
	put_operation_in_file(dasm);
	// free_all(dasm);
	// sleep(10000);
}
