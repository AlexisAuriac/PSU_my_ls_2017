/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Get_directories header file.
*/

#ifndef GET_DIRS
#define GET_DIRS

directory_t *add_dir(directory_t *first, char *name);
directory_t *get_dirs(int *nb_dir, char **dir_names, char *flags);

#endif
