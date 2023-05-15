#include "main.h"

int main(int ac, char **argv)
{
	char *prompt = "shell:$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t executable;
	const char *delim = " \n"; /* space and new line character */
	char *lineptr_copy = NULL;
	char *token;
	int len_token = 0;
	int i;

	/* declare void/unused variables */
	(void)ac;
	/* infinite loop in shell */
	while (1)
	{
		printf("%s", prompt);
		charsread = getline(&lineptr, &n, stdin);
		/* check if getline function reaches EOF/ CTRL + D */
		if (executable == -1)
		{
			printf("Exit shell\n");
			return (-1);
		}
	
		lineptr_copy = malloc(sizeof(char) * charsread);
        	if (lineptr_copy == NULL)
        	{
                	perror("memory allocation failed");
                	return (-1);
        	}
        	strcpy(lineptr_copy, lineptr);
        	/* split string lineptr into array of strings */
        	token = strtok(lineptr, delim);
		/* number of tokens */
		while (token != NULL)
		{
			len_token++;
			token = strtok(NULL, delim);
		}
		len_token++;
		argv = malloc(sizeof(char *) * len_token);
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		/* execute command typed */
		execommand(argv);
	}
	/* printf("%s\n", lineptr); */
	/* free allocated memory */
	free(lineptr);
	free(lineptr_copy);

	return (0);
}

