/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Creates an entry.
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my.h"
#include "struct.h"

char *get_path(char *dir_name, char *file_name)
{
	char *path = my_strdup(dir_name);
	int len = my_strlen(path);

	if (len != 0 && path[len - 1] != '/')
		path = my_push_back(path, '/');
	path = my_pushstr_back(path, file_name);
	return (path);
}

entry_t *create_entry(char *dir_name, char *name)
{
	entry_t *new_entry = malloc(sizeof(entry_t));
	char *path = get_path(dir_name, name);

	new_entry->name = my_strdup(name);
	new_entry->stats = malloc(sizeof(struct stat));
	stat(path, new_entry->stats);
	new_entry->next = NULL;
	free(path);
	return (new_entry);
}
