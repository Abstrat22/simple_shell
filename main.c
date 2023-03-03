#include "main.h"

/**
 * main - entry point.
 *
 * Description: A simple shell program to execute commands
 * @ac: Argument count
 * @av: Argument vector
 * @env: Environment argument
 * Return: 0 (success)
 */

int main(int ac, char **av, char **env)
{
	char *cmd, **argv, *arg_str, *cm_str;
	int c_count = 0;

	cmdl_arg(ac, c_count, av);
	cmd = get_cmd();
	cm_str = get_cmd_file(cmd);
	arg_str = get_args_str(cmd);
	argv = get_args(arg_str);

	while (strcmp(cmd, "exit") != 0)
	{
		c_count++;

		creat_ps(cm_str, argv, env, c_count);

		if (isatty(STDIN_FILENO) != 1)
			exit(0);
		free(arg_str);
		free(argv);

		cmd = get_cmd();
		cm_str = get_cmd_file(cmd);
		arg_str = get_args_str(cmd);
		argv = get_args(arg_str);
	}
	free(cm_str);
	free(arg_str);
	free(argv);
	return (0);
}
