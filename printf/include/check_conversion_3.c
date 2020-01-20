/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_conversion_3.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 14:09:19 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:09:55 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_check_p_star_no_flag(va_list ap, t_printf *st)
{
	if (ft_strcmp(st->flag + st->flag_star_i, "*") == 0 &&
		ft_strcmp(st->flag_sp_l, "l") != 0)
	{
		if (ft_check_dash(st) == 0)
			ft_dash_star_flag_p(ap, st);
		else
			ft_star_flag_p(ap, st);
	}
	else if (ft_strcmp(st->flag, NULL) == 0 ||
			ft_strcmp(st->flag_2, NULL) == 0 || ft_check_dash(st) == 0)
	{
		if (ft_strcmp(st->flag_sp_l, "l") != 0 &&
			ft_strcmp(st->flag_pt_s, ".") != 0 &&
			ft_strcmp(st->flag + st->flag_star_i, "*") != 0)
		{
			st->ll_converter = va_arg(ap, long long);
			st->str_convert = ft_strjoin_r_free("0x",
				ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
			if (st->ll_converter == 0)
				ft_putstr("0x0", st);
			else
				ft_putstr(st->str_convert, st);
		}
	}
}

void		ft_check_p(va_list ap, t_printf *st, char *fmt)
{
	if (fmt[st->i] == 'p')
	{
		if (ft_strcmp(st->flag_sp_l, "l") == 0)
			ft_field_size_p(st, ap);
		if (ft_strcmp(st->flag_pt_s, ".") == 0)
			ft_point_flag_p(st, ap);
		ft_check_p_star_no_flag(ap, st);
		ft_re_init(st);
	}
}

static void	ft_check_percent_star_no_flag(va_list ap, t_printf *st)
{
	if (ft_strcmp(st->flag + st->flag_star_i, "*") == 0 &&
			ft_strcmp(st->flag_sp_l, "l") != 0)
	{
		if (ft_check_dash(st) == 0)
			ft_dash_star_flag_percent(ap, st);
		else
			ft_star_flag_percent(ap, st);
	}
	else if (ft_strcmp(st->flag, NULL) == 0 ||
			ft_strcmp(st->flag_2, NULL) == 0 || ft_check_dash(st) == 0)
	{
		if (ft_strcmp(st->flag_sp_l, "l") != 0 &&
			ft_strcmp(st->flag_pt_s, ".") != 0 &&
			ft_strcmp(st->flag + st->flag_star_i, "*") != 0)
		{
			st->no_malloc_str = 1;
			ft_putchar('%', st);
		}
	}
}

void		ft_check_percent(va_list ap, t_printf *st, char *fmt)
{
	if (fmt[st->i] == '%')
	{
		if (ft_strcmp(st->flag_sp_l, "l") == 0)
			ft_field_size_percent(st, ap);
		if (ft_strcmp(st->flag_pt_s, ".") == 0)
			ft_point_flag_percent(st, ap);
		ft_check_percent_star_no_flag(ap, st);
		ft_re_init(st);
	}
}
