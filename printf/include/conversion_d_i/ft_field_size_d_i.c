/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_d_i.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:44:53 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:46:44 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_star_left(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	if (st->len_star_2 < 0)
		st->dash_star = 1;
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
	ft_print_d_i_no_point(st, final_len);
	return (final_len);
}

static int	ft_star_right(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	st->verif = 2;
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	final_len = ft_atoi(st->flag) - ft_int_len(st->int_converter);
	ft_neg_d_i(st);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_d_i_no_point(st, final_len);
	return (final_len);
}

static int	ft_two_star(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->len_star_3 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	if (st->len_star_2 >= 0)
		ft_two_star_sup_d_i(st, final_len);
	else
		ft_two_star_neg_d_i(st, final_len);
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
	return (final_len);
}

static int	ft_no_star(t_printf *st, va_list ap, int final_len)
{
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null++;
	final_len = ft_atoi(st->flag) - ft_int_len(st->int_converter);
	ft_neg_d_i(st);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_d_i_no_point(st, final_len);
	return (final_len);
}

void		ft_field_size_d_i(t_printf *st, va_list ap)
{
	int			final_len;

	final_len = 0;
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	if (st->star_pt_star == 1)
		final_len = ft_star_left(st, ap, final_len);
	else if (st->star_pt_star == 2)
		final_len = ft_two_star(st, ap, final_len);
	else if (st->star_pt_star == 3)
		final_len = ft_star_right(st, ap, final_len);
	else
		final_len = ft_no_star(st, ap, final_len);
	if (st->dash_field == 1 && ft_strcmp(st->flag_pt_s, ".") != 0 &&
			final_len < 0)
	{
		final_len = (final_len * -1) -
				(ft_int_len(st->int_converter) * 2);
		if (final_len > 0)
		{
			st->space = ft_fill_space(final_len);
			ft_putstr(st->space, st);
			ft_memdel((void *)&st->space);
		}
	}
}
