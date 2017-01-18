/*
 * reverse_lines.c
 *
 *  Created on: Sep 19, 2015
 *      Author: Zack Gill
 *
 *  Program reverses input given to it.
 */

#include <stdio.h>
#include <string.h>

char* reverse(char *str);


int main()
{


	for ( char line[132]; fgets(line, sizeof line, stdin) != NULL;){

		printf(reverse(line));
	}

	return 0;

}

char* reverse (char *str)
{

	int l = strlen(str);
	char temp;
	for(int i = 0; i < l/2; i++)
	{
		temp = str[i];
		str[i] = str[l-i-1];
		str[l-i-1] = temp;
	}


	return str;
}

