/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:47:40 by euyi              #+#    #+#             */
/*   Updated: 2021/12/25 22:40:34 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function counts a string and returns the length as an unsigned long int
** represented as size_t, meaning its value cant be less than zero
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**		char c[] = "hello";
** 
**	    printf("%li", ft_strlen(c));
**	}
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[(i)])
		i++;
	return (i);
}
