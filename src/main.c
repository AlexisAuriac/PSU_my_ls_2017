/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Main file.
*/

#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "struct.h"
#include "get_dirs.h"
#include "delete.h"
#include "show_dirs.h"
#include "analyse_argv.h"
#include "flag_R.h"

int main(int ac, char **av)
{
	char **dir_names = malloc(sizeof(char *) * ac);
	char flags[6] = "";
	int nb_dir = analyse_argv(ac, av, flags, dir_names);
	directory_t *first_dir = get_dirs(&nb_dir, dir_names, flags);

	if (in_str('R', flags))
		get_dir_rec(first_dir);
	apply_flags(&first_dir, flags);
	delete_all(first_dir, dir_names);
}
