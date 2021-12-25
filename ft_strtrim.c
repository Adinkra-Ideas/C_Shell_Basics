/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:38:50 by euyi              #+#    #+#             */
/*   Updated: 2021/12/05 09:53:42 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Param #1. The string to be trimmed.
** param#2. The reference set of characters to trim.
** Return value The trimmed string. NULL if the allocation fails.
** External functs. malloc
** Description Allocates (with malloc(3)) and returns a copy of
** ’s1’ with the characters specified in ’set’ removed
** from the beginning and/or the end of the string.
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**		char src[] = "          ";
**	
**		printf("%s\n", ft_strtrim(src, "\t \n"));
**	}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	ptr = (char *) malloc(ft_strlen((char *)s1) + 2);
	while (ft_strchr((char *)set, *s1) != NULL && *s1 != '\0')
		s1++;
	if (*s1 == '\0')
	{
		ptr[0] = '\0';
		return (ptr);
	}
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	i--;
	while (ft_strchr(set, ptr[i]) != NULL)
		i--;
	ptr[i + 1] = '\0';
	return (ptr);
}
