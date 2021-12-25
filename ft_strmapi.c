/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:22:38 by euyi              #+#    #+#             */
/*   Updated: 2021/12/25 22:43:01 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Strmapi returns pointer to a string created from the successive 
** applications of the function pointed to by the function pointer F.
** Strmapi returns NULL if the allocation fails.
**
** param 1 is The string on which to iterate.
** param 2 is a pointer to to function to apply to each character.
**
** A loop is created to pass *s index through the character string, and
** passing each index as first argument to the function pointed by F.
*/
/*	char	ptr2func(unsigned int n, char c);
**	#include <stdio.h>
**	int main(void)
**	{
**		char arr[] = "What is it";
**	
**		printf("My result is %s\n", ft_strmapi(arr, ptr2func));
**	}
**
**	char	ptr2func(unsigned int n, char c)
**	{
**		if (n != (unsigned int)c)
**			return (c);
**		else
**			return ((char)n);
**	}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s)) + 1);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
