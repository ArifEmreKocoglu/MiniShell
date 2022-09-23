/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:13:48 by akocoglu          #+#    #+#             */
/*   Updated: 2022/09/23 17:25:46 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
size_t	ft_count_words(const char *s, char c)
{
	char	pre_c;
	size_t	i;

	i = 0;
	pre_c = c;
	while (*s)
	{
		if (pre_c == c && *s != c)
			i++;
		pre_c = *s;
		s++;
	}
	return (i);
}

char *echo_utility(t_minishell minishell)
{
    int i;
    char *str;

    i = 1;
    while (i <= minishell.word_count)
    {
        if(!(i == minishell.word_count))
            minishell.commands[i] = ft_strjoin(minishell.commands[i]," ");
        str = ft_strjoin(str,minishell.commands[i]);
        i++;
    }
    return str;
}

void envoirement(t_minishell minishell)
{
    int status;
    int pid;
    if ((!ft_strncmp(minishell.line, "ls", 2)))
    {
        pid = fork();
        if(pid == 0)
        {
            char cmd[] = "/bin/ls";
            char *argve[] = {"ls", "-l", NULL};
            execve(cmd, argve, NULL);
            exit(0);
        }
        wait(&status);
    }
    if ((!ft_strncmp(minishell.line, "pwd", 3)))
    {
        pid = fork();
        if(pid == 0)
        {
            char cmd[] = "/bin/pwd";
            char *argve[] = {"pwd", "-L", NULL};
            execve(cmd, argve, NULL);
            exit(0);
        }
        wait(&status);
    }
     if ((!ft_strncmp(minishell.line, "echo", 4)))
    {
        pid = fork();
        if(pid == 0)
        {
            char cmd[] = "/bin/echo";
            char *argve[] = {"echo", echo_utility(minishell), NULL};
            execve(cmd, argve, NULL);
            
            exit(0);
        }
        wait(&status);
    }

	 if ((!ft_strncmp(minishell.line, "mkdir", 5)))
    {
        int pid2;
        pid = fork();
        if(pid == 0)
        {
            int i;
            i = 1;
            while(i < minishell.word_count)
            {
                pid2 = fork();
                if(pid2 == 0)
                {
                    char cmd[] = "/bin/mkdir";
                    char *argve[] = {"mkdir", minishell.commands[i], NULL}; // TIRNAK İŞARETİNİ UNUTMAAAAAAAAAAAAAA!!!!!!!!!!!!!!!!!
                    execve(cmd, argve, NULL);
                    exit(0);
                }
                wait(&status);  
                i++;          
            }
            exit(0);
        }
        wait(&status);
    }

     if ((!ft_strncmp(minishell.line, "cat", 3)))
    {
        int pid2;
        pid = fork();
        if(pid == 0)
        {
            int i;
            i = 1;
            while(i < minishell.word_count)
            {
                pid2 = fork();
                if(pid2 == 0)
                {
                    char cmd[] = "/bin/cat";
                    char *argve[] = {"cat", minishell.commands[i], NULL};
                    execve(cmd, argve, NULL);
                    exit(0);
                }
                wait(&status);  
                i++;          
            }
            exit(0);
        }
        wait(&status);
    }
}

int main(int argc, char *argv[], char **envp)
{
    t_minishell minishell;
    int i;
    int j;
    char *pwd;

    i = 0;
    j = 0;
    int sa;
    int pid;

    pwd = getenv("PWD");
    char *env = getenv("PATH");
    minishell.program_name = "$minishell-> % ";
    char old_path[256];
    char *status;
    status = getcwd(old_path, sizeof(old_path));
    printf("SA: %s\n", old_path);
    while (1)
    {
        minishell.line = readline(ft_strjoin(minishell.program_name, ""));
        minishell.commands = ft_split(minishell.line, ' ');
        if (!(ft_strncmp(minishell.commands[0], "cd", 2)) &&  !(ft_strncmp(minishell.commands[1], "..", 2)))
        {
            pid = fork();
            if(pid == 0)
            {
                printf("%s \n", pwd);
                exit(0);   
            }
            wait(&sa);
        }
        minishell.word_count = ft_count_words(minishell.line, ' ');
        add_history(minishell.line);
        envoirement(minishell);

    }
    return 0;
}