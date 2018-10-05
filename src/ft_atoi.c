/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:23:40 by gfielder          #+#    #+#             */
/*   Updated: 2018/09/30 21:37:54 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	value;
	int	spaces;

	sign = 1;
	value = 0;
	spaces = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = value * 10 + sign * (str[i] - '0');
		else if (i == spaces && str[i] == '+')
			;
		else if (i <= spaces && str[i] == '-')
			sign = -1;
		else if (i <= spaces && (str[i] == ' '
					|| (str[i] >= 9 && str[i] <= 13)))
			spaces++;
		else
			break ;
		i++;
	}
	return (value);
}
