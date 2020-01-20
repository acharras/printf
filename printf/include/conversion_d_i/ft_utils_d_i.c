/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_d_i.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 13:44:49 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:57:23 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_d_i_no_point(t_printf *st, int final_len)
{
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
		if (st->int_neg == 1 || st->int_neg == 2)
			ft_putchar('-', st);
		if (st->int_neg == 2)
			st->str_convert = ft_int_min(st->str_convert);
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	ft_no_zero_percent_or_d_i(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
		if (st->int_neg == 1 || st->int_neg == 2)
			ft_putchar('-', st);
		if (st->int_neg == 2)
			st->str_convert = ft_int_min(st->str_convert);
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}

void	ft_neg_d_i(t_printf *st)
{
	if (st->int_converter < 0 && ft_strcmp(st->flag_pt_s, ".") != 0 &&
			st->int_converter > -2147483648)
	{
		st->int_neg = 1;
		st->int_converter *= -1;
	}
	if (st->int_converter == -2147483648 && ft_strcmp(st->flag_pt_s, ".") != 0)
	{
		st->int_converter = 2147483647;
		st->int_neg = 2;
	}
}

void	ft_point_neg_d_i(t_printf *st)
{
	if (st->int_converter < 0 && st->int_converter > -2147483648)
	{
		st->int_converter *= -1;
		st->dash_d = 1;
	}
}

int		ft_two_star_sup_d_i(t_printf *st, int final_len)
{
	final_len = st->len_star_2 - ft_int_len(st->int_converter);
	ft_neg_d_i(st);
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
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
		st->malloc_zero = 0;
		if (st->int_neg == 1 || st->int_neg == 2)
			ft_putchar('-', st);
		if (st->int_neg == 2)
			st->str_convert = ft_int_min(st->str_convert);
		ft_putstr(st->str_convert, st);
	}
	ft_no_zero_percent_or_d_i(st, final_len);
	return (final_len);
}

void	ft_print_dash_star_neg_d_i(t_printf *st, int final_len)
{
	st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
	if (final_len >= 0 && ft_strcmp(st->flag_zero, "zero") != 0)
		st->space = ft_fill_space(final_len);
	else
	{
		final_len = (final_len * -1) -
				(ft_int_len(st->int_converter) * 2);
		if (final_len > 0)
			st->space = ft_fill_space(final_len);
	}
	st->malloc_zero = 0;
	ft_putstr(st->str_convert, st);
	if (ft_strcmp(st->flag_zero, "zero") != 0)
		ft_putstr(st->space, st);
}
