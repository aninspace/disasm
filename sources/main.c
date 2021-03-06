/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:29:11 by fmelda            #+#    #+#             */
/*   Updated: 2020/07/10 15:26:16 by anastasiase      ###   ########.fr       */
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
	free_all(dasm);
}
