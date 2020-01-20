/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 12:10:13 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:40:15 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_two_star_neg_s(t_printf *st, int final_len)
{
	st->len_star_2 *= -1;
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0)
		ft_putstr(st->str_convert, st);
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

int		ft_two_star_neg_d_i(t_printf *st, int final_len)
{
	st->len_star_2 *= -1;
	final_len = st->len_star_2 - ft_int_len(st->int_converter);
	ft_neg_d_i(st);
	ft_zero_d_i(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
		st->malloc_zero = 0;
		ft_putstr(st->str_convert, st);
	}
	if (final_len >= 0 && (ft_strcmp(st->flag_zero, "zero") != 0 ||
			ft_check_dash(st) == 0))
		st->dash_field = 1;
	else
	{
		if (ft_strcmp(st->flag_pt_s, ".") == 0 &&
				ft_check_dash(st) != 0)
			st->check_pt = 1;
		else
			st->dash_field = 1;
	}
	return (final_len);
}

void	ft_two_star_neg_u(t_printf *st, int final_len)
{
	st->len_star_2 *= -1;
	final_len = st->len_star_2 - ft_u_int_len(st->uns_int_converter);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	if (final_len >= 0 && ft_strcmp(st->flag_zero, "zero") != 0)
		st->dash_field = 1;
	else
	{
		if (ft_strcmp(st->flag_pt_s, ".") == 0 && ft_check_dash(st) != 0)
			st->check_pt = 1;
		else
			st->dash_field = 1;
	}
}

void	ft_two_star_neg_x(char *fmt, t_printf *st, int final_len)
{
	st->len_star_2 *= -1;
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_x_no_dash(fmt, st);
	if (final_len >= 0 && ft_strcmp(st->flag_zero, "zero") != 0)
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

void	ft_two_star_neg_percent(t_printf *st, int final_len)
{
	st->len_star_2 *= -1;
	final_len = st->len_star_2 - 1;
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
	{
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	if (final_len >= 0 && (ft_strcmp(st->flag_zero, "zero") != 0 ||
			ft_check_dash(st) == 0))
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
