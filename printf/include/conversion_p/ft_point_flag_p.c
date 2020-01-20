/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_point_flag_p.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 14:08:03 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 15:04:33 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_check_dash_field(t_printf *st, int len)
{
	if ((st->dash_field == 1 && st->verif == 0) ||
			(st->dash_star == 1 && st->verif == 1))
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

void		ft_point_flag_p(t_printf *st, va_list ap)
{
	int		len;

	len = 0;
	if (ft_strcmp(st->flag_2, "*") == 0 && st->verif2 == 0)
	{
		st->len_star_2 = va_arg(ap, int);
		st->verif = 1;
	}
	if (st->ll_converter == 0 && st->null == 0)
		st->ll_converter = va_arg(ap, long long);
	if (st->ll_converter == 0)
		st->null++;
	if (st->str_convert != NULL)
		ft_memdel((void *)&st->str_convert);
	st->str_convert = ft_strjoin_r_free("0x",
			ft_itoa_base_ul(st->ll_converter, "0123456789abcdef"));
	ft_check_field_size(st, len);
	if (st->ll_converter == 0)
		ft_putstr("0x", st);
	else
		ft_putstr(st->str_convert, st);
	ft_check_dash_field(st, len);
}
