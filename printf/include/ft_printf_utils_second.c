/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_utils_second.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/22 17:31:16 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:06:38 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_strcmp(char *s1, char *s2)
{
	int i;
	int comp;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	comp = (s1[i] - s2[i]);
	return (comp);
}

static char	*ft_convert(char *str, int i, char *set, long nbr)
{
	int min;
	int size_set;

	size_set = ft_strlen(set);
	min = 0;
	str[i + 1] = '\0';
	while (i >= min)
	{
		str[i] = set[nbr % size_set];
		nbr = nbr / size_set;
		i--;
	}
	return (str);
}

static void	ft_size(long *nbr, int *i, char *set)
{
	int size_set;

	size_set = ft_strlen(set);
	while (*nbr / size_set > 0)
	{
		*nbr /= size_set;
		*i += 1;
	}
}

char		*ft_itoa_base(long nbr, char *set)
{
	char	*str;
	int		i;
	long	nb_copy;

	i = 1;
	if (nbr < 0)
		nbr = 4294967296 + nbr;
	nb_copy = nbr;
	ft_size(&nbr, &i, set);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i--;
	str = ft_convert(str, i, set, nb_copy);
	return (str);
}

char		*ft_fill_zero(int len)
{
	char		*str;
	int			i;

	i = 0;
	if (!(str = malloc(sizeof(str) * len + 1)))
		return (NULL);
	while (len != 0)
	{
		str[i] = '0';
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
