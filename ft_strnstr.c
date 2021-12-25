/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:53:06 by euyi              #+#    #+#             */
/*   Updated: 2021/12/03 22:10:57 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* is a string searcher. It searches for the full string of LITTLE
** within the first N characters of BIG.
** Characters that appear after a `\0' character are not searched
** If LITTLE doesn't occur in BIG, it returns NULL
** If LITTLE is an empty string, BIG is returned
** If LITTLE exists in BIG, a pointer to the first character of the 
** first occurrence of LITTLE in BIG is returned
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**		const char bigstr[] = "Intttynational";
**	  	const char litstr[] = "tty";
**		char *ret;
**
**		ret = ft_strnstr(bigstr, litstr, 6);
**		printf("ret = %s", ret);
**	}
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	litlen;

	litlen = ft_strlen(little);
	i = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (len > i && big[i] != '\0')
	{
		if ((ft_strncmp(&big[i], little, litlen) == 0) && (i + litlen <= len))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
