/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:20:49 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/17 15:51:00 by anastasiase      ###   ########.fr       */
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
	dasm->size = 0;
	dasm->in = 0;
	return (dasm);
}