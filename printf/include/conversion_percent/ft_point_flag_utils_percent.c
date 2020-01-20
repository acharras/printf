/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_utils_percent.c                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 15:36:42 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:14:29 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_flag_null_percent(t_printf *st)
{
	st->str_convert = ft_strjoin_free(st->zero, "%");
	st->malloc_zero = 0;
}

void	ft_no_star_pt_no_star_percent(t_printf *st, int len_zero)
{
	if (st->flag == NULL)
		st->flag = ft_strdup("0");
	len_zero = ft_atoi(st->flag) - ft_strlen("%");
	if (len_zero >= 0)
	{
		if (ft_strcmp(st->flag_zero, "zero") == 0 && ft_check_dash(st) != 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(len_zero);
			st->malloc_zero = 1;
		}
		if (ft_atoi(st->flag) > 0)
		{
			st->str_convert = ft_strjoin_free(st->zero, "%");
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else
		st->str_convert = ft_strdup("%");
}

void	ft_star_pt_star_percent(t_printf *st, int len_zero)
{
	len_zero = st->len_star_2 - ft_strlen("%");
	if (len_zero >= 0)
	{
		if (ft_strcmp(st->flag_zero, "zero") == 0 && ft_check_dash(st) != 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(len_zero);
			st->malloc_zero = 1;
		}
		if (st->len_star_2 > 0)
		{
			st->str_convert = ft_strjoin_free(st->zero, "%");
			st->malloc_zero = 0;
		}
		else
			st->str_convert = ft_strdup(" ");
	}
	else
		st->str_convert = ft_strdup("%");
}

void	ft_no_star_pt_star_percent(t_printf *st, int len_zero)
{
	len_zero = ft_atoi(st->flag) - ft_strlen("%");
	if (len_zero >= 0)
	{
		if (ft_strcmp(st->flag_zero, "zero") == 0 && ft_check_dash(st) != 0)
		{
			if (st->malloc_zero == 1)
				ft_memdel((void *)&st->zero);
			st->zero = ft_fill_zero(len_zero);
		}
		st->str_convert = ft_strjoin_free(st->zero, "%");
		st->malloc_zero = 0;
	}
	else
		st->str_convert = ft_strdup("%");
}

void	ft_star_pt_no_star_percent(t_printf *st)
{
	st->str_convert = ft_strdup("%");
}
