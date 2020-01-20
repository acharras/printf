/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_star_flag_s.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 17:21:33 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 14:14:49 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

void		ft_dash_star_flag_s(va_list ap, t_printf *st)
{
	int		final_len;

	st->len_star = va_arg(ap, int);
	if (st->str_convert == NULL && st->null == 0)
		st->str_convert = va_arg(ap, char*);
	if (st->str_convert == NULL)
	{
		st->null = 1;
		st->str_convert = ft_strdup("(null)");
	}
	else
		st->no_malloc_str = 1;
	final_len = st->len_star - ft_strlen(st->str_convert);
	if (final_len >= 0)
		st->space = ft_fill_space(final_len);
	else
		st->space = ft_strdup("");
	ft_putstr(st->str_convert, st);
	ft_putstr(st->space, st);
}

static void	ft_len_star_2(t_printf *st, int final_len)
{
	if (st->len_star_2 >= 0)
	{
		final_len = st->len_star_2 - ft_strlen(st->str_convert);
		if (ft_strcmp(st->flag_pt_s, ".") != 0)
		{
			if (final_len >= 0)
				st->space = ft_fill_space(final_len);
			else
				st->space = ft_strdup("");
			ft_putstr(st->space, st);
			ft_putstr(st->str_convert, st);
		}
	}
	else
	{
		st->len_star_2 *= -1;
		final_len = st->len_star_2 - ft_strlen(st->str_convert);
		if (ft_strcmp(st->flag_pt_s, ".") != 0)
		{
			ft_putstr(st->str_convert, st);
			ft_print_space(st, final_len);
		}
	}
}

void		ft_star_flag_s(va_list ap, t_printf *st)
{
	int		final_len;

	final_len = 0;
	if (st->verif == 0 && st->star_pt_star != 2)
		st->len_star_2 = va_arg(ap, int);
	if (st->str_convert == NULL && st->null == 0)
		st->str_convert = va_arg(ap, char *);
	if (st->str_convert == NULL)
	{
		st->null = 1;
		st->str_convert = ft_strdup("(null)");
	}
	else
		st->no_malloc_str = 1;
	ft_len_star_2(st, final_len);
}
