/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains directory flag functions.
*/

#include <dirent.h>
#include "my.h"
#include "struct.h"
#include "create_entry.h"

static entry_t *add_entry_first(entry_t *first, char *name)
{
	entry_t *new_entry = create_entry(NULL, name);

	new_entry->next = first;
	return (new_entry);
}

directory_t *get_only_dir(int nb_dir, char **names)
{
	directory_t *dir = malloc(sizeof(directory_t));

	dir->name = my_strdup("directories");
	dir->dir = NULL;
	dir->next = NULL;
	dir->first_entry = NULL;
	for (int i = nb_dir - 1 ; i >= 0 ; i--)
		dir->first_entry = add_entry_first(dir->first_entry, names[i]);
	return (dir);
}
