/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_u.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 13:36:38 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 08:31:53 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_print_u_no_point(t_printf *st, int final_len)
{
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	ft_no_zero(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
}

void	ft_two_star_sup_u(t_printf *st, int final_len)
{
	final_len = st->len_star_2 - ft_u_int_len(st->uns_int_converter);
	if (ft_strcmp(st->flag_zero, "zero") == 0 && final_len >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(final_len);
		st->malloc_zero = 1;
	}
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
		ft_putstr(st->str_convert, st);
		st->malloc_zero = 0;
	}
	ft_no_zero(st, final_len);
}

void	ft_fill_str_zero(t_printf *st, int len_zero)
{
	if (ft_strcmp(st->flag_zero, "zero") == 0 || st->uns_int_converter == 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(len_zero);
		st->malloc_zero = 1;
	}
}
