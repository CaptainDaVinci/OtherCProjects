// |demo_C.c|: demonstrate |C()|

#include <stdio.h>
#include <stdlib.h>

#define     alen(a)     (sizeof (a) / sizeof *(a))

int * dynamicArray(const int [], size_t, size_t);

void display(const int *, size_t);

int
main()
{
    const int phone_digits[] = { 3, 3, 1, 2, 9, 1, 5 };
    int * phone_digits_ = dynamicArray(phone_digits, alen(phone_digits), 5);
    display(phone_digits_, alen(phone_digits) + 5);
    putchar('\n');
    free(phone_digits_);
    puts("done");
}

void
display(const int * ia_p, size_t len)
{
    char sep_ch = '{';
    for ( const int * ia_end = ia_p + len ;
            ia_p < ia_end ;
            ++ia_p, sep_ch = ','
            )
        printf("%c %i", sep_ch, *ia_p);
    fputs(" }", stdout);
}
