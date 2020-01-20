/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_star_flag_d_i.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 17:33:27 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:13:48 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_dash_star_flag_d_i(va_list ap, t_printf *st)
{
	int			final_len;

	st->len_star = va_arg(ap, int);
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	final_len = st->len_star - ft_int_len(st->int_converter);
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_dash_star_neg_d_i(st, final_len);
}

static void	ft_len_star_2_sup(t_printf *st, int final_len)
{
	final_len = st->len_star_2 - ft_int_len(st->int_converter);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
		ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
			ft_itoa(st->int_converter));
		st->malloc_zero = 0;
		if (final_len >= 0)
			st->space = ft_fill_space(final_len);
		else
			st->space = ft_strdup("");
		if (ft_strcmp(st->flag_zero, "zero") != 0)
			ft_putstr(st->space, st);
		ft_putstr(st->str_convert, st);
	}
}

static void	ft_len_star_2(t_printf *st, int final_len)
{
	if (st->len_star_2 >= 0)
		ft_len_star_2_sup(st, final_len);
	else
	{
		st->len_star_2 *= -1;
		final_len = st->len_star_2 - ft_int_len(st->int_converter);
		if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(final_len);
			st->malloc_zero = 1;
		}
		if (ft_strcmp(st->flag_pt_s, ".") != 0)
		{
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
			st->malloc_zero = 0;
			ft_putstr(st->str_convert, st);
			if (ft_strcmp(st->flag_zero, "zero") != 0)
				ft_print_space(st, final_len);
		}
	}
}

void		ft_star_flag_d_i(va_list ap, t_printf *st)
{
	int			final_len;

	if (st->verif == 0 && st->star_pt_star != 2)
		st->len_star_2 = va_arg(ap, int);
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	final_len = st->len_star_2 - ft_int_len(st->int_converter);
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	ft_len_star_2(st, final_len);
}
