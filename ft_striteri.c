/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 01:21:34 by euyi              #+#    #+#             */
/*   Updated: 2021/12/25 22:39:09 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* this function applies its param 2 (pointer to a function)
**  to each character of the string in param 1.
*/
/*	void	ptr2func(unsigned int n, char *c);
**	#include <stdio.h>
**	int main(void)
**	{
**		char arr[9] = "hello";
**		ft_striteri(arr, ptr2func);
**		printf("%s", arr);
**	}
**
**	void	ptr2func(unsigned int n, char *c)
**	{
**		n++;
**		*c += 1;
**		n--;		
**	}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[(i)])
	{
		f(i, &s[(i)]);
		i++;
	}
}
