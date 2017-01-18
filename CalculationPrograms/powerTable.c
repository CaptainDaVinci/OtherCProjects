/*
 * powerTable.c
 *
 *  Created on: Sep 19, 2015
 *      Author: Zack Gill
 *
 *  Program outputs a neatly formmated table of powers up to int 20
 */


#include <stdio.h>

int main()
{

	printf("::::: \t A TABLE OF POWERS \t :::::\n");

	printf("\nInteger \t Square \t 3rd power \t 4th power \t 5th power\n");

	printf("------- \t ------ \t --------- \t --------- \t ---------\n");

	int power;
	int current_num;
	int total = 0;
	int space = 0;

	for(current_num = 1; current_num < 21; current_num++)
	{
		total = current_num;
		for(power = 1; power < 6; power++)
		{


			switch (power) {
				case 1:
					space = 7;
					break;
				case 2:
					space = 15;
					break;
				case 3:
					space = 18;
					break;
				case 4:
					space = 10;
					break;
				case 5:
					space = 10;
			}


			printf("%*i\t", space, total);
			total *= current_num;
		}
		printf("\n");
	}

	return 0;



}
