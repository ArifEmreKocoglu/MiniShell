/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:13:48 by akocoglu          #+#    #+#             */
/*   Updated: 2022/08/24 19:06:54 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_readline(t_minishell *ms)
{
	ms->line = readline(ft_strjoin("[minishell][:)]~> ", ""));
	add_history(ms->line);
	return (1);
}

void	lunch_program(char **env, char **argv)
{
	int pid;
	int sa;
	t_minishell	*ms;

	ms->line = NULL;
	char *ma_env = getenv("PATH");
	while (1)
	{
		if(pid > 0)
			ft_readline(ms);
		
		if (!(ft_strncmp(ms->line, "ls", 2)))
		{
			pid = fork(); // Main process and child process
			if (pid == 0) // child process goes in
			{
				char cmd[] = "/bin/ls";
				char *argve[] = {"ls", "-l", NULL};
				execve(cmd, argve, NULL);
				exit(0);
			}
			wait(&sa); //Main process waits for child process to terminate
		}
		if (!(ft_strncmp(ms->line, "pwd", 3)))
		{
			pid = fork(); // Main process and child process
			if (pid == 0) // child process goes in
			{
				char cmd[] = "/bin/pwd";
				char *argve[] = {"pwd", "-L", NULL};
				execve(cmd, argve, NULL);
				exit(0);
			}
			wait(&sa); //Main process waits for child process to terminate
		}	
		
	}
}

int main (int argc, char **argv, char **env) {
   lunch_program(env, argv);	
}	