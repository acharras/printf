/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 17:32:17 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:52:52 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(char *str, int i, long nbr)
{
	int	min;

	if (str[0] == '-')
		min = 1;
	else
		min = 0;
	str[i + 1] = '\0';
	while (i >= min)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
	return (str);
}

static void	ft_size(int *nbr, int *i)
{
	while (*nbr / 10 >= 1 || *nbr / 10 <= -1)
	{
		*nbr /= 10;
		*i += 1;
	}
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	long	nb_copy;

	i = 1;
	nb_copy = nbr;
	ft_size(&nbr, &i);
	if (nb_copy < 0)
	{
		nb_copy = -nb_copy;
		i++;
		if (!(str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		str[0] = '-';
	}
	else
	{
		if (!(str = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		str[0] = 0;
	}
	i--;
	str = ft_convert(str, i, nb_copy);
	return (str);
}
