/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_percent.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 18:20:02 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:46:03 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_star_left(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->len_star_2 < 0)
		st->dash_star = 1;
	final_len = st->len_star_2 - 1;
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	ft_print_no_point_percent(st);
	ft_no_zero_percent_or_d_i(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}

static void	ft_star_right(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	st->verif = 2;
	final_len = ft_atoi(st->flag) - 1;
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
			ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	ft_no_zero_percent_or_d_i(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}

static void	ft_two_star(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->len_star_3 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->len_star_2 >= 0)
		ft_two_star_sup_percent(st, final_len);
	else
		ft_two_star_neg_percent(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}

static void	ft_no_star(t_printf *st, int final_len)
{
	final_len = ft_atoi(st->flag) - 1;
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0 &&
		ft_check_dash(st) != 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	ft_no_zero_percent_or_d_i(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		st->str_convert = ft_strjoin_free(st->zero, "%");
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}

void		ft_field_size_percent(t_printf *st, va_list ap)
{
	int		final_len;

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
		ft_no_star(st, final_len);
}
