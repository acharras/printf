/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_conversion_2.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 14:08:14 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:09:56 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_check_u_star_no_flag(va_list ap, t_printf *st)
{
	if (ft_strcmp(st->flag + st->flag_star_i, "*") == 0 &&
			ft_strcmp(st->flag_sp_l, "l") != 0)
	{
		if (ft_check_dash(st) == 0)
			ft_dash_star_flag_u(ap, st);
		else
			ft_star_flag_u(ap, st);
	}
	else if (ft_strcmp(st->flag, NULL) == 0 ||
			ft_strcmp(st->flag_2, NULL) == 0 || ft_check_dash(st) == 0)
	{
		if (ft_strcmp(st->flag_sp_l, "l") != 0 &&
			ft_strcmp(st->flag_pt_s, ".") != 0 &&
			ft_strcmp(st->flag + st->flag_star_i, "*") != 0)
		{
			st->long_converter = va_arg(ap, int);
			st->no_malloc_str = 1;
			if (st->long_converter < 0)
				st->uns_int_converter = 4294967296 + st->long_converter;
			else
				st->uns_int_converter = st->long_converter;
			ft_putnbr_u(st->uns_int_converter, st);
		}
	}
}

void		ft_check_u(va_list ap, t_printf *st, char *fmt)
{
	if (fmt[st->i] == 'u')
	{
		if (ft_strcmp(st->flag_sp_l, "l") == 0)
			ft_field_size_u(st, ap);
		if (ft_strcmp(st->flag_pt_s, ".") == 0)
			ft_point_flag_u(st, ap);
		ft_check_u_star_no_flag(ap, st);
		ft_re_init(st);
	}
}

static void	ft_check_x_star_no_flag(va_list ap, t_printf *st, char *fmt)
{
	if (ft_strcmp(st->flag + st->flag_star_i, "*") == 0 &&
		ft_strcmp(st->flag_sp_l, "l") != 0)
	{
		if (ft_check_dash(st) == 0)
			ft_dash_star_flag_x(fmt, ap, st);
		else
			ft_star_flag_x(fmt, ap, st);
	}
	else if (ft_strcmp(st->flag, NULL) == 0 ||
			ft_strcmp(st->flag_2, NULL) == 0 || ft_check_dash(st) == 0)
	{
		if (ft_strcmp(st->flag_sp_l, "l") != 0 &&
			ft_strcmp(st->flag_pt_s, ".") != 0 &&
			ft_strcmp(st->flag + st->flag_star_i, "*") != 0)
		{
			st->int_converter = va_arg(ap, int);
			if (fmt[st->i] == 'x')
				st->str_convert = ft_itoa_base(st->int_converter,
					"0123456789abcdef");
			else if (fmt[st->i] == 'X')
				st->str_convert = ft_itoa_base(st->int_converter,
					"0123456789ABCDEF");
			ft_putstr(st->str_convert, st);
		}
	}
}

void		ft_check_x(va_list ap, t_printf *st, char *fmt)
{
	if (fmt[st->i] == 'x' || fmt[st->i] == 'X')
	{
		if (ft_strcmp(st->flag_sp_l, "l") == 0)
			ft_field_size_x(fmt, st, ap);
		if (ft_strcmp(st->flag_pt_s, ".") == 0)
			ft_point_flag_x(fmt, st, ap);
		ft_check_x_star_no_flag(ap, st, fmt);
		ft_re_init(st);
	}
}
