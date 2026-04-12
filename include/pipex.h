/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoulima <soulimani.ilir@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:47:22 by isoulima          #+#    #+#             */
/*   Updated: 2026/04/12 19:34:11 by isoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	int	fd_in;
	int	fd_out;
	int	pipe_fd[2];
}	t_pipex;

/* main.c */
void	free_tab(char **tab);
void	error_exit(char *msg);

/* path.c */
char	*get_env_path(char **env);
char	*try_paths(char **paths, char *cmd);
char	*get_cmd_path(char *cmd, char **env);

/* pipex.c */
void	execute(char *cmd, char **env);
void	child_one(t_pipex *p, char *cmd, char **env);
void	child_two(t_pipex *p, char *cmd, char **env);
int		run_children(t_pipex *p, char **av, char **env);
int		pipex(char **av, char **env);

#endif
