/*
ID: rohitch1
PROG: friday
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

bool isLeap(int year)
{
    if(year % 100 ==0)
	return (year % 400 ==0);
    else
	return (year % 4 ==0);
}


int main(void)
{

    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int period;
    fin>>period;


    int calendarDay=0; //This will always be maintained at the first of every month.
    int freq[7]={0,0,0,0,0,0,0}; // This will store the frequency of 13's
    int normDays[12]={31,28,31,30,31,30,31,31,30,31,30,31}; // This
    int leapDays[12]={31,29,31,30,31,30,31,31,30,31,30,31}; // and this have no of days in a month

for(int year=1900; year<1900+period; year++)
{
	for(int month=0; month<12; month++)
	{
		int weekday=(calendarDay+12)%7;
		freq[(weekday+2)%7]++;  //So that first place is storing saturday and so on.. as required.
		calendarDay += isLeap(year) ? leapDays[month]:normDays[month];
	}
}

for(int i=0; i<7; i++)
{
	fout<<freq[i];
	if(i==6) fout<<endl;
	else fout<<" ";
}

return 0;
}