#include <stdio.h>
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
} ;

/* day of year: setday of year from month and day */
int day_of_year(int year, int month, int day) {
	int i, leap;
	
	leap = (year%4 == 0 && year%100 != 0 )|| year%400 == 0; 
	for (i = 1; i < month; i++)
		day += daytab[leap][i];		/* The arithmetic value of a logical expression
									*such as the one for leap is either zero (false)
									* or one (true), so it can be used as a subscript of the 
									* array daytab	i.e .daytab[1][2] represents 29th Feb in a leap year	*/
	return day;
}
/* month_day: set month, day from day of year*/
void day_month(int year, int yearday, int *pday, int *pmonth) {
	int i, leap;
	
	leap = (year%4 == 0 &&  year%100 != 0 )|| year%400 == 0; 
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday; 
}

int main() {
	printf("The day of the year is %d\n", day_of_year(2022, 7, 16) );
	int m, d;

	day_month(2024, 60, &d, &m);
	printf("date is:  %d / %d\n", d, m);
	printf(" %d\n", daytab[1][2]); /*equiv to daytab[leap][2] */
	return 0;
}
	
