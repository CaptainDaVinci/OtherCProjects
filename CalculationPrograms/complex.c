// This material is derived from Hanly & Koffman

/*
 *  Operators to process complex numbers
 */
#include <stdio.h>
#include <math.h>

/*  User-defined complex number type */
typedef struct {
      double real, imag;
} complex_t;

complex_t get_complex();
void print_complex(complex_t c);
complex_t add_complex(complex_t c1, complex_t c2);
complex_t subtract_complex(complex_t c1, complex_t c2);
complex_t multiply_complex(complex_t c1, complex_t c2);
complex_t divide_complex(complex_t c1, complex_t c2);
complex_t abs_complex(complex_t c);

/*  Driver                                                         	*/
int
main(void)
{
      complex_t com1, com2;

      /*  Gets two complex numbers	*/
      printf("Enter the real and imaginary parts of a complex number\n");
      printf("separated by a space> ");
      com1 = get_complex();
      printf("Enter a second complex number> ");
      com2 = get_complex();

      /*  Forms and displays the sum	*/
      printf("\n");
      print_complex(com1);
      printf("  +  ");
      print_complex(com2);
      printf("  =  ");
      print_complex(add_complex(com1, com2));

      /*  Forms and displays the product                	*/
      printf("\n\n");
      print_complex(com1);
      printf("  *  ");
      print_complex(com2);
      printf("  =  ");
      print_complex(multiply_complex(com1, com2));

      /*  Forms and displays the quotient                 	*/
      printf("\n\n");
      print_complex(com1);
      printf("  /  ");
      print_complex(com2);
      printf("  =  ");
      print_complex(divide_complex(com1, com2));

      /*  Forms and displays the absolute value of the first number  	*/
      printf("\n\n|");
      print_complex(com1);
      printf("|  =  ");
      print_complex(abs_complex(com1));
      printf("\n");

      return 0;
}

/*
 *  Complex number input function
 */
complex_t
get_complex()
{
      complex_t c;
      scanf("%lf%lf", &c.real, &c.imag);
      return c;
}

/*
 *  Complex output function displays value as (a + bi) or (a - bi),
 *  dropping a or b if they round to 0 unless both round to 0
 */
void
print_complex(complex_t c) /* input - complex number to display   */
{
      double a, b;
      char   sign;

      a = c.real;
      b = c.imag;

      printf("(");

      if (fabs(a) < .005  &&  fabs(b) < .005) {
            printf("%.2f", 0.0);
      } else if (fabs(b) < .005) {
            printf("%.2f", a);
      } else if (fabs(a) < .005) {
            printf("%.2fi", b);
      } else {
            if (b < 0)
                  sign = '-';
            else
                  sign = '+';
            printf("%.2f %c %.2fi", a, sign, fabs(b));
      }

      printf(")");
}

/*
 *  Returns sum of complex values c1 and c2
 */
complex_t
add_complex(complex_t c1, complex_t c2) /* input - values to add    */
{
      complex_t csum;

      csum.real = c1.real + c2.real;
      csum.imag = c1.imag + c2.imag;

      return csum;
}

/*
 *  Returns difference c1 - c2
 */
complex_t
subtract_complex(complex_t c1, complex_t c2) /* input parameters    */
{
      complex_t cdiff;
      cdiff.real = c1.real - c2.real;
      cdiff.imag = c1.imag - c2.imag;

      return cdiff;
}

/*  ** Stub **
 *  Returns product of complex values c1 and c2
 */
complex_t
multiply_complex(complex_t c1, complex_t c2) /* input parameters    */
{
	complex_t cprod;
	cprod.real = (c1.real * c2.real) - (c1.imag * c2.imag);
	cprod.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
	return cprod;
}

/*  ** Stub **
 *  Returns quotient of complex values (c1 / c2)
 */
complex_t
divide_complex(complex_t c1, complex_t c2) /* input parameters     */
{
      complex_t cquot;
      cquot.real = (c1.real * c2.real) + (c1.imag * c2.imag);
      cquot.real = cquot.real / ((c2.real * c2.real) + (c2.imag * c2.imag));

      cquot.imag = (c1.imag * c2.real) - (c1.real * c2.imag);
      cquot.imag = cquot.imag / ((c2.real * c2.real) + (c2.imag * c2.imag));


      return cquot;
}

/*
 *  Returns absolute value of complex number c
 */
complex_t
abs_complex(complex_t c) /* input parameter                        */
{
      complex_t cabs;

      cabs.real = sqrt(c.real * c.real + c.imag * c.imag);
      cabs.imag = 0;

      return cabs;
}
