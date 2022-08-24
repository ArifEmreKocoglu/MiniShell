/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:13:28 by akocoglu          #+#    #+#             */
/*   Updated: 2022/08/24 18:09:09 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <editline/readline.h>
#include <signal.h>
#include <sys/wait.h>

#include "./libft/libft.h"

typedef struct s_minishell
{
    char *line;    
} t_minishell;
