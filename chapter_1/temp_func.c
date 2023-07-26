#include <stdio.h>

#define LOWER  0
#define UPPER  100
#define STEP 5

float celsius(float fahr);

int main()
{
float fahr;
printf("\nFahrenheit-Celsius table\n\n");
fahr = LOWER;
while (fahr <= UPPER) {
	printf("%3.0f\t%6.1f\n",fahr, celsius(fahr));
	fahr = fahr + STEP;
}
return 0;
}

/* 'celsius' function: a function to convert fahr into celsius */
float celsius(float fahr)
{
 float c;
 c = (5.0 /9.0) * (fahr - 32.0);
 return c;
}


