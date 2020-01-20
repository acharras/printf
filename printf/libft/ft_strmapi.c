/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 14:40:10 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 15:12:18 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*map;

	i = 0;
	map = NULL;
	if (s != '\0' && f)
	{
		if (!(map = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
			return (NULL);
		while (i < ft_strlen((char*)s))
		{
			map[i] = f(i, s[i]);
			i++;
		}
	}
	map[i] = '\0';
	return (map);
}
