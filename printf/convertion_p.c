/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:47:25 by ccalas            #+#    #+#             */
/*   Updated: 2021/12/13 15:01:12 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_lenght_p(uintptr_t n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_putnbr_p(uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_putnbr_p(nb / 16);
		ft_putnbr_p(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	ft_putstr_p(uintptr_t p)
{
	int	len;

	len = 0;
	len = len + write(1, "0x", 2);
	if (p == 0)
		len = len + write(1, "0", 1);
	else
	{
		ft_putnbr_p(p);
		len = len + ft_nb_lenght_p(p);
	}
	return (len);
}
