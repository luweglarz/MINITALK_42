/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:15:49 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 18:54:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

int     ft_strlen(const char *s);
void    ft_putstr_fd(int fd, const char *s);
int	    ft_atoi(const char *nptr);
char    *str_to_binary(char *s);

#endif