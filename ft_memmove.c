/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:50:49 by euyi              #+#    #+#             */
/*   Updated: 2021/12/05 07:29:03 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* This function copies N amount of bytes from SRC to DEST 
** This function can copy and overlap source / same memory without
** affecting data. Meaning it can copy from arr[1] to arr[2] while
** still being able to copy the previous value of arr[2] to arr[3]
** This is possible because it compares the array size from both
** src and dest to determine if it should copy backward or forward
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**	   char *ptr = NULL;
**
**	   printf("dest = %s\n", (char *)ft_memmove(ptr, ptr, 4));
**	}
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	i = 0;
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dptr > sptr)
	{
		while (n > 0)
		{
			dptr[(n - 1)] = sptr[(n - 1)];
			n--;
		}
		return (dptr);
	}
	while (n > 0)
	{
		dptr[(i)] = sptr[(i)];
		i++;
		n--;
	}
	return (dptr);
}
