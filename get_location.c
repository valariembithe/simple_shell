#include "main.h"

/*
 * *get_location: searches environment list to find specific environment
 * variable passed in the argument
 * Description - searches environment list to find specific environment
 * variable passed in the argument
 * command: name of command
 * Return: filepath name
 */
char *get_location(char *command)
{
	char *path, *pathcopy, *token, *filepath;
	int command_len, dir_length;
	/*stores information of the file pointed in the path */
	struct stat buffer;
	/* searches the env list to find specific variable name passed in argument */
	path = getenv("PATH");
	if (path)
	{
		/* create a copy of path to free up memory */
		pathcopy = strdup(path);
		/* length of command passed */
		command_len = _strlen(command);
		/* break down pathname to get all directories, delim is :  */
		token = strtok(pathcopy, ":");

		while (token != NULL) /* directories available */
		{
			/* length of directory */
			dir_length = _strlen(token);
			/* allocate memory for both command and directory passed */
			/* add 2 for the null character and '/' */
			filepath = malloc(command_len + dir_length + 2);
			/* to build a path, create a copy of directory path and concatenate */
			_strcpy(filepath, token);
			_strcat(filepath, "/");
			_strcat(filepath, command);
			_strcat(filepath, "\0");
			/* check if filepath is not empty and return it */
			if (stat(filepath, &buffer) == 0) /* stores info of file pointed in path */
			{
				/* free allocated memory and return the path */
				free(pathcopy);
				return (filepath);
			}
			else
			{
				/* free filepath memory and check another path */
				free(filepath);
				token = strtok(NULL, ":");
			}
		}
		/* if filepath doesnot exist we free the pathcopy memory */
		free(pathcopy);
		/* check if command is a filepath that exists */
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}

