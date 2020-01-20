/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_utils_first.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 10:28:35 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:23:04 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c, t_printf *st)
{
	write(1, &c, 1);
	st->k++;
}

void	ft_putstr(char *s, t_printf *st)
{
	write(1, s, ft_strlen(s));
	st->k = st->k + ft_strlen(s);
}

void	ft_putnbr(int n, t_printf *st)
{
	long	i;

	i = n;
	if (i < 0)
	{
		i = i * -1;
		ft_putchar(('-'), st);
	}
	if (i >= 10)
		ft_putnbr((i / 10), st);
	ft_putchar(('0' + (i % 10)), st);
}

char	*ft_fill_space(int len)
{
	char		*str;
	int			i;

	i = 0;
	if (!(str = malloc(sizeof(str) * len + 1)))
		return (NULL);
	while (len != 0)
	{
		str[i] = ' ';
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putnbr_u(unsigned int n, t_printf *st)
{
	long long	i;

	i = n;
	if (i < 0)
	{
		i = i * -1;
		ft_putchar(('-'), st);
	}
	if (i >= 10)
		ft_putnbr_u((i / 10), st);
	ft_putchar(('0' + (i % 10)), st);
}
