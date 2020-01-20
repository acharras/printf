/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_x_second.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 13:26:40 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:15:35 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_replace_x_or_maj_x(char *fmt, t_printf *st)
{
	if (fmt[st->i] == 'x')
		st->str_convert = ft_strjoin_2_free(st->zero,
			ft_itoa_base(st->int_converter, "0123456789abcdef"));
	else if (fmt[st->i] == 'X')
		st->str_convert = ft_strjoin_2_free(st->zero,
			ft_itoa_base(st->int_converter, "0123456789ABCDEF"));
	st->malloc_zero = 0;
}
