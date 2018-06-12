/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Contains long flag functions.
*/

#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "my.h"
#include "macro.h"
#include "struct.h"

static void show_rights(struct stat *s)
{
	my_putchar(S_ISDIR(s->st_mode) ? 'd' : '-');
	my_putchar((s->st_mode & S_IRUSR) ? 'r' : '-');
	my_putchar((s->st_mode & S_IWUSR) ? 'w' : '-');
	my_putchar((s->st_mode & S_IXUSR) ? 'x' : '-');
	my_putchar((s->st_mode & S_IRGRP) ? 'r' : '-');
	my_putchar((s->st_mode & S_IWGRP) ? 'w' : '-');
	my_putchar((s->st_mode & S_IXGRP) ? 'x' : '-');
	my_putchar((s->st_mode & S_IROTH) ? 'r' : '-');
	my_putchar((s->st_mode & S_IWOTH) ? 'w' : '-');
	my_putchar((s->st_mode & S_IXOTH) ? 'x' : '-');
}

void show_infos_entry(struct stat *s, int min_widths[2])
{
	struct passwd *pwd = getpwuid(s->st_uid);
	struct group *grp = getgrgid(s->st_gid);

	show_rights(s);
	my_printf(" %*d", min_widths[LINK], s->st_nlink);
	my_printf(" %s ", pwd->pw_name);
	my_printf("%s ", grp->gr_name);
	my_printf("%*d", min_widths[SIZE], s->st_size);
	write(1, ctime(&s->st_mtime) + 3, 13);
	my_putchar(' ');
}

void show_total(entry_t *first_entry)
{
	entry_t *current = first_entry;
	int total = 0;

	while (current != NULL) {
		if (current->name[0] != '.')
			total += current->stats->st_blocks;
		current = current->next;
	}
	my_printf("total %d\n", total / 2);
}

static int int_len(long n)
{
	int dgt = 1;

	for (dgt = 1 ; n >= 10 ; dgt++)
		n /= 10;
	return (dgt);
}

void get_widths(int max_widths[2], entry_t *first_entry)
{
	entry_t *current = first_entry;

	while (current != NULL) {
		if (int_len(current->stats->st_nlink) > max_widths[LINK])
			max_widths[LINK] = int_len(current->stats->st_nlink);
		if (int_len(current->stats->st_size) > max_widths[SIZE])
			max_widths[SIZE] = int_len(current->stats->st_size);
		current = current->next;
	}
}
