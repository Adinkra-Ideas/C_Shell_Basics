#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int g_fd;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[(i)] != '\0')
		i++;
	return (i);
}

static int	print(char *string)
{
	int	length = 0;

	while (string && string[length])
		length++;
	if (string)
		write(2, string, length);
	return (1);
}

static int	executor(char **argv, int i, char **env)
{
	int	status;
	int	fd[2];
	int	pid;
	int	is_piped = 0;

	if ( argv[i] && strcmp(argv[i], "|") == 0 )
		is_piped = 1;
	if ( pipe(fd) == -1 )
		return (print("error: fatal\n\0"));
	pid = fork();
	if ( pid == -1 )
		return (print("error: fatal\n\0"));
	else if ( pid == 0 )
	{
		// close read end of the current opened pipe
		close(fd[0]);

		// redirect stdin to read end of previous pipe stored in global. or do nothing if global is 0
		dup2(g_fd, 0); 
		argv[i] = NULL;

		// If piping required, redirect stdout to write end of current opened pipe
		if ( is_piped )
			dup2(fd[1], 1);
		if ( execve(*argv, argv, env) == -1 )
		{
			if ( ft_strlen(*argv) > 0 )
			{
				print("error: cannot execute \0");
				print(*argv);
				print("\n\0");
			}
			close(fd[1]);
			exit(0);
		}
	}
	else
	{
		close(fd[1]);
		waitpid(pid, &status, 0);
		if (g_fd != 0)
			close(g_fd);
		if (is_piped)
			g_fd = dup(fd[0]);
		close(fd[0]);
	}
	return (0);
}

static int	builtin_cd(char **argv)
{
	if ( argv[2] && strcmp(argv[2], "|") && strcmp(argv[2], ";") )
		return (print("error: cd: bad arguments\n\0"));
	if ( chdir(argv[1]) == -1 )
		return ((print("error: cd: cannot change directory to \0"), print(argv[1]), print("\n\0")) );
	return (0);
}

int main(int argc, char *argv[], char *env[])
{
	int	i = 1;
	if (argc < 2)
		return (0);
	argv[argc] = NULL;
	while (argv[i - 1] && argv[i])
	{
		argv += i;
		i = 0;

		// loop stops when argv[i] meets | or ; full string
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if ( !strcmp(*argv, "cd") )
			builtin_cd(argv);	
		else
			executor(argv, i, env); // i == number of args (including cmd) before |, ; or NULL
		i++; // because we need to skip through all the used args before shifting argv to next i index in next iteration
	}
	
	if ( g_fd != 0 )
			close(g_fd);

	return (0);
}
