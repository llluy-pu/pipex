/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llluy-pu <llluy-pu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:12:19 by llluy-pu          #+#    #+#             */
/*   Updated: 2023/06/10 20:21:58 by llluy-pu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		error_exit("pipex: command not found\n", 127);
	}
}

void	arg_cmd1(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(av[2], env);
}

void	arg_cmd2(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
		error_exit("usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	if (pipe(p_fd) == -1)
		error_exit("pipex: pipe error\n", -1);
	pid = fork();
	if (pid == -1)
		error_exit("pipex: fork error\n", -1);
	if (!pid)
		arg_cmd1(av, p_fd, env);
	arg_cmd2(av, p_fd, env);
}
