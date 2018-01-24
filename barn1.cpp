/*
ID: rohitch1
PROG: barn1
LANG: C++
*/
// PRoblem data has 1 based indexing :(


#include<bits/stdc++.h>

using namespace std;

// First for cow, second for covered
typedef pair<bool,bool> bb;

#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)


int main(void)
{
//Taking inputs
    int M, S, C;    // Max-boards, stalls, cows
    ifstream fin;
    fin.open("barn1.in");
    fin >>M >>S >>C;

//Initializing stalls
    vector<bb> stalls(S+1);
    for(int i=1;i<=S;i++)
    {
        stalls[i].first = false;
        stalls[i].second = false;
    }

//Filling stalls (i.e. data about which stalls are occupied)
    for(int i=1;i<=C;i++)
    {
        int stallno;    //Declared inside because: https://stackoverflow.com/questions/7959573/declaring-variables-inside-loops-good-practice-or-bad-practice
        fin >> stallno;                 // Also notice stallno doesn't need to retain previous value.
        stalls[stallno].first = true;
    }
//First board
    int boards, covered,first,last,i=1;
    while(i<=S && stalls[i].first==false)    i++;
    first=i;
    while(i<=S){
        if(stalls[i].first==true) last =i;
        i++;
    }
    boards=1; covered = (last-first+1);
    printf("initial cover %d\n",covered);
//Find positions to cut
    vector<int> gaps;
    for(int i=first;i<=last;i++)
    {
        while(i<last && stalls[i].first==true)
            i++;
        int curlen=0;
        while(i<last && stalls[i].first==false)
        {
            curlen++;i++;
        }
        gaps.push_back(curlen);
    }
//Sort in descending order
    sort(gaps.rbegin(),gaps.rend());
    tr(gaps,i)
    {
        if(boards<M){
            covered -= *i;
            boards++;
        }
        else break;
    }

    ofstream fout;
    fout.open("barn1.out");
    fout << covered <<'\n';
}





