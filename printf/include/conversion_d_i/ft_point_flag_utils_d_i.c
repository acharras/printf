/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_utils_d_i.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:40:21 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:13:44 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_flag_null_d_i(t_printf *st)
{
	ft_point_neg_d_i(st);
	if (st->malloc_zero == 1)
		ft_memdel((void *)&st->zero);
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	if (st->int_converter != 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
		st->malloc_zero = 0;
	}
	else if (st->check_pt == 1)
		st->str_convert = ft_strdup(" ");
	else
		st->str_convert = ft_strdup("");
}

void	ft_no_star_pt_no_star_d_i(t_printf *st, int len_zero)
{
	ft_point_neg_d_i(st);
	if (st->flag_2 == NULL)
		st->flag_2 = ft_strdup("0");
	len_zero = ft_atoi(st->flag_2) - ft_int_len(st->int_converter);
	if (len_zero >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(len_zero);
		st->malloc_zero = 1;
		if (st->int_converter != 0 || ft_atoi(st->flag_2) > 0)
		{
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else if (st->int_converter != 0)
		st->str_convert = ft_strdup_free(ft_itoa(st->int_converter));
	else if (ft_atoi(st->flag_2) != 0 && st->int_converter == 0)
		st->str_convert = ft_strdup_free(ft_itoa(st->int_converter));
	else
		st->str_convert = ft_strdup("");
}

void	ft_star_pt_star_d_i(t_printf *st, int len_zero)
{
	ft_point_neg_d_i(st);
	len_zero = st->len_star_3 - ft_int_len(st->int_converter);
	if (len_zero >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(len_zero);
		st->malloc_zero = 1;
		if (st->int_converter != 0 || st->len_star_3 > 0)
		{
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else if (st->int_converter != 0)
		st->str_convert = ft_strdup_free(ft_itoa(st->int_converter));
	else if (st->len_star_3 != 0 && st->int_converter == 0)
		st->str_convert = ft_strdup_free(ft_itoa(st->int_converter));
	else
		st->str_convert = ft_strdup("");
}

void	ft_no_star_pt_star_d_i(t_printf *st, int len_zero)
{
	ft_point_neg_d_i(st);
	len_zero = st->len_star_2 - ft_int_len(st->int_converter);
	if (len_zero >= 0)
	{
		if (st->malloc_zero == 1)
			ft_memdel((void *)&st->zero);
		st->zero = ft_fill_zero(len_zero);
		st->malloc_zero = 1;
		if (st->int_converter != 0 || st->len_star_2 > 0)
		{
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_itoa(st->int_converter));
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else if (st->int_converter != 0)
		st->str_convert = ft_strdup_free(ft_itoa(st->int_converter));
	else if (st->len_star_2 != 0 && st->int_converter == 0)
		st->str_convert = ft_strdup_free(ft_itoa(st->int_converter));
	else
		st->str_convert = ft_strdup("");
}

void	ft_star_pt_no_star_d_i(t_printf *st)
{
	ft_point_neg_d_i(st);
	if (st->int_converter != 0 && st->len_star_2 != 0)
		st->str_convert = ft_strdup_free(ft_itoa(st->int_converter));
	else
		st->str_convert = ft_strdup("");
}
