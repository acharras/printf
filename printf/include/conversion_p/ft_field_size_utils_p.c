/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_utils_p.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 13:59:15 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:14:04 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_two_star_neg_p(t_printf *st, int final_len)
{
	st->len_star_2 *= -1;
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x", st);
		else
			ft_putstr(st->str_convert, st);
	}
	if (final_len >= 0)
		st->dash_field = 1;
	else
	{
		if (ft_strcmp(st->flag_pt_s, ".") == 0 &&
				ft_check_dash(st) != 0)
			st->check_pt = 1;
		else
			st->dash_field = 1;
	}
}
