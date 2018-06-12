/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Inserts a list of directories into another list of directories.
*/

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include "my.h"
#include "struct.h"

static directory_t *get_last(directory_t *first)
{
	if (first == NULL)
		return (NULL);
	while (first->next != NULL)
		first = first->next;
	return (first);
}

void insert_list(directory_t *dir, directory_t *other_first)
{
	directory_t *next = dir->next;
	directory_t *other_last = get_last(other_first);

	if (dir != NULL && other_first != NULL) {
		next = dir->next;
		dir->next = other_first;
		other_last->next = next;
	}
}
