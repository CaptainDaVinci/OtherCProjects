/*
 * DVD_Collection.c
 *
 *  Created on: Oct 2, 2015
 *      Author: Zack
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct{
	int minutes;
	float price;
	char title[256];
} DVD;


void displayDVD(DVD *input, int amount);
void softWrap(char *title);
int compareTitle(const void * input1, const void * input2);
int compareMinutes(const void * input1, const void * input2);
int comparePrice(const void * input1, const void * input2);

int main()
{

	int option;

	DVD collection[10] = {{117, 9.99, "Back to the Future"}, {176, 9.99, "Indiana Jones and the Raiders of the Lost Ark"},
			{82, 6.99, "Army of Darkness"}, {85, 6.99, "Evil Dead 2"},
			{178, 4.00, "The Lord of the Rings: Fellowship of the Ring"},
			{121, 15.00, "Star Wars, Episode IV: A New Hope"},
			{169, 11.99, "The Hobbit: An Unexpected Journey"},
			{106, 9.58, "High Plains Drifter"},
			{99, 6.26, "A Fistful of Dollars"},
			{90, 19.99, "Heavy Metal"}
	};

	printf("1. Show my collection\n");
	printf("2. Sort by Duration\n");
	printf("3. Sort by price\n");
	printf("4. Sort by title\n");

	scanf("%d", &option);

	switch(option)
	{
				// Display all DVDs.
		case 1:	displayDVD(collection, 10);
					break;

				// sort by duration.
		case 2: qsort(collection, 10, sizeof(DVD), compareMinutes);
				displayDVD(collection, 10);
				break;

				// sort by price.
		case 3: qsort(collection, 10, sizeof(DVD), comparePrice);
				displayDVD(collection, 10);
				break;

				// sort by title.
		case 4: qsort(collection, 10, sizeof(DVD), compareTitle);
				displayDVD(collection, 10);
				break;

	}


	// printf("%s\n", collection[2].title);
	// printf("%i\n", collection[5].minutes);
	// printf("%.2f\n", collection[8].price);
}

int compareTitle(const void * input1, const void * input2)
{
	DVD dvd1 = *(DVD *)input1;
	DVD dvd2 = *(DVD *)input2;

	const char *temp1 = dvd1.title;
	const char *temp2 = dvd2.title;

	//Ignore leading white space
	int i, j;
	for(j = 0; isspace(temp1[j]); j++);
	for(i = 0; isspace(temp2[i]); i++);
	temp1 = temp1 + j;
	temp2 = temp2 + i;


	// Doing else ifs so "The A An" won't result in skipping The, and A, and An, but only The

	if(temp1[0] == 'T' && temp1[1] == 'h' && temp1[2] == 'e'){
		temp1 = temp1 + 4; // Point at next word
	}
	else if(temp1[0] == 'A' && temp1[1] == 'n')
		temp1 = temp1 + 3; // Point to next word
	else if(temp1[0] == 'A' && temp1[1] == ' '){
		temp1 = temp1 + 2; // Point at next word
	}
	if(temp2[0] == 'T' && temp2[1] == 'h' && temp2[2] == 'e'){
			temp2 = temp2 + 4; // Point at next word
	}
	else if(temp2[0] == 'A' && temp2[1] == 'n')
			temp2 = temp2 + 3; // Point to next word
	else if(temp2[0] == 'A' && temp2[1] == ' '){
		temp2 = temp2 + 2; // Point at next word
	}


	return strcmp(temp1, temp2);

}

int compareMinutes(const void * input1, const void * input2)
{
	DVD dvd1 = *(DVD *)input1;
	DVD dvd2 = *(DVD *)input2;
	if(dvd1.minutes > dvd2.minutes)
		return -1;
	if(dvd1.minutes < dvd2.minutes)
		return 1;
	else
		return 0;
}

int comparePrice(const void * input1, const void * input2)
{
	DVD dvd1 = *(DVD *)input1;
	DVD dvd2 = *(DVD *)input2;
	if(dvd1.price > dvd2.price)
		return -1;
	if(dvd1.price < dvd2.price)
		return 1;
	else
		return 0;
}


void displayDVD(DVD *input, int amount)
{
	printf("------------------------------------------\n");
	printf("TITLE\t\t |  RUN TIME\t| PRICE\n");
	printf("------------------------------------------\n");
	for(int i = 0; i < amount; i++)
	{
		softWrap(input[i].title);
		printf("%s\t\t%3i\t  %.2f\n\n", input[i].title, input[i].minutes, input[i].price);
	}
	printf("------------------------------------------\n");
}


// wraps the line after a certain number of characters
// (in this case 15), by keeping track of the last Blank characters
// and replacing it with a new line in case length of title is greater
// than 15. It also adds spaces at the end of the title upto a certain length
// so that the tab length is same for various title of varying length.
void softWrap(char *title)
{
	int i, j = 1, nc = 0;
	int lastBlank = 0;
	int length = strlen(title);
	char temp[30];

	for(i = 0; i <= length; i++)
	{
		if(title[i] == ' ')
		{
			lastBlank = i;
		}

		// adds a new line at the last blank for every
		// 15 intervals.
		if(i >= 15 * j)
		{
			title[lastBlank] = '\n';
			j++;
		}
	}

	title[i] = '\0';
	length = strlen(title);

	// to count the length of the word in the last line of the title.
	for(i = 0; i < length; i++)
	{
		if(title[i] == '\n')
			nc = 0;

		else nc++;
	}

	// adds spaces to the last line of the title.
	for(j = 0; j < 15 - nc; j++)
	{
		temp[j] = ' ';
	}

	temp[j] = '\0';

	strcat(title, temp);

}
