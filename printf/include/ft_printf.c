/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 11:40:48 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 16:18:35 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_algo(t_printf *st, int j, int k, char *fmt)
{
	while (fmt[st->i] == '*' || fmt[st->i] == '.' ||
			fmt[st->i] == '-' || (fmt[st->i] >= '0' && fmt[st->i] <= '9'))
	{
		ft_algo_star(st, j, k, fmt);
		ft_algo_field_size(st, fmt);
		ft_algo_point(st, fmt);
		st->i++;
	}
}

int			ft_check_arg(char *fmt, t_printf *st, va_list ap)
{
	int			j;
	int			k;

	j = 0;
	while (fmt[st->i])
	{
		if (fmt[st->i] == '%')
		{
			st->i++;
			k = st->i;
			ft_algo(st, j, k, fmt);
			ft_check_s(ap, st, fmt);
			ft_check_c(ap, st, fmt);
			ft_check_d_i(ap, st, fmt);
			ft_check_p(ap, st, fmt);
			ft_check_u(ap, st, fmt);
			ft_check_x(ap, st, fmt);
			ft_check_percent(ap, st, fmt);
		}
		else
			ft_putchar(fmt[st->i], st);
		st->i++;
	}
	return (1);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_printf	st[1];

	ft_init(st);
	va_start(ap, fmt);
	ft_check_arg((char*)fmt, st, ap);
	va_end(ap);
	return (st->k);
}
