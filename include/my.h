/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by libmy.a.
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define ABS(value) (((value > 0) ? (value) : (-value)))

typedef struct format_id {
	int legit;
	int length;
	char flags[6];
	int nb_flag;
	int min_width;
	int precision;
	char type;
}format_id_t;

void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_in_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char const *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalise(char *str);
int my_strisalpha(char const *str);
int my_isalpha(char c);
int my_strisnum(char const *str);
int my_strislower(char const *str);
int my_strisupper(char const *str);
int my_strisprintable(char const *str);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *str);
void *my_malloc(int size);
void *my_realloc(char *str, int const size);
char *my_revstr(char *str);
void put_strpart(char *str, int start, int finish);
void incr10_str(char *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
int my_str_isnum(char const *str);
int my_rec_str_isprintable(char const *str, int i);
int isalph(char c);
char **my_str_to_word_array(char *str);
int my_show_word_array(char * const *tab);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char int_char(int const n);
int find_power_10(long n);
char *int_str(long nb);
char *put_nbr_to_base(long nbr, char const *base);
char *put_precision(char *cat, format_id_t const *fid, va_list ap);
int display_fid(format_id_t *fid, va_list ap, int *bytes);
format_id_t *get_format_id(char const *str, int pos);
format_id_t *init_format_id(void);
int in_str(char const c, char const *str);
int my_printf(char *str, ...);
char *my_push_back(char *str, char const cat);
char *my_pushstr_back(char *str, char const *cat);
char *my_insert_char(char *str, char const cat, int const pos);
char *my_insert_str(char *str, char const *cat, int const pos);
char *put_var_nbr(char *str, format_id_t const *fid, va_list ap);

#endif
