/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_to_hex.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/22 13:25:58 by edribeir      #+#    #+#                 */
/*   Updated: 2023/11/23 10:59:24 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int nb_long(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

char ft_convert_to_hex(unsigned long n, char *base)
{
	char			*hex;
	unsigned int	count;

	count = nb_long(n);
	hex = (char *)malloc((count + 1) * sizeof(char));
	if (hex == NULL)
		return (NULL);
	hex[count] = '\0';
	while (n > 0)
	{
		hex[count - 1] = base[n % 16];
		n = n / 16;
		count--;
	}
	return (hex);
}
