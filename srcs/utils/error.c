/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:58:34 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 17:12:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	error(int errcode, char *tofree)
{
	if (errcode == ERRSIGNAL1)
		printf("Failed to send the signal\n");
	if (errcode == ERRSIGNAL2)
		printf("Failed to receive the signal\n");
	if (errcode == ERRSIGNAL3)
		printf("Signum isn't SIGUSR1 or SIGUSR2 \n");
	if (tofree)
		free(tofree);
	exit(errcode);
}
