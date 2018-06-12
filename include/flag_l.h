/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Flag_l header file.
*/

#ifndef FLAG_L_H
#define FLAG_L_H

void show_infos_entry(struct stat *s, int min_widths[2]);
void show_total(entry_t *first_entry);
void get_widths(int max_widths[2], entry_t *first_entry);

#endif
