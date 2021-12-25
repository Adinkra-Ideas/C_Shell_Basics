/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:30:54 by euyi              #+#    #+#             */
/*   Updated: 2021/12/25 22:35:17 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function searches string *S to return the first occurence of C
** if C not found, it returns NULL
** The function search even the null str terminator '\0'
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**	   const char str[] = "monnster";
**	   const char ch = '\0';
**	   char *ret;
**
**	   ret = ft_strchr(str, ch);
**
**	   printf("String after |%c| is - |%s|\n%c", ch, ret, *str);
**	}
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		i--;
	}	
	return (NULL);
}
