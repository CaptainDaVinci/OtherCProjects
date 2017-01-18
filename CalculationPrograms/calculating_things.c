/*
 * calculating_things.c
 *
 *  Created on: Sep 20, 2015
 *      Author: Zack Gill
 *  Program will calculate Fibonacci, Integer square root, and floating
 *  point square root of positive integers given by user.
 */



#include <stdio.h>
#include <math.h>


int fib (int current);
int intsqrt(int param);


int main()
{

	int input = 0;

	while(input >= 0)
	{
		printf("Enter i: ");
		scanf("%i", &input);
		if(input < 0){
			printf("quitting\n");
			break;
		}
		printf("F(%i): %i\n", input, fib(input));
		printf("isqrt(%i): %i\n", input, intsqrt(input));
		printf("sqrt(%i): %f\n", input, sqrt(input));
	}

	return 0;
}



/*
 * Function Fib finds the Fibonacci number requested recursively.
 * This results in O (2 ^ n), since we have to go through the recursive process
 * for each value that makes up the numbers before the one we want.
 */
int fib (int current)
{
	if(current <= 0){
		return 0;
	}

	if (current == 1){
		return 1;
	}
	int num = 0;
	num = fib(current-1) + fib(current - 2);

	return num;
}

/*
 * Calculating the int square root takes O(sqrt(n)). Since we loop until we
 * find the square root, we never have to go beyond it, so we only have to do
 * that much work
 */
int intsqrt(int param)
{

	int result = 1;

	for(int i = 1; i < param; i++)
	{
		if ((i*i) <= param)
			result = i;
		if ((i*i) >= param){
			break;
		}
	}

	return result;
}
