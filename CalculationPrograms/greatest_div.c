/*
 * greatest_div.c
 *
 *  Created on: Sep 24, 2015
 *      Author: Zack Gill
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int denom, numer;
} fraction;

int greatest_div(fraction fract);
void print_fraction(fraction fract);
fraction reduce_fraction(fraction fract);



int main()
{

	fraction input;

	printf("Enter m: ");
	scanf("%i", &input.numer);
	printf("Enter n: ");
	scanf("%i", &input.denom);

	printf("Regular ");
	print_fraction(input);

	printf("Reduced ");
	print_fraction(reduce_fraction(input));
	return 0;
}


void print_fraction(fraction fract)
{
	if(fract.denom == 0)
		printf("Cannot divide by 0\n");
	else
		printf("Fraction:  %i / %i \n", fract.numer, fract.denom);

}

fraction reduce_fraction(fraction fract)
{
	fraction result;
	int div = greatest_div(fract);
	result.denom = fract.denom / div;
	result.numer = fract.numer / div;
	return result;
}

int greatest_div(fraction fract)
{

	for(int i = abs(fract.numer); i > 0; i--)
	{
		if((fract.numer % i) == 0)
			if((fract.denom%i) == 0)
				return i;
	}

	return 1;
}
