/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_u.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:38:02 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:06:25 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_star_left(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->uns_int_converter == 0 && st->null == 0)
		st->long_converter = va_arg(ap, int);
	if (st->long_converter < 0)
		st->uns_int_converter = 4294967296 + st->long_converter;
	else
		st->uns_int_converter = st->long_converter;
	if (st->uns_int_converter == 0)
		st->null = 1;
	if (st->len_star_2 < 0)
		st->dash_star = 1;
	final_len = st->len_star_2 - ft_u_int_len(st->uns_int_converter);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_u_no_point(st, final_len);
}

static void	ft_star_right(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	st->verif = 2;
	if (st->uns_int_converter == 0 && st->null == 0)
		st->long_converter = va_arg(ap, int);
	if (st->long_converter < 0)
		st->uns_int_converter = 4294967296 + st->long_converter;
	else
		st->uns_int_converter = st->long_converter;
	if (st->uns_int_converter == 0)
		st->null = 1;
	final_len = ft_atoi(st->flag) - ft_u_int_len(st->uns_int_converter);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_u_no_point(st, final_len);
}

static void	ft_two_star(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->len_star_3 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->uns_int_converter == 0 && st->null == 0)
		st->long_converter = va_arg(ap, int);
	if (st->long_converter < 0)
		st->uns_int_converter = 4294967296 + st->long_converter;
	else
		st->uns_int_converter = st->long_converter;
	if (st->uns_int_converter == 0)
		st->null = 1;
	if (st->len_star_2 >= 0)
		ft_two_star_sup_u(st, final_len);
	else
		ft_two_star_neg_u(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}

static void	ft_no_star(t_printf *st, va_list ap, int final_len)
{
	if (st->uns_int_converter == 0 && st->null == 0)
		st->long_converter = va_arg(ap, int);
	if (st->long_converter < 0)
		st->uns_int_converter = 4294967296 + st->long_converter;
	else
		st->uns_int_converter = st->long_converter;
	if (st->uns_int_converter == 0)
		st->null++;
	final_len = ft_atoi(st->flag) - ft_u_int_len(st->uns_int_converter);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_u_no_point(st, final_len);
}

void		ft_field_size_u(t_printf *st, va_list ap)
{
	int			final_len;

	final_len = 0;
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	if (st->star_pt_star == 1)
		ft_star_left(st, ap, final_len);
	else if (st->star_pt_star == 2)
		ft_two_star(st, ap, final_len);
	else if (st->star_pt_star == 3)
		ft_star_right(st, ap, final_len);
	else
		ft_no_star(st, ap, final_len);
}
