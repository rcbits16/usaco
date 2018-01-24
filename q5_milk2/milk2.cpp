/*
ID: rohitch1
PROG: milk2
LANG: C++
*/
// Naive soln,
//Operations  = n*10^6 + n

#include<bits/stdc++.h>

using namespace std;

bool secs[1000000];
int main(void)
{

    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int n;
    int start=0,end=0,final=0,initial=1000000;
    int m=0,id=0, lm=0 ,lid=0;


    fin >> n;
    while(n--)
    {
        fin >> start >> end;
        initial = (start<initial) ? start : initial;
        final = (end > final) ? end : final;

        for(int i=start;i<end;i++)
        {
            secs[i] = true;
        }
    }

    int i=initial;
    while(i<final)
    {
        m=0;id=0;
        while(i<final&&secs[i])
        {
            m++;
            i++;
        }
        lm = (m>lm) ? m : lm;

        while(i<final&&(!secs[i]) )
        {
            id++;
            i++;
        }
        lid = (id>lid) ? id : lid;

    }

    fout << lm << " " << lid <<"\n";

return 0;
}