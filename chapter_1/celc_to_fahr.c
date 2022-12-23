#include <stdio.h>

/* print celsius-fahrenheit table */
/* for Celsius = 0, 20, ..., 160; floating-point version */

int main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = -20; /*lower limit of temp. table */
	upper = 160; /* upper limit */
	step = 10; /*step size */
	printf("\nCelsius-Fahrenheit table\n\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0 * celsius) + 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
		}
return 0;
}


