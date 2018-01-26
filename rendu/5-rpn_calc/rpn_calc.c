# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// 5-1-rpn_calc : Beginner C Exam @ 42

static int		is_digit(char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	return (0);
}

static int		is_neg_int(char c, char *s)
{
	if (c == '-')
	{
		if (*(s + 1) && is_digit(*(s + 1)))
			return (1);
		return (0);
	}
	return (0);
}

static int		push(int n, int *tab, int *t)
{
	tab[*t] = n;
	(*t)++;
	return (1);
}

static int		get_int(char *s, int *i) // For storing ints as we parse av[1]
{
	int ret;

	ret = 0;
	*i = 0;
	if (!*s)
		return (0);
	if (is_digit(*s))
	{
		ret = *s - '0';
		s++;
		while (*s && is_digit(*s)) 
		{
			ret *= 10;
			ret += *s - '0';
			s++;
			(*i)++;
		}
	}
	return (ret);
}			

static int		get_neg_int(char *s, int *i) // Slightly different procedure for negative numbers, bit redundant
{
	int ret;

	ret = 0;
	*i = 0;
	s++;
	(*i)++;
	if (is_digit(*s))
	{
		ret = *s - '0';
		s++;
		while (*s && is_digit(*s)) 
		{
			ret *= 10;
			ret += *s - '0';
			s++;
			(*i)++;
		}
	}

	return (ret * -1);
}

static int		is_op(char s) // If char is an operand, return identifying int (bit redundant)
{
	int ret = 0;
	if (s == '+')
		ret = 1;
	else if (s == '-')
		ret = 2;
	else if (s == '*')
		ret = 3;
	else if (s == '/')
		ret = 4;
	else if (s == '%')
		ret = 5;
	return (ret);
}

static int		do_math(char op, int *tab, int *t)	// Depending on operand, perform corresponding operations
{
	int res;
	res = 0;
	(*t)--;
	if (op == 1)
		res = tab[*t - 1] + tab[*t];
	else if (op ==2)
		res = tab[*t - 1] - tab[*t];
	else if (op == 3)
		res = tab[*t - 1] * tab[*t];
	else if (op == 4 || op == 5)
	{
		if (tab[*t] != 0)
		{
			if (op == 4)
				res = tab[*t - 1] / tab[*t];
			else if (op == 5)
				res = tab[*t - 1] % tab[*t];
		}
		else
			return (0);
	}
	(*t)--;
	tab[*t] = res;
	(*t)++;
	return (1);
}



static int		calc(char *s, int *err)
{
	int tab[10000];
	int t = 0;
	int i = 0;

	while (*s)
	{
		if (is_neg_int(*s, s))
		{
			get_neg_int(s, &i);
			push(get_neg_int(s, &i), tab, &t);
			s += i;
			s++;
		}
		else if (is_digit(*s))
		{
			push(get_int(s, &i), tab, &t);
			s += i;
			s++;
		}
		else if (is_op(*s))
		{
			if (t < 2)
			{
				*err = 1;
				return(0);
			}
			if (!(do_math(is_op(*s), tab, &t)))
			{
				*err = 1;
				return(0);
			}
			s++;
		}
		if (*s)
		{
			if (*s != ' ')
			{
				*err = 1;
				return (0);
			}
		}
		if (*s)
		{
			if (*s != ' ' && (!(*s >= '0' && *s <= '9')) && !(is_op(*s)))
			{
				*err = 1;
				return (0);
			}
			s++;
		}
	}
	if (t != 1)
	{
		*err = 1;
		return (0);
	}
	return (tab[0]);
}



int		main(int ac, char **av)
{
	int err = 0;
	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return(0);
	}
	calc(av[1], &err);
	if (!err)
		printf("%d\n", calc(av[1], &err));
	else
		printf("Error\n");
	return (0);
}
