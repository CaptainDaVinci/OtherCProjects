/*
 * DynamicArray.c
 *
 *  Created on: Oct 1, 2015
 *      Author: Zack
 */

#include <stdlib.h>

int* dynamicArray(int array[], unsigned int len, unsigned int incr)
{

	int *new;
	new = malloc(sizeof(int)*(len + incr));

	for(int i = 0; i < len; i++)
		new[i] = array[i];

	return new;
}
