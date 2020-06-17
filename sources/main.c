/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:09:31 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/17 12:05:46 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int			main(int argc, char **argv)
{
	t_dasm	*dasm;

	dasm = init_dasm();
	parse_all(argc, argv, dasm);
}