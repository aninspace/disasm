/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:19:25 by anastasiase       #+#    #+#             */
/*   Updated: 2020/06/17 13:09:03 by anastasiase      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int			bytecode_to_int(unsigned char *s, int size)
{
	int			i;
	unsigned	tmp;
	int			res;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		tmp = tmp << 8;
		// printf("tmp %d\n", tmp);
		// printf("s[i] %d\n", s[i]);
		tmp |= s[i];
		// printf("tmp1 %d\n", tmp);
		i++;
	}
	if (size == 1)
		res = (char)tmp;
	else if (size == 2)
		res = (short)tmp;
	else
		res = (int)tmp;
	// printf("res%d\n", res);
	return (res);
}