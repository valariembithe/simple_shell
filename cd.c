#include "main.h"

/**
 * cd_par - changes to the parent directory
 *
 * @datash: data relevant
 *
 * Return: no return
 */

void cd_par(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = strdup(pwd);
	set_env("OLDPWD", cp_pwd, datash);
	dir = datash->args[1];
	if (strcmp(".", dir) == 0)
	{
	set_env("PWD", cp_pwd, datash);
	free(cp_pwd);
	return;
	}
	if (strcmp("/", cp_pwd) == 0)
	{
	free(cp_pwd);
	return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
	cp_strtok_pwd = strtok(NULL, "\0");

	if (cp_strtok_pwd != NULL)
	rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
	chdir(cp_strtok_pwd);
	set_env("PWD", cp_strtok_pwd, datash);
	}
	else
	{
	chdir("/");
	set_env("PWD", "/", datash);
	}
	datash->status = 0;
	free(cp_pwd);
}
/**
 * cd_in - changes to a directory specified
 * by the user
 *
 * @datash: data relevant
 * Return: no return
 */
void cd_in(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = datash->args[1];
	if (chdir(dir) == -1)
	{
	get_error(datash, 2);
	return;
	}

	cp_pwd = strdup(pwd);
	set_env("OLDPWD", cp_pwd, datash);

	cp_dir = strdup(dir);
	set_env("PWD", cp_dir, datash);

	free(cp_pwd);
	free(cp_dir);

	datash->status = 0;

	chdir(dir);
}
/**
 * cd_prev - changes to the previous directory
 *
 * @datash: data relevant (environ)
 * Return: no return
 */
void cd_prev(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = strdup(pwd);

	p_oldpwd = getenv("OLDPWD");

	if (p_oldpwd == NULL)
	cp_oldpwd = cp_pwd;
	else
	cp_oldpwd = strdup(p_oldpwd);

	setenv("OLDPWD", cp_pwd, 1);

	if (chdir(cp_oldpwd) == -1)
	setenv("PWD", cp_pwd, 1);
	else
	setenv("PWD", cp_oldpwd, 1);

	p_pwd = getenv("PWD");

	write(STDOUT_FILENO, p_pwd, strlen(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
	free(cp_oldpwd);

	datash->status = 0;

	chdir(p_pwd);
}
/**
 * cd_home - changes to home directory
 *
 * @datash: data relevant (environ)
 * Return: no return
 */
void cd_home(data_shell *datash)
	{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = strdup(pwd);

	home = getenv("HOME");

	if (home == NULL)
	{
	setenv("OLDPWD", p_pwd, 1);
	free(p_pwd);
	return;
	}

	if (chdir(home) == -1)
	{
	get_error(datash, 2);
	free(p_pwd);
	return;
	}

	setenv("OLDPWD", p_pwd, 1);
	setenv("PWD", home, 1);
	free(p_pwd);
	datash->status = 0;
}
