/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_percent.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 13:42:28 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:46:29 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_no_zero_percent_or_d_i(t_printf *st, int final_len)
{
	if (final_len >= 0 && (ft_strcmp(st->flag_zero, "zero") != 0 ||
			ft_check_dash(st) == 0))
	{
		st->space = ft_fill_space(final_len);
		if (ft_check_dash(st) != 0 && ft_strcmp(st->flag_pt_s, ".") != 0)
			ft_putstr(st->space, st);
		else if (ft_strcmp(st->flag_pt_s, ".") != 0)
			ft_putstr(st->space, st);
		else if (ft_strcmp(st->flag_pt_s, ".") == 0 &&
				ft_check_dash(st) != 0)
			st->check_pt = 1;
		else
			st->dash_field = 1;
		ft_memdel((void *)&st->space);
	}
	else
	{
		if (ft_strcmp(st->flag_pt_s, ".") == 0 &&
				ft_check_dash(st) != 0)
			st->check_pt = 1;
		else
			st->dash_field = 1;
	}
}

void	ft_two_star_sup_percent(t_printf *st, int final_len)
{
	final_len = st->len_star_2 - 1;
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	ft_no_zero_percent_or_d_i(st, final_len);
}

void	ft_print_no_point_percent(t_printf *st)
{
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}
