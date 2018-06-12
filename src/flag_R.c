/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains recursive flag functions.
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "my.h"
#include "struct.h"
#include "get_dirs.h"
#include "create_entry.h"
#include "insert_dir_list.h"

static char **dirs_in_entries(entry_t *first, char *path, int nb_dir)
{
	int i = 0;
	char **dir_names = malloc(sizeof(char *) * nb_dir);

	for (i = 0 ; i < nb_dir ; i++)
		dir_names[i] = NULL;
	i = 0;
	while (first != NULL) {
		if (S_ISDIR(first->stats->st_mode) && first->name[0] != '.') {
			dir_names[i] = get_path(path, first->name);
			i++;
		}
		first = first->next;
	}
	return (dir_names);
}

static int get_nb_dir(entry_t *first)
{
	int nb_dir = 0;

	while (first != NULL) {
		if (S_ISDIR(first->stats->st_mode) && first->name[0] != '.')
			nb_dir++;
		first = first->next;
	}
	return (nb_dir);
}

static directory_t *simple_get_dirs(int nb_dir, char **dir_names)
{
	directory_t *first = NULL;

	for (int i = nb_dir - 1 ; i >= 0 ; i--)
		first = add_dir(first, dir_names[i]);
	return (first);
}

void get_dir_rec(directory_t *first_dir)
{
	int i = 0;
	int nb_dir = 0;
	char **dir_names = NULL;
	entry_t *entry = NULL;
	directory_t *rec_dirs = NULL;

	while (first_dir != NULL) {
		nb_dir = get_nb_dir(first_dir->first_entry);
		entry = first_dir->first_entry;
		dir_names = dirs_in_entries(entry, first_dir->name, nb_dir);
		rec_dirs = simple_get_dirs(nb_dir, dir_names);
		insert_list(first_dir, rec_dirs);
		first_dir = first_dir->next;
		i++;
		for (int i = 0 ; i < nb_dir ; i++)
			free(dir_names[i]);
		free(dir_names);
	}
}
