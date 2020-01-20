/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_field_size_s.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 11:05:41 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 15:20:37 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static void	ft_star_left(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	if (st->str_convert == NULL && st->null == 0)
		st->str_convert = va_arg(ap, char *);
	if (st->str_convert == NULL)
	{
		st->null = 1;
		st->str_convert = ft_strdup("(null)");
	}
	else
		st->no_malloc_str = 1;
	final_len = st->len_star_2 - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
		ft_putstr(st->str_convert, st);
	ft_no_zero(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
		ft_putstr(st->str_convert, st);
}

static void	ft_star_right(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->verif2 = 1;
	st->verif = 2;
	if (st->str_convert == NULL && st->null == 0)
		st->str_convert = va_arg(ap, char *);
	if (st->str_convert == NULL)
	{
		st->null = 1;
		st->str_convert = ft_strdup("(null)");
	}
	else
		st->no_malloc_str = 1;
	final_len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
		ft_putstr(st->str_convert, st);
	ft_no_zero(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
		ft_putstr(st->str_convert, st);
}

static void	ft_two_star(t_printf *st, va_list ap, int final_len)
{
	st->len_star_2 = va_arg(ap, int);
	st->len_star_3 = va_arg(ap, int);
	st->verif2 = 2;
	if (st->str_convert == NULL && st->null == 0)
		st->str_convert = va_arg(ap, char *);
	if (st->str_convert == NULL)
	{
		st->null = 1;
		st->str_convert = ft_strdup("(null)");
	}
	else
		st->no_malloc_str = 1;
	if (st->len_star_2 >= 0)
	{
		final_len = st->len_star_2 - ft_strlen(st->str_convert);
		if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
			ft_putstr(st->str_convert, st);
		ft_no_zero(st, final_len);
	}
	else
		ft_two_star_neg_s(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
		ft_putstr(st->str_convert, st);
}

static void	ft_no_star(t_printf *st, va_list ap, int final_len)
{
	if (st->str_convert == NULL && st->null == 0)
		st->str_convert = va_arg(ap, char *);
	if (st->str_convert == NULL)
	{
		st->null++;
		st->str_convert = ft_strdup("(null)");
	}
	else
		st->no_malloc_str = 1;
	final_len = ft_atoi(st->flag) - ft_strlen(st->str_convert);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) == 0)
		ft_putstr(st->str_convert, st);
	ft_no_zero(st, final_len);
	if (ft_strcmp(st->flag_pt_s, ".") != 0 && ft_check_dash(st) != 0)
		ft_putstr(st->str_convert, st);
}

void		ft_field_size_s(t_printf *st, va_list ap)
{
	int			final_len;

	final_len = 0;
	if (st->star_pt_star == 1)
		ft_star_left(st, ap, final_len);
	else if (st->star_pt_star == 2)
		ft_two_star(st, ap, final_len);
	else if (st->star_pt_star == 3)
		ft_star_right(st, ap, final_len);
	else
		ft_no_star(st, ap, final_len);
}
