/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag_c.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 14:55:10 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:13:26 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_star(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	st->char_converter = (char)va_arg(ap, int);
	final_len = st->len_star_2 - 1;
	if (ft_check_dash(st) == 0)
		ft_putchar(st->char_converter, st);
	if (final_len >= 0)
	{
		st->space = ft_fill_space(final_len);
		ft_putstr(st->space, st);
	}
	if (ft_check_dash(st) != 0)
		ft_putchar(st->char_converter, st);
}

static void	ft_no_star(t_printf *st, va_list ap, int final_len)
{
	if (st->char_converter == 0)
		st->char_converter = (char)va_arg(ap, int);
	final_len = ft_atoi(st->flag) - 1;
	if (ft_check_dash(st) == 0)
		ft_putchar(st->char_converter, st);
	if (final_len >= 0)
	{
		st->space = ft_fill_space(final_len);
		ft_putstr(st->space, st);
	}
	if (ft_check_dash(st) != 0)
		ft_putchar(st->char_converter, st);
}

void		ft_field_size_c(t_printf *st, va_list ap)
{
	int		final_len;

	final_len = 0;
	st->no_malloc_str = 1;
	if (st->star_pt_star == 1)
		ft_star(st, ap, final_len);
	else
		ft_no_star(st, ap, final_len);
}

void		ft_dash_star_flag_c(va_list ap, t_printf *st)
{
	int		final_len;

	st->len_star = va_arg(ap, int);
	st->char_converter = (char)va_arg(ap, int);
	final_len = st->len_star - 1;
	st->no_malloc_str = 1;
	if (final_len >= 0)
		st->space = ft_fill_space(final_len);
	else
		st->space = ft_strdup("");
	ft_putchar(st->char_converter, st);
	ft_putstr(st->space, st);
}

void		ft_star_flag_c(va_list ap, t_printf *st)
{
	int		final_len;

	st->len_star = va_arg(ap, int);
	st->char_converter = (char)va_arg(ap, int);
	final_len = st->len_star - 1;
	st->no_malloc_str = 1;
	if (final_len >= 0)
	{
		st->space = ft_fill_space(final_len);
		ft_putstr(st->space, st);
		ft_putchar(st->char_converter, st);
	}
	else
	{
		ft_putchar(st->char_converter, st);
		final_len = final_len * -1 - 2;
		st->space = ft_fill_space(final_len);
		ft_putstr(st->space, st);
	}
}
