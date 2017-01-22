/*
 * countChars.c
 *
 *  Created on: Sep 20, 2015
 *      Author: Zack Gill
 *	Program emulates wc
 */


#include <stdio.h>


int main()
{

	int lines = 0;
	int chars = 0;
	int words = 0;

	char c;

	while ((c = getchar()) != EOF)
	{
		chars++;
		if(c == ' ' || c == '\t')
			words++;

		if(c == '\n')
		{
			lines++;
			words++;
		}
	}

	if(lines == 1)
		printf("1 line \n");
	else
		printf("%i lines \n", lines);

	if(words == 1)
		printf("1 word \n");
	else
		printf("%i words \n", words);

	if(chars == 1)
		printf("1 character \n");
	else
		printf("%i characters \n", chars);

}
