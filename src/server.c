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

int	main(void)
{
	ft_printf("SERVER PID=%d\n", getpid());
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
