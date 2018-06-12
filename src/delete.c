/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains functions that deletes the directory list.
*/

#include <stdlib.h>
#include <dirent.h>
#include "struct.h"

static void delete_entries(entry_t *first_entry)
{
	entry_t *current = first_entry;
	entry_t *to_delete = NULL;

	while (current != NULL) {
		to_delete = current;
		current = current->next;
		free(to_delete->name);
		free(to_delete->stats);
		free(to_delete);
	}
}

static void delete_dirs(directory_t *first_dir)
{
	directory_t *current = first_dir;
	directory_t *to_delete = NULL;

	while (current != NULL) {
		to_delete = current;
		current = current->next;
		free(to_delete->name);
		delete_entries(to_delete->first_entry);
		closedir(to_delete->dir);
		free(to_delete);
	}
}

void delete_all(directory_t *first_dir, char **dir_names)
{
	delete_dirs(first_dir);
	for (int i = 0 ; dir_names[i] ; i++)
		free(dir_names[i]);
	free(dir_names);
}
