/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:00:18 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 18:58:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int     ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    ft_putstr_fd(int fd, const char *s)
{
    write(fd, s, ft_strlen(s));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nbr;
	int	isnegative;

	nbr = 0;
	isnegative = 1;
	i = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			isnegative = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (isnegative * nbr);
}

char *str_to_binary(char *s)
{
    int i;
    int k;
    int j;
    char    *binary;

    binary = malloc(sizeof(char) * (ft_strlen(s) * 8 + 1));
    i = 0;
    j = 0;
    while (s[i])
    {
        k = 7;
        while (k >= 0)
        {
            if (s[i] & (1 << k))
                binary[j++] = '1';
            else
                binary[j++] = '0';

            k--;
        }
        i++;
    }
    binary[j] = '\0';
    return (binary);
}