/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_utils_x.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 15:00:01 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 08:13:57 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_flag_null_x(char *fmt, t_printf *st)
{
	if (st->malloc_zero == 1)
		ft_memdel((void *)&st->zero);
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	ft_memdel((void *)&st->str_convert);
	if (st->int_converter != 0)
		ft_replace_x_or_maj_x(fmt, st);
	else if (st->check_pt == 1)
		st->str_convert = ft_strdup(" ");
	else
		st->str_convert = ft_strdup("");
}

void	ft_no_star_pt_no_star_x(char *fmt, t_printf *st, int len_zero)
{
	len_zero = ft_atoi(st->flag_2) - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (len_zero >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(len_zero);
		st->malloc_zero = 1;
		if (st->int_converter != 0 || ft_atoi(st->flag_2) > 0)
			ft_replace_x_or_maj_x(fmt, st);
		else
			st->str_convert = ft_strdup(" ");
	}
	else if (st->int_converter != 0)
	{
		if (fmt[st->i] == 'x')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789abcdef"));
		else if (fmt[st->i] == 'X')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789ABCDEF"));
	}
	else
		st->str_convert = ft_strdup("");
}

void	ft_star_pt_star_x(char *fmt, t_printf *st, int len_zero)
{
	len_zero = st->len_star_3 - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (len_zero >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(len_zero);
		st->malloc_zero = 1;
		if (st->int_converter != 0 || st->len_star_3 > 0)
			ft_replace_x_or_maj_x(fmt, st);
		else
			st->str_convert = ft_strdup(" ");
	}
	else
	{
		if (fmt[st->i] == 'x')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789abcdef"));
		else if (fmt[st->i] == 'X')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789ABCDEF"));
	}
}

void	ft_no_star_pt_star_x(char *fmt, t_printf *st, int len_zero)
{
	len_zero = st->len_star_2 - ft_strlen(st->str_convert);
	ft_memdel((void *)&st->str_convert);
	if (len_zero >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(len_zero);
		st->malloc_zero = 1;
		if (st->int_converter != 0 || st->len_star_2 > 0)
			ft_replace_x_or_maj_x(fmt, st);
		else
			st->str_convert = ft_strdup(" ");
	}
	else
	{
		if (fmt[st->i] == 'x')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789abcdef"));
		else if (fmt[st->i] == 'X')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789ABCDEF"));
	}
}

void	ft_star_pt_no_star_x(char *fmt, t_printf *st)
{
	ft_memdel((void *)&st->str_convert);
	if (st->int_converter != 0)
	{
		if (fmt[st->i] == 'x')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789abcdef"));
		else if (fmt[st->i] == 'X')
			st->str_convert = ft_strdup_free(ft_itoa_base(st->int_converter,
				"0123456789ABCDEF"));
	}
	else
		st->str_convert = ft_strdup(" ");
}
