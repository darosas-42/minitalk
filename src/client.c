/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darosas- <darosas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:51:50 by darosas-          #+#    #+#             */
/*   Updated: 2025/06/03 18:52:38 by darosas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_signal(char c, int pid)
{
    int i;

    i = -1;
    while (++i < 8)
    {
        if ((c << i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(100);
    }
}

int	main(int argc, char **argv)
{
    int i;
    int pid;

	if (argc != 3)
        return (1);
    i = 0;
    pid = ft_atoi(argv[1]);
    while (argv[2][i])
        send_signal(argv[2][i], pid);
}
