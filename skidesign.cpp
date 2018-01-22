/*
ID: rohitch1
PROG: skidesign
LANG: C++
*/

// Can change the height of a hill only once.
//  Low no of possibilities, brute force will do :P

#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> hills;

int main(void)
{
    ifstream fin("skidesign.in");
    fin >> N;
    for(int i=0;i<N;i++)
    {
        int height;
        fin >> height;
        hills.push_back(height);
    }
    fin.close();

    int costmin=100000000,low=0,high=17;
    for(low=0;low<=83;low++)
    {
        int cost=0;
        for(int i=0;i<N;i++)
        {
            if(hills[i]>high)     cost+= (hills[i]-high)*(hills[i]-high);
            else if(hills[i]<low) cost+= (low-hills[i])*(low-hills[i]);
        }
        if(cost<costmin)    costmin=cost;
        high++;
    }



    ofstream fout("skidesign.out");
    fout << costmin <<"\n";
return 0;
}

