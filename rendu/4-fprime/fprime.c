#include <stdio.h> // printf is allowed, okay...


/*
* Uses, um, logic to find all the prime factors of an int.
*/



int		ft_atoi(char *str) // atoi is allowed, but let's write our own
{
	int nbr;
	int neg;

	nbr = 0;
	neg = 1;

	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && str)
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * neg);
}



int		ft_isprime(int nbr) // test if we have a prime number
{
	int ret; // return 1 if prime (default), 0 if not
	int div; // divisor
	ret = 1;
	div = 2; // because we don't care if nbr is divisible by 0 or 1

	while(div < nbr)
	{
		if (nbr % div == 0) // if nbr is divisible by anything other than 1/itself
		{
			ret = 0;        // ...then nbr isn't prime
			return(ret);
		}

		div++; // this will check all possible factors up to size of int.
			   // this might not be the most efficient.
	}
	return (ret);
}



void	ft_fprime(char *number)
{
	int n;   // argument
	int div; // divisor

	div = 2; // we don't care if we can divide by 0 or 1
	n = ft_atoi(number);

	if (n == 1 || n == 2 || n == 3) // lo-hanging fruit
	{
		printf("%d\n", n);
		return ;
	}
	else if (ft_isprime(n)) // low-hanging fruit
	{
		printf("%d\n",n);
		return ;
	}
	else // if number isn't prime...
		while (n > 0 && div < n)
		{
			while (n % div == 0 && n > 0)
			// check for factors
			{
				printf("%d",div);
				if (ft_isprime(n / div)) // last factor found is also prime!
				{
					printf("*%d\n",n / div);
					return ;  // exit accordingly
				}
				else
					printf("*");
				n /= div; // divide n by factor each time we find a factor
			}
			div++; // check for the next largest factor
	}
return ;
}



int		main(int ac, char **av) // **if params not one, newline
{
	if (ac != 2)
	{
		printf("\n");
		return(0);
	}

	ft_fprime(av[1]);

/*
*	examples from subject file:
*
*	ft_fprime("225225");
*	
*	ft_fprime("8333325");
*	
*	ft_fprime("9539");
*	
*	ft_fprime("804577");
*		
*	ft_fprime("42");
*	
*	ft_fprime("0");
*	
*	ft_fprime("1");
*		
*	ft_fprime("2");
*/
	return (0);



}