/*
ID: rohitch1
PROG: milk2
LANG: C++
*/
// Another solution. Sort the times by start time, merge, and then search for longest periods.

// No. of operations : Sorting = nlogn, merging = n; finding max = n(no.of blocks is n in worst case);
// Overall = nlogn + 2n

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main(void)
{

    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int n;

    ii mtime;
    vector<ii> times;

    fin >> n;
    for(int i=0;i<n;i++)
    {
        fin >> mtime.first >> mtime.second;
        times.push_back(mtime);
    }
    sort(times.begin(), times.end());
    vector<ii> merged;
    ii joint;
    for(int i=0;i<n;i++)
    {
        joint.first = times[i].first;
        joint.second = times[i].second;
        while((i<n-1)&&(joint.second>=times[i+1].first))
        {
            if(times[i+1].second>joint.second) joint.second = times[i+1].second;
            i++;
        }
        merged.push_back(joint);
    }
    int maxmilk=0,maxfree=0,blocks=merged.size();
    for(int i=0;i<blocks;i++)
    {
        if((merged[i].second-merged[i].first)>maxmilk) maxmilk = (merged[i].second-merged[i].first);
        if( (i+1<blocks)&&(merged[i+1].first-merged[i].second)>maxfree) maxfree = (merged[i+1].first-merged[i].second);
    }
    fout << maxmilk <<" " << maxfree <<'\n';
}