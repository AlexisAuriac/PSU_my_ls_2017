/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains functions that creates the directory list.
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"
#include "struct.h"
#include "create_entry.h"
#include "flag_d.h"
#include "flag_R.h"

static entry_t *add_entry(entry_t *last, dirent_t **dirent, directory_t *dir)
{
	entry_t *new_entry = NULL;

	*dirent = readdir(dir->dir);
	if (*dirent != NULL) {
		new_entry = create_entry(dir->name, (*dirent)->d_name);
		last->next = new_entry;
		return (new_entry);
	}
	return (last);
}

static entry_t *get_entries(directory_t *new_dir)
{
	entry_t *first_entry = NULL;
	entry_t *last_entry = NULL;
	dirent_t *dirent = NULL;

	dirent = readdir(new_dir->dir);
	if (dirent != NULL) {
		first_entry = create_entry(new_dir->name, dirent->d_name);
		last_entry = first_entry;
		while (dirent != NULL)
			last_entry = add_entry(last_entry, &dirent, new_dir);
		return (first_entry);
	}
	return (NULL);
}

directory_t *add_dir(directory_t *first, char *name)
{
	directory_t *new_dir = malloc(sizeof(directory_t));

	new_dir->dir = opendir(name);
	if (new_dir->dir != NULL) {
		new_dir->name = my_strdup(name);
		new_dir->first_entry = get_entries(new_dir);
		new_dir->next = first;
		return (new_dir);
	} else {
		free(new_dir);
		my_printf("'%s': No such file or directory\n", name);
		return (first);
	}
}

directory_t *get_dirs(int *nb_dir, char **dir_names, char *flags)
{
	directory_t *first = NULL;

	if (*nb_dir == 0) {
		dir_names[0] = my_strdup(".");
		*nb_dir = 1;
	}
	if (in_str('d', flags))
		first = get_only_dir(*nb_dir, dir_names);
	else {
		for (int i = *nb_dir - 1 ; i >= 0 ; i--)
			first = add_dir(first, dir_names[i]);
	}
	return(first);
}
