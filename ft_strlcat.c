/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:49:08 by euyi              #+#    #+#             */
/*   Updated: 2021/12/25 22:37:51 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function concatenate strings DEST and SRC based on SIZE.
** If you give it SIZE of 3 for instance, it first check if DEST has a 
** strlen greater than 3-1
** if DEST has a strlen greater than 3-1, it wont touch DEST. 
** it simply returns (strlen src + 1)
** if dest has a strlen equal to 3-1, it puts 0 in dest[3-1] before 
** returning (strlen src + 1)
** if dest has a strlen less than 3-1, it will fill dest[strlen] .. dest[3-2]
** then put 0 in dest[3-1] before returning (strlen src + 1) (array size)
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**	   const char src[20]  = "newstrin";
**	   char dest[10] = "h";
**
**	   ft_strlcat(dest, src, 7);
**	   printf("After = %s\n %i\n", dest, dest[6]);
**	   printf("string length = %li", ft_strlcat(dest, src, 1));
**	}
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destbkp;
	size_t	srcbkp;
	size_t	i;
	size_t	j;

	destbkp = ft_strlen(dest);
	srcbkp = ft_strlen(src);
	i = 0;
	j = destbkp;
	if (destbkp < size - 1 && size > 0)
	{
		while (src[i] != 0 && destbkp + i < size - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
			dest[j] = 0;
		}
	}
	if (destbkp >= size)
		destbkp = size;
	return (destbkp + srcbkp);
}
