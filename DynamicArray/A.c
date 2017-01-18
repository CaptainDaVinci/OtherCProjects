/*
 * A.c
 *
 *  Created on: Oct 1, 2015
 *      Author: Zack
 */


/* |astr.c|: pointer-exercising code */

#include <stdio.h>

void  astr( const char** input);

int
main()
{
    const char * s1 = "zero";
    const char * s2 = "infinity";
    astr(&s1);
    astr(&s2);
}

void
astr( const char** input)
{
    printf("invocation of |astr(\"%s\")| successful\n", *input);
}
