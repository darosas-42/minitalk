/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:47:04 by darosas-          #+#    #+#             */
/*   Updated: 2025/06/03 20:17:28 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signal)
{
	static int	bits;
	static char	c;

	if (signal == SIGUSR2)
		c |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("SERVER PID=%d\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
