/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains reverse flag functions.
*/

#include <stdlib.h>
#include <dirent.h>
#include "struct.h"

static void rev_entrys(entry_t **first_entry)
{
	entry_t *previous = NULL;
	entry_t *current = NULL;
	entry_t *next = NULL;

	current = *first_entry;
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*first_entry = previous;
}

void rev_dirs(directory_t **first_dir)
{
	directory_t *previous = NULL;
	directory_t *current = NULL;
	directory_t *next = NULL;

	current = *first_dir;
	while (current != NULL) {
		next = current->next;
		current->next = previous;
		previous = current;
		rev_entrys(&current->first_entry);
		current = next;
	}
	*first_dir = previous;
}
