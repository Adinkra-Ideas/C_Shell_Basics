/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:52:03 by euyi              #+#    #+#             */
/*   Updated: 2021/12/25 22:38:50 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** param 1. The prefix string.
** param 2. The suffix string.
**
** desc: Allocates (with malloc(3)) and returns a new
** string, which is the result of the concatenation
** of ’s1’ and ’s2’.
**
** Return value = The new string. NULL if the allocation fails.
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**		char arr[] = "hey ";
**		char arr2[] = "there!";
**	
**		printf("%s \n", ft_strjoin(arr, arr2));
**	}
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *) malloc(sizeof(char) * (len + 1) + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
