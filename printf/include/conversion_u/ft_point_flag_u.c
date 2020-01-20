/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_u.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 14:37:52 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:17:16 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_check_flag(t_printf *st)
{
	int		len_zero;
	char	*uns_char;

	len_zero = 0;
	uns_char = NULL;
	if (st->flag_2 == NULL)
		ft_flag_null_u(st);
	else if (st->verif == 0 && (st->star_pt_star == 0 || st->star_pt_star == 1
				|| st->star_pt_star == 3))
		ft_no_star_pt_no_star_u(st, len_zero, uns_char);
	else if (st->verif == 0 && (st->star_pt_star == 2 && st->len_star_3 != 0))
		ft_star_pt_star_u(st, len_zero, uns_char);
	else if (st->verif == 1 || st->verif == 2)
		ft_no_star_pt_star_u(st, len_zero, uns_char);
	else
		ft_star_pt_no_star_u(st, uns_char);
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
	}
}

void		ft_point_flag_u(t_printf *st, va_list ap)
{
	int		len;

	len = 0;
	if (ft_strcmp(st->flag_2, "*") == 0 && st->verif2 == 0)
	{
		st->len_star_2 = va_arg(ap, int);
		st->verif = 1;
	}
	if (st->uns_int_converter == 0 && st->null == 0)
		st->long_converter = va_arg(ap, int);
	if (st->long_converter < 0)
		st->uns_int_converter = 4294967296 + st->long_converter;
	else
		st->uns_int_converter = st->long_converter;
	if (st->uns_int_converter == 0)
		st->null++;
	ft_check_flag(st);
	ft_check_field_size(st, len);
	ft_putstr(st->str_convert, st);
	ft_check_dash_field(st, len);
}
