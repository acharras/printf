/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_utils_fifth.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 16:13:48 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 14:22:40 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_convert(char *str, int i, char *set, unsigned long nbr)
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

static void	ft_size(unsigned long *nbr, int *i, char *set)
{
	int size_set;

	size_set = ft_strlen(set);
	while (*nbr / size_set > 0)
	{
		*nbr /= size_set;
		*i += 1;
	}
}

char		*ft_itoa_base_ul(unsigned long nbr, char *set)
{
	char			*str;
	int				i;
	unsigned long	nb_copy;

	i = 1;
	nb_copy = nbr;
	ft_size(&nbr, &i, set);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i--;
	str = ft_convert(str, i, set, nb_copy);
	return (str);
}

void		ft_memdel(void **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char		*ft_strdup_free(const char *s1)
{
	char		*tab;
	size_t		i;
	size_t		len;

	i = 0;
	len = ft_strlen(s1);
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	free((char *)s1);
	return (tab);
}
