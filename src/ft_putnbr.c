/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:44:41 by gfielder          #+#    #+#             */
/*   Updated: 2018/10/04 05:40:08 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MY_LONG_MIN -9223372036854775807

int		ft_putchar(char c);

void	ft_putnbr(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == MY_LONG_MIN)
		{
			ft_putchar('9');
			nb = -223372036854775807;
		}
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + (nb % 10));
	}
	else
		ft_putchar('0' + nb);
}