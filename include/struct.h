/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct dirent dirent_t;

typedef struct entry {
	char *name;
	struct stat *stats;
	struct entry *next;
}entry_t;

typedef	struct directory {
	char *name;
	DIR *dir;
	struct directory *next;
	entry_t *first_entry;
}directory_t;

#endif
