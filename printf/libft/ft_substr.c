/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: acharras <acharras@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 18:48:42 by acharras     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 13:01:31 by acharras    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (len > 0)
	{
		str[i] = (char)s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
