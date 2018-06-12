/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Recuparates the flags and directories' names.
*/

#include <dirent.h>
#include "my.h"
#include "struct.h"
#include "const.h"

static int add_flag(char *add, char *flags, int nb_flags)
{
	for (int i = 1 ; add[i] ; i++) {
		if (!in_str(add[i], flags) && in_str(add[i], FLAGS))
			flags[nb_flags++] = add[i];
	}
	return (nb_flags);
}

int analyse_argv(int ac, char **av, char flags[6], char **dir_names)
{
	int nb_flags = 0;
	int nb_dir = 0;

	for (int i = 0 ; i < ac ; i++)
		dir_names[i] = NULL;
	for (int i = 1 ; i < ac ; i++) {
		if (av[i][0] == '-' && in_str(av[i][1], FLAGS))
			nb_flags = add_flag(av[i], flags, nb_flags);
		else
			dir_names[nb_dir++] = my_strdup(av[i]);
	}
	return (nb_dir);
}
