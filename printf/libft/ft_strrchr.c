/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:52:05 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 18:53:53 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (*s == '\0' && c == '\0')
		return ((char*)s);
	if (c == '\0')
		return ((char*)(s + ft_strlen(s)));
	while (i >= 0)
	{
		if ((char)s[i] == c)
			return ((char*)s + i);
		i--;
	}
	return (NULL);
}
