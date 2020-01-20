/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_d_i.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:58:58 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:15:04 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_check_flag(t_printf *st)
{
	int		len_zero;

	len_zero = 0;
	if (st->int_converter == -2147483648)
	{
		st->int_converter = -2147483647;
		st->check_int_min = 1;
		st->dash_d = 1;
	}
	if (st->flag_2 == NULL)
		ft_flag_null_d_i(st);
	else if (st->verif == 0 && (st->star_pt_star == 0 || st->star_pt_star == 1
				|| st->star_pt_star == 3))
		ft_no_star_pt_no_star_d_i(st, len_zero);
	else if (st->verif == 0 && st->star_pt_star == 2)
		ft_star_pt_star_d_i(st, len_zero);
	else if (st->verif == 1 || st->verif == 2)
		ft_no_star_pt_star_d_i(st, len_zero);
	else
		ft_star_pt_no_star_d_i(st);
}

char		*ft_int_min(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	str[i - 1] = '8';
	return (str);
}

static void	ft_check_dash_field(t_printf *st, int len)
{
	if ((st->dash_field == 1 && (st->verif == 0 || st->verif2 == 1)) ||
			(st->dash_star == 1 && st->verif == 1))
	{
		if (st->dash_star == 1)
			st->len_star_2 *= -1;
		if (st->len_star_2 != 0 && st->verif != 2)
			len = st->len_star_2 - ft_strlen(st->str_convert);
		else
			len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
		if (len >= 0)
			st->space = ft_fill_space(len);
		else
			st->space = ft_strdup("");
		ft_putstr(st->space, st);
	}
}

static void	ft_check_field_size(t_printf *st, int len)
{
	if (st->dash_star == 1)
		st->verif = 1;
	if (st->dash_d == 1)
	{
		st->dash_zero = ft_strdup("-");
		st->str_convert = ft_strjoin_2_free(st->dash_zero, st->str_convert);
		if (st->check_int_min == 1)
			st->str_convert = ft_int_min(st->str_convert);
	}
	if ((st->check_pt == 1 && st->verif == 0) ||
			(st->dash_star == 1 && st->dash_field == 0 && st->verif == 0))
	{
		if (st->dash_star == 1)
			st->len_star_2 *= -1;
		if (st->len_star_2 != 0)
			len = st->len_star_2 - ft_strlen(st->str_convert);
		else
			len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
		if (len >= 0)
			st->space = ft_fill_space(len);
		else
			st->space = ft_strdup("");
		ft_putstr(st->space, st);
		st->verif = 1;
	}
}

void		ft_point_flag_d_i(t_printf *st, va_list ap)
{
	int		len;

	len = 0;
	if (ft_strcmp(st->flag_2, "*") == 0 && st->verif2 == 0)
	{
		st->len_star_2 = va_arg(ap, int);
		st->verif = 1;
	}
	if (st->int_converter == 0 && st->null == 0)
		st->int_converter = va_arg(ap, int);
	if (st->int_converter == 0)
		st->null++;
	ft_check_flag(st);
	ft_check_field_size(st, len);
	if (st->check_int_min == 1)
		ft_int_min(st->str_convert);
	ft_putstr(st->str_convert, st);
	ft_check_dash_field(st, len);
}
