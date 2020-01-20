/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_star_flag_x.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 13:03:10 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:15:58 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_dash_star_flag_x(char *fmt, va_list ap, t_printf *st)
{
	int			final_len;

	st->len_star = va_arg(ap, int);
	st->int_converter = va_arg(ap, int);
	ft_know_x_or_maj_x(fmt, st);
	final_len = st->len_star - ft_strlen(st->str_convert);
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_memdel((void *)&st->str_convert);
	ft_replace_x_or_maj_x(fmt, st);
	if (final_len >= 0 && ft_strcmp(st->flag_zero, "zero") != 0)
		st->space = ft_fill_space(final_len);
	else
		st->space = ft_strdup("");
	ft_putstr(st->str_convert, st);
	if (ft_strcmp(st->flag_zero, "zero") != 0)
		ft_putstr(st->space, st);
}

static void	ft_len_star_2_sup(char *fmt, t_printf *st, int final_len)
{
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0)
	{
		ft_memdel((void *)&st->str_convert);
		ft_replace_x_or_maj_x(fmt, st);
		if (final_len >= 0)
			st->space = ft_fill_space(final_len);
		else
			st->space = ft_strdup("");
		if (ft_strcmp(st->flag_zero, "zero") != 0)
			ft_putstr(st->space, st);
		ft_putstr(st->str_convert, st);
	}
}

static void	ft_len_star_2(char *fmt, t_printf *st, int final_len)
{
	if (st->len_star_2 >= 0)
		ft_len_star_2_sup(fmt, st, final_len);
	else
	{
		st->len_star_2 *= -1;
		final_len = st->len_star_2 - ft_strlen(st->str_convert);
		if (ft_strcmp(st->flag_zero, "zero") == 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(final_len);
			st->malloc_zero = 1;
		}
		if (ft_strcmp(st->flag_pt_s, ".") != 0)
		{
			ft_memdel((void *)&st->str_convert);
			ft_replace_x_or_maj_x(fmt, st);
			ft_putstr(st->str_convert, st);
			if (ft_strcmp(st->flag_zero, "zero") != 0)
				ft_print_space(st, final_len);
		}
	}
}

void		ft_star_flag_x(char *fmt, va_list ap, t_printf *st)
{
	int			final_len;

	if (st->verif == 0 && st->star_pt_star != 2)
		st->len_star_2 = va_arg(ap, int);
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	ft_know_x_or_maj_x(fmt, st);
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	ft_len_star_2(fmt, st, final_len);
}
