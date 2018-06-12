/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains functions that shows the directory list.
*/

#include <sys/stat.h>
#include <dirent.h>
#include "my.h"
#include "macro.h"
#include "struct.h"
#include "flag_r.h"
#include "flag_l.h"
#include "flag_t.h"

static void show_entries(entry_t *first_entry, const char *flags, int min_widths[2])
{
	entry_t *current = first_entry;

	while (current != NULL) {
		if (current->name[0] != '.' || in_str('d', flags)) {
			if (in_str('l', flags))
				show_infos_entry(current->stats, min_widths);
			my_printf("%s\n", current->name);
		}
		current = current->next;
	}
}

static void show_dirs(const directory_t *first_dir,
		      const char *flags)
{
	const directory_t *current = first_dir;
	int shown_dir = 0;
	int min_widths[2] = {0};

	while (current != NULL) {
		shown_dir++;
		if (!(shown_dir == 1 && current->next == NULL)) {
			if (in_str('R', flags))
				my_printf("%s:\n", current->name);
		}
		if (in_str('l', flags)) {
			get_widths(min_widths, first_dir->first_entry);
			show_total(current->first_entry);
		}
		show_entries(current->first_entry, flags, min_widths);
		current = current->next;
		if (current != NULL)
			my_putchar('\n');
	}
}

void apply_flags(directory_t **first_dir, char *flags)
{
	if (in_str('t', flags))
		sort_dirs_by_time(first_dir);
	if (in_str('r', flags))
		rev_dirs(first_dir);
	show_dirs(*first_dir, flags);
}
