/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_star_flag_p.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 16:25:06 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:14:12 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_dash_star_flag_p(va_list ap, t_printf *st)
{
	int			final_len;

	st->len_star = va_arg(ap, int);
	st->ll_converter = va_arg(ap, long long);
	st->str_convert = ft_strjoin_r_free("0x",
			ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
	final_len = st->len_star - ft_strlen(st->str_convert);
	if (final_len >= 0)
		st->space = ft_fill_space(final_len);
	else
		st->space = ft_strdup("");
	if (st->ll_converter == 0)
		ft_putstr("0x0", st);
	else
		ft_putstr(st->str_convert, st);
	if (ft_strcmp(st->flag_zero, "zero") != 0)
		ft_putstr(st->space, st);
}

static void	ft_len_star_2_sup(t_printf *st, int final_len)
{
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0)
	{
		if (final_len >= 0)
			st->space = ft_fill_space(final_len);
		else
			st->space = ft_strdup("");
		if (ft_strcmp(st->flag_zero, "zero") != 0)
			ft_putstr(st->space, st);
		if (st->ll_converter == 0)
			ft_putstr("0x0", st);
		else
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
		final_len = st->len_star_2 - ft_strlen(st->str_convert);
		if (ft_strcmp(st->flag_pt_s, ".") != 0)
		{
			if (st->ll_converter == 0)
				ft_putstr("0x0", st);
			else
				ft_putstr(st->str_convert, st);
			if (ft_strcmp(st->flag_zero, "zero") != 0)
				ft_print_space(st, final_len);
		}
	}
}

void		ft_star_flag_p(va_list ap, t_printf *st)
{
	int			final_len;

	if (st->verif == 0 && st->star_pt_star != 2)
		st->len_star_2 = va_arg(ap, int);
	if (st->ll_converter == 0 && st->null == 0)
		st->ll_converter = va_arg(ap, long long);
	if (st->ll_converter == 0)
		st->null = 1;
	st->str_convert = ft_strjoin_r_free("0x",
			ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	ft_len_star_2(st, final_len);
}
