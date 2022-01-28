/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:47:44 by ccalas            #+#    #+#             */
/*   Updated: 2021/12/13 15:01:28 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_lenght_unsigned(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (len = 1);
	while (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	unsigned int	n;
	int				nombre;

	nombre = ft_nb_lenght_unsigned(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		n = n % 10;
	}
	ft_putchar(n + 48);
	return (nombre);
}
