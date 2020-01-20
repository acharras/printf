/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_s.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:46:00 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:20:46 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_check_flag(t_printf *st, int len)
{
	if (st->flag_2 == NULL)
		st->str_convert_2 = ft_substr(st->str_convert, 0, 0);
	else if (st->verif == 0 && (st->star_pt_star == 0 || st->star_pt_star == 1
			|| st->star_pt_star == 3))
		st->str_convert_2 = ft_substr(st->str_convert, 0, ft_atoi(st->flag_2));
	else if (st->verif == 0 && (st->star_pt_star == 2 && st->len_star_3 != 0))
		st->str_convert_2 = ft_substr(st->str_convert, 0, st->len_star_3);
	else if (st->verif == 1 || st->verif == 2)
		st->str_convert_2 = ft_substr(st->str_convert, 0, st->len_star_2);
	else
		st->str_convert_2 = ft_substr(st->str_convert, 0, 0);
	if (st->check_pt == 1 && st->verif == 0)
	{
		if (st->len_star_2 != 0)
			len = st->len_star_2 - ft_strlen(st->str_convert_2);
		else
			len = ft_atoi(st->flag) - ft_strlen(st->str_convert_2);
		if (len >= 0)
			st->space = ft_fill_space(len);
		else
			st->space = ft_strdup("");
		ft_putstr(st->space, st);
	}
}

static void	ft_check_dash_field(t_printf *st, int len)
{
	if (st->dash_field == 1 && (st->verif == 0 || st->verif2 == 1))
	{
		if (st->len_star_2 != 0 && st->verif != 2)
			len = st->len_star_2 - ft_strlen(st->str_convert_2);
		else
			len = ft_atoi(st->flag) - ft_strlen(st->str_convert_2);
		if (len >= 0)
			st->space = ft_fill_space(len);
		else
			st->space = ft_strdup("");
		ft_putstr(st->space, st);
	}
}

void		ft_point_flag_s(t_printf *st, va_list ap)
{
	int		len;

	len = 0;
	if (ft_strcmp(st->flag_2, "*") == 0 && st->verif2 == 0)
	{
		st->len_star_2 = va_arg(ap, int);
		st->verif = 1;
	}
	if (st->str_convert == NULL && st->null == 0)
		st->str_convert = va_arg(ap, char*);
	if (st->str_convert == NULL)
	{
		st->null++;
		st->str_convert = ft_strdup("(null)");
	}
	else if (ft_strcmp(st->str_convert, "(null)") == 0)
		st->no_malloc_str = 0;
	else
		st->no_malloc_str = 1;
	ft_check_flag(st, len);
	ft_putstr(st->str_convert_2, st);
	ft_check_dash_field(st, len);
}
