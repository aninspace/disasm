/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:58:51 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/22 13:01:36 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			free_all(t_dasm *dasm)
{
	while (dasm->com)
	{
		free(dasm->com->arg);
		free(dasm->com->name);
		free(dasm->com->t_arg);
		free(dasm->com);
		dasm->com = dasm->com->next;
	}
	free(dasm->com);
	dasm->com = NULL;
	free(dasm->code);
	free(dasm->comment);
	free(dasm->file_name);
	free(dasm->head);
	free(dasm->name);
	free(dasm);
}