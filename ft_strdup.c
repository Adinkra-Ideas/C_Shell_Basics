/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:25:18 by euyi              #+#    #+#             */
/*   Updated: 2021/12/05 08:05:32 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* String Duplicator
** tries to allocate enough memory to hold the old string (plus a '\0'
** character to mark the end of the string).
** If the allocation failed, it sets errno to ENOMEM and returns NULL 
** immediately. Setting of errno to ENOMEM is something malloc does on auto
** Otherwise the allocation worked so we copy the old string to 
** the new string along with a terminating '\0' and return the new address.
** (which the caller is responsible for freeing at some later point).
** The  strdup()  function  returns a pointer to a new string which is a 
** duplicate of the string s.  Memory for the new string is obtained with 
** malloc(3), and can be freed with free(3).
** On success, the ft_strdup() function returns a pointer to the duplicated 
** string.
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**		char arr[13] = "pop";
**		
**	    printf("%s", ft_strdup(arr));
**	}
*/

char	*ft_strdup(const char *s)
{
	int		j;
	char	*ptr;

	j = (int)(ft_strlen((char *)s) + 1);
	ptr = (char *)malloc(j * sizeof(char));
	if (!s)
		return (NULL);
	ptr[(j - 1)] = '\0';
	j -= 2;
	while (j >= 0)
	{
		ptr[j] = s[j];
		j--;
	}
	return (ptr);
}
