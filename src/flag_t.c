/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains time flag functions.
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include "struct.h"

static int cmp_time(struct timespec a, struct timespec b)
{
	if (a.tv_sec == b.tv_sec)
		return (a.tv_nsec > b.tv_nsec);
	else
		return (a.tv_sec > b.tv_sec);
}

static void move(void **previous, void **current, void *next)
{
	*previous = *current;
	*current = next;
}

void sort_entries_by_time(entry_t **first_entry)
{
	entry_t *previous = NULL;
	entry_t *current = *first_entry;
	entry_t *next = NULL;

	if (current != NULL)
		next = current->next;
	while (next != NULL) {
		if (cmp_time(next->stats->st_mtim, current->stats->st_mtim)) {
			current->next = next->next;
			next->next = current;
			if (previous != NULL)
				previous->next = next;
			else
				*first_entry = next;
			previous = NULL;
			current = *first_entry;
			next = current->next;
		} else {
			move((void *) &previous, (void *) &current, next);
			next = next->next;
		}
	}
}

static int older_than(directory_t *dir1, directory_t *dir2)
{
	struct stat stat1;
	struct stat stat2;

	stat(dir1->name, &stat1);
	stat(dir2->name, &stat2);
	if (cmp_time(stat1.st_mtim, stat2.st_mtim))
		return (1);
	else
		return (0);
}

void sort_dirs_by_time(directory_t **first_dir)
{
	directory_t *previous = NULL;
	directory_t *current = *first_dir;
	directory_t *next = NULL;

	if (current != NULL) {
		next = current->next;
		sort_entries_by_time(&current->first_entry);
	}
	while (next != NULL) {
		if (older_than(next, current)) {
			current->next = next->next;
			next->next = current;
			if (previous != NULL)
				previous->next = next;
			else
				*first_dir = next;
			previous = NULL;
			current = *first_dir;
			next = current->next;
		} else {
			move((void *) &previous, (void *) &current, next);
			next = next->next;
		}
		sort_entries_by_time(&current->first_entry);
	}
}
