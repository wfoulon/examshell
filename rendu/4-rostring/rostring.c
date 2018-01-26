#include <unistd.h> // for write
#include <stdlib.h> // for malloc, free


/* In this version:
*
*  - Count words so we don't run into trouble with trailing whitespace.
*  - Allocate space for first word.
*  - Print other words (with only one space in between).
*  - Print the first word.
*  - Profit
* 
*/

int		is_space(char *str, int i) // see if we can use pointer arithmetic to advance str
{
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		return (1);
	else
		return (0);
}

void	nl()
{
	write(1, "\n", 1);
}



int		count_words(char *str) // count number of words in original string
{
	int words; // word counter
	int i; // generic counter to traverse string

	words = 1; // if we've gotten this far, we have at least one word
	i = 0; 

	if (str[0] == ' ' || str[0] == '\t') // move past leading whitespace
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}

	while (str[i+1] && str) // count words
	{		
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' ' && str[i + 1])
		{
			words++;
		}
		i++;
	}
	return (words);
}


void	ft_rostring(char *str)
{
	int i;
	int j; //for printable letters.
	int k; //to make sure we don't print beyond the number of words
	char *first_word;
	int first_word_len;
	int flag; // flag signalling more than one word found.
	int words;

	i = 0;
	j = 0;
	k = 0;
	first_word_len = 0;
	flag = 0;
	words = count_words(str);

	// 1. remove leading whitespace.
	if (is_space(str, i))
	{
		while (is_space(str, i))
			i++;
	}
	str += i;
	i = 0;

	// 2. Get length of first word.
	while (!is_space(str, first_word_len))
	{
		first_word_len++;
	}

	// 3. Allocate memory for first word and save it.

	first_word = (char *)malloc(sizeof(char) * first_word_len + 1);
	first_word[first_word_len] = '\0';

	while (!is_space(str, i))
	{

		first_word[i] = str[i];
		i++;
	}
	str += i;
	i = 0;

	// 4. Traverse string, starting to print whenever the char after a space is a printable char.

	while (*(str + i))
	{
		if (is_space(str, i) && str[i] && k < words - 1)
		{
			j = 0;
			if (i)
				write(1, " ", 1);
			while (is_space(str, i + j) && str[i + j])
			{
				j++;
			}
			i += j;
			k++;
		}
		if (!is_space(str, i))
		{
			flag = 1;
			write (1, &str[i], 1);
		}
		i++;
	}	

	// 5. Print (saved) first word.
	j = 0;
	if (flag)
		write(1, " ", 1);
	while (j < first_word_len)
	{
		write(1, &first_word[j], 1);
		j++;
	}
	free (first_word);
	return ;
}



int		main(int ac, char **av)
{
	if (ac != 2)
	{
		nl();
		return (0); // exit if wrong number of args
	}

	ft_rostring(av[1]);
	nl();
	return (0);

}