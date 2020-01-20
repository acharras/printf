/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_x.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 13:16:03 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:15:38 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_no_zero(t_printf *st, int final_len)
{
	if (final_len >= 0 && ft_strcmp(st->flag_zero, "zero") != 0)
	{
		st->space = ft_fill_space(final_len);
		if (ft_check_dash(st) != 0 && ft_strcmp(st->flag_pt_s, ".") != 0)
			ft_putstr(st->space, st);
		else if (ft_strcmp(st->flag_pt_s, ".") != 0)
			ft_putstr(st->space, st);
		else if (ft_strcmp(st->flag_pt_s, ".") == 0 && ft_check_dash(st) != 0)
			st->check_pt = 1;
		else
			st->dash_field = 1;
		ft_memdel((void *)&st->space);
	}
	else
	{
		if (ft_strcmp(st->flag_pt_s, ".") == 0 && ft_check_dash(st) != 0)
			st->check_pt = 1;
		else
			st->dash_field = 1;
	}
}

void	ft_print_x_no_dash(char *fmt, t_printf *st)
{
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
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

void	ft_no_point_x(char *fmt, t_printf *st, int final_len)
{
	ft_print_x_no_dash(fmt, st);
	ft_no_zero(st, final_len);
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

void	ft_two_star_sup_x(char *fmt, t_printf *st, int final_len)
{
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		ft_memdel((void *)&st->str_convert);
		if (fmt[st->i] == 'x')
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa_base(st->int_converter, "0123456789abcdef"));
		else if (fmt[st->i] == 'X')
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa_base(st->int_converter, "0123456789ABCDEF"));
		st->malloc_zero = 0;
		ft_putstr(st->str_convert, st);
	}
	ft_no_zero(st, final_len);
}

void	ft_know_x_or_maj_x(char *fmt, t_printf *st)
{
	if (fmt[st->i] == 'x')
		st->str_convert = ft_itoa_base(st->int_converter, "0123456789abcdef");
	else if (fmt[st->i] == 'X')
		st->str_convert = ft_itoa_base(st->int_converter, "0123456789ABCDEF");
}
