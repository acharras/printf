/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_p.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 13:55:32 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:47:23 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_star_left(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->ll_converter == 0 && st->null == 0)
		st->ll_converter = va_arg(ap, long long);
	if (st->ll_converter == 0)
		st->null = 1;
	if (st->len_star_2 < 0)
		st->dash_star = 1;
	st->str_convert = ft_strjoin_r_free("0x",
			ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	ft_print_no_point_p(st);
	ft_no_zero(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x", st);
		else
			ft_putstr(st->str_convert, st);
	}
}

static void	ft_star_right(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	st->verif = 2;
	if (st->ll_converter == 0 && st->null == 0)
		st->ll_converter = va_arg(ap, long long);
	if (st->ll_converter == 0)
		st->null = 1;
	st->str_convert = ft_strjoin_r_free("0x",
			ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
	final_len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x", st);
		else
			ft_putstr(st->str_convert, st);
	}
	ft_no_zero(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		if (st->int_converter == 0)
			ft_putstr("0x", st);
		else
			ft_putstr(st->str_convert, st);
	}
}

static void	ft_two_star(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->len_star_3 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->ll_converter == 0 && st->null == 0)
		st->ll_converter = va_arg(ap, long long);
	if (st->ll_converter == 0)
		st->null = 1;
	st->str_convert = ft_strjoin_r_free("0x",
			ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
	if (st->len_star_2 >= 0)
		ft_two_star_sup_p(st, final_len);
	else
		ft_two_star_neg_p(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x", st);
		else
			ft_putstr(st->str_convert, st);
	}
}

static void	ft_no_star(t_printf *st, va_list ap, int final_len)
{
	if (st->ll_converter == 0 && st->null == 0)
		st->ll_converter = va_arg(ap, long long);
	if (st->ll_converter == 0)
		st->null++;
	st->str_convert = ft_strjoin_r_free("0x",
			ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
	final_len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x0", st);
		else
			ft_putstr(st->str_convert, st);
	}
	ft_no_zero(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		if (st->ll_converter == 0)
			ft_putstr("0x0", st);
		else
			ft_putstr(st->str_convert, st);
	}
}

void		ft_field_size_p(t_printf *st, va_list ap)
{
	int			final_len;

	final_len = 0;
	if (st->star_pt_star == 1)
		ft_star_left(st, ap, final_len);
	else if (st->star_pt_star == 2)
		ft_two_star(st, ap, final_len);
	else if (st->star_pt_star == 3)
		ft_star_right(st, ap, final_len);
	else
		ft_no_star(st, ap, final_len);
}
