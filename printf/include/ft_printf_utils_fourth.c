/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_utils_fourth.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 15:57:04 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:23:43 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_nbsize(size_t nb)
{
	size_t	size;

	size = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

static char	*ft_algo_itoa(size_t nb, size_t size, char *str)
{
	size_t	i;

	i = size - 1;
	while (nb >= 10)
	{
		str[i--] = (char)('0' + nb % 10);
		nb = nb / 10;
	}
	str[i] = (char)('0' + nb % 10);
	str[size] = '\0';
	return (str);
}

char		*ft_uns_itoa(unsigned int n)
{
	char	*str;
	size_t	nb;
	size_t	size;

	nb = n;
	size = (size_t)ft_nbsize(nb);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = ft_algo_itoa(nb, size, str);
	return (str);
}

int			ft_check_dash(t_printf *st)
{
	while (st->flag[st->flag_dash_i] == '-')
		st->flag_dash_i++;
	if (st->dash == 1)
		return (0);
	if (st->flag_dash_i != 0)
		return (0);
	return (1);
}

void		ft_print_space(t_printf *st, int final_len)
{
	if (final_len >= 0)
	{
		st->space = ft_fill_space(final_len);
		ft_putstr(st->space, st);
	}
}
