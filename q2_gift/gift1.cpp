/*
ID: rohitch1
LANG: C++
PROG: gift1
*/

#include<bits/stdc++.h>

using namespace std;

typedef pair<string,int> si;

int find_ind(int n,si group[],string name);

int main(void)
{
    ifstream infile;   // Now infile and outfile can be used just like cin and cout.
    ofstream outfile;  // (Read more about ifstream and ofstream if you still don't know about them)

    infile.open("gift1.in");
    outfile.open("gift1.out");

    int np;
    infile >> np;
    si group[np];
    si p;

    for(int i=0;i<np;i++)
    {
        infile >> p.first;
        p.second = 0;
        group[i]= p;
    }

    for(int i=0;i<np;i++)
    {
        int money,num,it;

        infile >> p.first >> money >> num;

        if(num!=0)
        {
            it = find_ind(np,group,p.first);
            group[it].second -= money;
            group[it].second += (money%num);

            for(int j=0;j<num;j++)
            {
                infile >> p.first;
                it = find_ind(np,group,p.first);
                group[it].second += (money/num);
            }
        }
    }

    for(int i=0;i<np;i++)
    {
        outfile << group[i].first << " " << group[i].second << "\n";
    }
    infile.close();
    outfile.close();

    return 0;
}

int find_ind(int n,si group[],string name)

{
    for(int i=0;i<n;i++)
    {
        if( group[i].first == name)   return i;
    }
}