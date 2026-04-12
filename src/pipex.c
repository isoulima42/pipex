/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isoulima <soulimani.ilir@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:33:51 by isoulima          #+#    #+#             */
/*   Updated: 2026/04/12 19:34:16 by isoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		free_tab(args);
		ft_putstr_fd("pipex: command not found\n", 2);
		exit(127);
	}
	path = get_cmd_path(args[0], env);
	if (!path)
	{
		perror(args[0]);
		free_tab(args);
		exit(127);
	}
	execve(path, args, env);
	perror(args[0]);
	free(path);
	free_tab(args);
	exit(1);
}

void	child_one(t_pipex *p, char *cmd, char **env)
{
	dup2(p->fd_in, STDIN_FILENO);
	dup2(p->pipe_fd[1], STDOUT_FILENO);
	close(p->fd_in);
	close(p->fd_out);
	close(p->pipe_fd[0]);
	close(p->pipe_fd[1]);
	execute(cmd, env);
}

void	child_two(t_pipex *p, char *cmd, char **env)
{
	dup2(p->pipe_fd[0], STDIN_FILENO);
	dup2(p->fd_out, STDOUT_FILENO);
	close(p->fd_in);
	close(p->fd_out);
	close(p->pipe_fd[0]);
	close(p->pipe_fd[1]);
	execute(cmd, env);
}

int	run_children(t_pipex *p, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork");
	if (pid1 == 0)
		child_one(p, av[2], env);
	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork");
	if (pid2 == 0)
		child_two(p, av[3], env);
	close(p->pipe_fd[0]);
	close(p->pipe_fd[1]);
	close(p->fd_in);
	close(p->fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}

int	pipex(char **av, char **env)
{
	t_pipex	p;

	p.fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p.fd_out < 0)
		error_exit(av[4]);
	p.fd_in = open(av[1], O_RDONLY);
	if (p.fd_in < 0)
	{
		perror(av[1]);
		p.fd_in = open("/dev/null", O_RDONLY);
	}
	if (pipe(p.pipe_fd) < 0)
	{
		close(p.fd_in);
		close(p.fd_out);
		error_exit("pipe");
	}
	return (run_children(&p, av, env));
}
