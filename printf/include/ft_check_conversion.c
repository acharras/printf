/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_conversion.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 14:38:30 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:45:21 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_check_c(va_list ap, t_printf *st, char *fmt)
{
	if (fmt[st->i] == 'c')
	{
		if (ft_strcmp(st->flag_sp_l, "l") == 0)
			ft_field_size_c(st, ap);
		if (ft_strcmp(st->flag + st->flag_star_i, "*") == 0 &&
			ft_strcmp(st->flag_sp_l, "l") != 0)
		{
			if (ft_check_dash(st) == 0)
				ft_dash_star_flag_c(ap, st);
			else
				ft_star_flag_c(ap, st);
		}
		else if (ft_strcmp(st->flag, NULL) == 0 ||
				ft_check_dash(st) == 0)
		{
			if (ft_strcmp(st->flag_sp_l, "l") != 0 &&
				ft_strcmp(st->flag + st->flag_star_i, "*") != 0)
			{
				st->char_converter = (char)va_arg(ap, int);
				ft_putchar(st->char_converter, st);
				st->no_malloc_str = 1;
			}
		}
		ft_re_init(st);
	}
}

static void	ft_check_s_star_no_flag(va_list ap, t_printf *st)
{
	if (ft_strcmp(st->flag + st->flag_star_i, "*") == 0 &&
			ft_strcmp(st->flag_sp_l, "l") != 0)
	{
		if (ft_check_dash(st) == 0)
			ft_dash_star_flag_s(ap, st);
		else
			ft_star_flag_s(ap, st);
	}
	else if (ft_strcmp(st->flag, NULL) == 0 ||
			ft_strcmp(st->flag_2, NULL) == 0 || ft_check_dash(st) == 0)
	{
		if (ft_strcmp(st->flag_sp_l, "l") != 0 &&
			ft_strcmp(st->flag_pt_s, ".") != 0 &&
			ft_strcmp(st->flag + st->flag_star_i, "*") != 0)
		{
			st->str_convert = va_arg(ap, char*);
			if (st->str_convert == NULL)
				st->str_convert = ft_strdup("(null)");
			else
				st->no_malloc_str = 1;
			ft_putstr(st->str_convert, st);
		}
	}
}

void		ft_check_s(va_list ap, t_printf *st, char *fmt)
{
	if (fmt[st->i] == 's')
	{
		if (ft_strcmp(st->flag_sp_l, "l") == 0)
			ft_field_size_s(st, ap);
		if (ft_strcmp(st->flag_pt_s, ".") == 0)
			ft_point_flag_s(st, ap);
		ft_check_s_star_no_flag(ap, st);
		ft_re_init(st);
	}
}

static void	ft_check_d_i_star_no_flag(va_list ap, t_printf *st)
{
	if (ft_strcmp(st->flag + st->flag_star_i, "*") == 0 &&
			ft_strcmp(st->flag_sp_l, "l") != 0)
	{
		if (ft_check_dash(st) == 0)
			ft_dash_star_flag_d_i(ap, st);
		else
			ft_star_flag_d_i(ap, st);
	}
	else if (ft_strcmp(st->flag, NULL) == 0 ||
			ft_strcmp(st->flag_2, NULL) == 0 || ft_check_dash(st) == 0)
	{
		if (ft_strcmp(st->flag_sp_l, "l") != 0 &&
			ft_strcmp(st->flag_pt_s, ".") != 0 &&
			ft_strcmp(st->flag + st->flag_star_i, "*") != 0)
		{
			st->int_converter = va_arg(ap, int);
			st->no_malloc_str = 1;
			ft_putnbr(st->int_converter, st);
		}
	}
}

void		ft_check_d_i(va_list ap, t_printf *st, char *fmt)
{
	if (fmt[st->i] == 'd' || fmt[st->i] == 'i')
	{
		if (ft_strcmp(st->flag_sp_l, "l") == 0)
			ft_field_size_d_i(st, ap);
		if (ft_strcmp(st->flag_pt_s, ".") == 0)
			ft_point_flag_d_i(st, ap);
		ft_check_d_i_star_no_flag(ap, st);
		ft_re_init(st);
	}
}
