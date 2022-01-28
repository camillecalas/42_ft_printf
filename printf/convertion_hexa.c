/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccalas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:04:26 by ccalas            #+#    #+#             */
/*   Updated: 2021/12/13 15:00:59 by ccalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_same_char(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 23)
			return (0);
		i++;
	}
	if (ft_strlen(base) < 2)
		return (0);
	else if (ft_same_char(base) == 0)
		return (0);
	else
		return (1);
}

int	ft_nb_lenght_hex(unsigned int n)
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

int	ft_putnbr_base(unsigned int nb, char *base)
{
	unsigned int	n;
	int				nombre;

	nombre = ft_nb_lenght_hex(nb);
	if (nb == 0)
		return (ft_putchar('0'));
	if (ft_is_base(base) != 0)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			n = -nb;
		}
		else
			n = nb;
		if (n > (unsigned int) ft_strlen(base) - 1)
		{
			ft_putnbr_base(n / ft_strlen(base), base);
			ft_putnbr_base(n % ft_strlen(base), base);
		}
		else
			ft_putchar(base[n]);
	}
	return (nombre);
}
