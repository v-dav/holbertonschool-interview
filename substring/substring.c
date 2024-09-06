#include "substring.h"

/**
 * find_substring - finds all the possible substrings containing a list of
 * words, within a given string
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of elements
 * @n: address
 * Return: array or NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *idx, *aux_idx, wordlen, j, diff, s_len, f_idx, tmp;

	*n = 0;
	wordlen = (int)strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		aux_idx = search_word(s, words, nb_words);
		if (!aux_idx)
			break;
		qsort(aux_idx, nb_words, sizeof(int), cmp_values);
		f_idx = check_words(aux_idx, wordlen, nb_words);
		tmp = aux_idx[nb_words - 1];
		free(aux_idx);
		if (f_idx == 1)
		{
			diff = s_len - tmp;
			if (*n == 0 || diff != idx[*n - 1])
			{
				if (*n == 0)
				{
					idx = malloc((sizeof(int)));
					if (!idx)
						return (NULL);
				}
				else
					idx = realloc(idx, sizeof(int) * (*n + 1));
				idx[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	if (*n == 0)
		return (NULL);
	return (idx);
}

/**
 * search_word - ...
 *
 * @s: ...
 * @words: ...
 * @nb_words: ...
 * Return: ...
 */
int *search_word(char const *s, char const **words, int nb_words)
{
	int *aux_idx, i, j;
	char *aux;
	int len;

	aux_idx = malloc((sizeof(int) * nb_words));
	if (!aux_idx)
		return (NULL);
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
		{
			free(aux_idx);
			return (NULL);
		}
		len = (int)strlen(aux);
		for (j = 0; j < i; j++)
		{
			if (len == aux_idx[j])
			{
				aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
				if (!aux)
				{
					free(aux_idx);
					return (NULL);
				}
				len = (int)strlen(aux);
				aux_idx[i] = len;
				continue;
			}
		}
		aux_idx[i] = len;
	}
	return (aux_idx);
}

/**
 * check_words - ...
 *
 * @aux_idx: ...
 * @wordlen: ...
 * @idx_len: ...
 * Return: ...
 */
int check_words(int *aux_idx, int wordlen, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_idx[i + 1] - aux_idx[i] != wordlen)
			return (0);
	}
	return (1);
}

/**
 * cmp_values - ...
 *
 * @a: ...
 * @b: ...
 * Return: ...
 */
int cmp_values(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
