/*
ID:	rohitch1
PROG: palsquare
LANG: C

*/

// No need to do anything fancy, only 300 numbers, convert, check each for palindromicness :P

#include <stdio.h>

int ispalindrome(int x);
int baseChange(int num, int base);

int main(void)
{
	int num;

}


int ispalindrome(char *number)
{

}

int baseChange(int num, int base)
{
	char symbols[] = "0123456789ABCDEFGHIJ";
	char number[];					//Assuming numbers will be less than 300 always

}

//Counting no. of digits
int digitCount(int x)
{
	int ndigits=0,temp=x,expo=10;
	do
	{
		ndigits++;
		temp /= 10;
	}while(temp>0);
	return ndigits;
}






