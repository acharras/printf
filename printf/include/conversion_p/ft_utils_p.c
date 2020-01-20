/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_p.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 13:55:44 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:47:29 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_two_star_sup_p(t_printf *st, int final_len)
{
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x", st);
		else
			ft_putstr(st->str_convert, st);
	}
	ft_no_zero(st, final_len);
}

void	ft_print_no_point_p(t_printf *st)
{
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x", st);
		else
			ft_putstr(st->str_convert, st);
	}
}
