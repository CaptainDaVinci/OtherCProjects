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

	char lastChar;

	for (char c; (c = getchar()) != EOF;)
	{
		if(c == ' ')
			if(lastChar != ' ' && lastChar != '\t' && lastChar != '\n')
				words++;
		if(c == '\n'){
			lines++;
			if(lastChar != ' ' && lastChar != '\t' && lastChar != '\n')
							words++;
		}
		chars++;
		lastChar = c;
	}

	printf("%i lines \n", lines);
	printf("%i words \n", words);
	printf("%i characters \n" , chars);

	return 0;
}
