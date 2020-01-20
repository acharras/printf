/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo_printf.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 14:11:52 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:22:08 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_resolve_algo_point(t_printf *st, char *fmt)
{
	if (fmt[st->i + 1] >= '0' && fmt[st->i + 1] <= '9')
	{
		st->i++;
		while (fmt[st->i] == '0')
			st->i++;
		if (fmt[st->i] == 'd' || fmt[st->i] == 'u' || fmt[st->i] == 'x' ||
				fmt[st->i] == 'X' || fmt[st->i] == '%' || fmt[st->i] == 's'
					|| fmt[st->i] == 'c' || fmt[st->i] == 'p' ||
					fmt[st->i] == 'i')
			st->i--;
		st->flag_pt = ft_atoi(&fmt[st->i]);
		st->flag_pt_s = ft_itoa(st->flag_pt);
		st->flag_2 = ft_substr(&fmt[st->i], 0, ft_strlen(st->flag_pt_s));
		ft_memdel((void *)&st->flag_pt_s);
	}
	else if (fmt[st->i + 1] == '*')
	{
		st->i++;
		if (st->star_pt_star == 1)
			st->star_pt_star = 2;
		else
			st->star_pt_star = 3;
		st->flag_2 = ft_substr(&fmt[st->i], 0, 1);
	}
}

void	ft_algo_point(t_printf *st, char *fmt)
{
	if (fmt[st->i] == '.')
	{
		if (fmt[st->i - 1] == '%')
			st->flag_zero = ft_strdup("zero");
		ft_resolve_algo_point(st, fmt);
		st->flag_pt_s = ft_strdup(".");
	}
}

void	ft_algo_field_zero_or_star(t_printf *st, char *fmt)
{
	while (fmt[st->i] == '0')
	{
		if (st->flag_zero != NULL)
			ft_memdel((void *)&st->flag_zero);
		st->flag_zero = ft_strdup("zero");
		st->i++;
	}
	if (fmt[st->i] == 'd' || fmt[st->i] == 'u' || fmt[st->i] == 'x' ||
			fmt[st->i] == 'X' || fmt[st->i] == '%' || fmt[st->i] == 'i')
		st->i--;
	if (fmt[st->i] == '*')
		st->star_pt_star = 1;
	ft_memdel((void *)&st->flag_sp_l);
	st->flag_sp_len = ft_atoi(&fmt[st->i]);
	st->flag_sp_l = ft_itoa(st->flag_sp_len);
}

void	ft_algo_field_size(t_printf *st, char *fmt)
{
	if (ft_strcmp(st->flag_pt_s, NULL) == 0)
	{
		if (fmt[st->i] >= '0' && fmt[st->i] <= '9')
		{
			ft_algo_field_zero_or_star(st, fmt);
			if (st->flag_sp_l[0] == '-')
			{
				st->i++;
				st->dash = 1;
				ft_memdel((void *)&st->flag_sp_l);
				st->flag_sp_len = ft_atoi(&fmt[st->i]);
				st->flag_sp_l = ft_itoa(st->flag_sp_len);
			}
			if (st->flag != NULL)
				ft_memdel((void *)&st->flag);
			st->flag = ft_substr(&fmt[st->i], 0, ft_strlen(st->flag_sp_l));
			ft_memdel((void *)&st->flag_sp_l);
			st->flag_sp_l = ft_strdup("l");
			while (ft_strlen(st->flag) > st->l)
			{
				st->l++;
				st->i++;
			}
		}
	}
}

void	ft_algo_star(t_printf *st, int j, int k, char *fmt)
{
	if (fmt[st->i] == '*' || fmt[st->i] == '-')
	{
		k = st->i;
		if (fmt[st->i] == '*' && fmt[st->i + 1] == '.')
		{
			st->star_pt_star = 1;
			st->flag_sp_l = ft_strdup("l");
			st->flag_star_i = j;
			j++;
			if (st->flag != NULL)
				ft_memdel((void *)&st->flag);
			st->flag = ft_substr(fmt, k, j);
		}
		else if (fmt[st->i] == '*')
		{
			st->flag_star_i = j;
			j++;
			if (st->flag != NULL)
				ft_memdel((void *)&st->flag);
			st->flag = ft_substr(fmt, k, j);
		}
		if (fmt[st->i] == '-')
			st->dash = 1;
	}
}
