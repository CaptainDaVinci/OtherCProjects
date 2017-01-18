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


void displayDVD(DVD input);

int compareTitle(const void * input1, const void * input2);
int compareMinutes(const void * input1, const void * input2);
int comparePrice(const void * input1, const void * input2);

int main()
{

	DVD collection[10] = {{117, 9.99, "Back to the Future"}, {176, 9.99, "Indiana Jones and the Raiders of the Lost Ark"},
			{82, 6.99, "Army of Darkness"}, {85, 6.99, "Evil Dead 2"},
			{178, 4.00, "The Lord of the Rings: Fellowship of the Ring"},
			{121, 15.00, "Star Wars, Episode IV: A New Hope"},
			{169, 11.99, "The Hobbit: An Unexpected Journey"},
			{106, 9.58, "High Plains Drifter"},
			{99, 6.26, "A Fistful of Dollars"},
			{90, 19.99, "Heavy Metal"}
	};

	// Display all DVDs
	for(int i = 0; i < 10; i++)
	{
		displayDVD(collection[i]);
	}

	// Display a Title of one, price of another, runtime of another.

	printf("%s\n", collection[2].title);
	printf("%i\n", collection[5].minutes);
	printf("%.2f\n", collection[8].price);




	qsort(collection, 10, sizeof(DVD), compareTitle);
	printf("Title Sort \n");
	for(int i = 0; i < 10; i++)
	{
		displayDVD(collection[i]);
	}



	qsort(collection, 10, sizeof(DVD), compareMinutes);
	printf("Minute sort \n");
	for(int i = 0; i < 10; i++)
	{
		displayDVD(collection[i]);
	}




	qsort(collection, 10, sizeof(DVD), comparePrice);
	printf("Price sort \n");
	for(int i = 0; i < 10; i++)
	{
		displayDVD(collection[i]);
	}
	return 0;
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


void displayDVD(DVD input)
{
	printf("%s, Runtime: %i, Price: %.2f\n", input.title, input.minutes, input.price);
}
