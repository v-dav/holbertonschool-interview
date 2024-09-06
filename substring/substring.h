#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int *search_word(char const *s, char const **words, int nb_words);
int check_words(int *aux_idx, int wordlen, int idx_len);
int cmp_values(const void *a, const void *b);
#endif /*SUBSTRING_H*/
