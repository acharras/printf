/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_utils_u.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 15:00:17 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 08:32:16 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_flag_null_u(t_printf *st)
{
	if (st->malloc_zero == 1)
		ft_memdel((void *)&st->zero);
	st->zero = ft_fill_zero(0);
	st->malloc_zero = 1;
	if (st->uns_int_converter != 0)
	{
		st->str_convert = ft_strjoin_2_free(st->zero,
			ft_uns_itoa(st->uns_int_converter));
		st->malloc_zero = 0;
	}
	else if (st->check_pt == 1)
		st->str_convert = ft_strdup(" ");
	else
		st->str_convert = ft_strdup("");
}

void	ft_no_star_pt_no_star_u(t_printf *st, int len_zero, char *uns_char)
{
	uns_char = ft_uns_itoa(st->uns_int_converter);
	len_zero = ft_atoi(st->flag_2) - ft_u_int_len(st->uns_int_converter);
	if (len_zero >= 0)
	{
		ft_fill_str_zero(st, len_zero);
		if (st->uns_int_converter != 0 || ft_atoi(st->flag_2) > 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(len_zero);
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else if (st->uns_int_converter != 0)
		st->str_convert = ft_strdup(uns_char);
	else
		st->str_convert = ft_strdup("");
	ft_memdel((void *)&uns_char);
}

void	ft_star_pt_star_u(t_printf *st, int len_zero, char *uns_char)
{
	uns_char = ft_uns_itoa(st->uns_int_converter);
	len_zero = st->len_star_3 - ft_u_int_len(st->uns_int_converter);
	if (len_zero >= 0)
	{
		ft_fill_str_zero(st, len_zero);
		st->malloc_zero = 1;
		if (st->uns_int_converter != 0 || st->len_star_3 > 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(len_zero);
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else
		st->str_convert = ft_strdup(uns_char);
	ft_memdel((void *)&uns_char);
}

void	ft_no_star_pt_star_u(t_printf *st, int len_zero, char *uns_char)
{
	uns_char = ft_uns_itoa(st->uns_int_converter);
	len_zero = st->len_star_2 - ft_u_int_len(st->uns_int_converter);
	if (len_zero >= 0)
	{
		ft_fill_str_zero(st, len_zero);
		st->malloc_zero = 1;
		if (st->uns_int_converter != 0 || st->len_star_2 > 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(len_zero);
			st->str_convert = ft_strjoin_2_free(st->zero,
				ft_uns_itoa(st->uns_int_converter));
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else
		st->str_convert = ft_strdup(uns_char);
	ft_memdel((void *)&uns_char);
}

void	ft_star_pt_no_star_u(t_printf *st, char *uns_char)
{
	uns_char = ft_uns_itoa(st->uns_int_converter);
	if (st->uns_int_converter != 0)
		st->str_convert = ft_strdup(uns_char);
	else
		st->str_convert = ft_strdup(" ");
	ft_memdel((void *)&uns_char);
}
