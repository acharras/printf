/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_x.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 15:00:19 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:06:54 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_star_left(char *fmt, t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	ft_know_x_or_maj_x(fmt, st);
	if (st->len_star_2 < 0)
		st->dash_star = 1;
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_no_point_x(fmt, st, final_len);
}

static void	ft_star_right(char *fmt, t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	st->verif = 2;
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	ft_know_x_or_maj_x(fmt, st);
	final_len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_no_point_x(fmt, st, final_len);
}

static void	ft_two_star(char *fmt, t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->len_star_3 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null = 1;
	ft_know_x_or_maj_x(fmt, st);
	if (st->len_star_2 >= 0)
		ft_two_star_sup_x(fmt, st, final_len);
	else
		ft_two_star_neg_x(fmt, st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		if (fmt[st->i] == 'x')
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa_base(st->int_converter, "0123456789abcdef"));
		else if (fmt[st->i] == 'X')
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa_base(st->int_converter, "0123456789ABCDEF"));
		st->malloc_zero = 0;
		ft_putstr(st->str_convert, st);
	}
}

static void	ft_no_star(char *fmt, t_printf *st, va_list ap, int final_len)
{
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null++;
	ft_know_x_or_maj_x(fmt, st);
	final_len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_no_point_x(fmt, st, final_len);
}

void		ft_field_size_x(char *fmt, t_printf *st, va_list ap)
{
	int			final_len;

	final_len = 0;
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	if (st->star_pt_star == 1)
		ft_star_left(fmt, st, ap, final_len);
	else if (st->star_pt_star == 2)
		ft_two_star(fmt, st, ap, final_len);
	else if (st->star_pt_star == 3)
		ft_star_right(fmt, st, ap, final_len);
	else
		ft_no_star(fmt, st, ap, final_len);
}
