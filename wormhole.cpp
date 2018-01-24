/*
ID: rohitch1
PROG: wormhole
LANG: C++
*/
// I looked at an editorial because the problem wasn't clear to me.
// Key Takeaway:: DON"T try to come up with a formula, just enumerate and count, nearly always a better strategy.

#include<bits/stdc++.h>

using namespace std;

#define MAX_N 12

int N,X[MAX_N+1],Y[MAX_N+1];
int partner[MAX_N+1];
int next_right[MAX_N+1];

int solve(void);
bool has_cycles(void);


int main(void)
{
    ifstream fin;
    fin.open("wormhole.in");
    fin >> N;
    for(int i=1;i<=N;i++)
        fin >> X[i] >> Y[i];
    fin.close();

//Set next-right wormhole, stays zero if none
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if( X[j] > X[i] && Y[j] == Y[i] )
              if( next_right[i]==0 || X[j]-X[i] < X[next_right[i]] -X[i] ) // Update if this one comes before the one's found previously
                next_right[i]=j;
        }
    }

    ofstream fout;
    fout.open("wormhole.out");
    fout << solve() <<'\n';
    fout.close();

return 0;
}
//Count all solutions
int solve(void)
{
//find first unnpaired wormhole
    int i, total=0;
    for (i=1; i<=N; i++)
        if (partner[i] == 0) break;

//Everyone paired
    if(i>N){
        if(has_cycles()) return 1;
        else return 0;
    }

// try pairing i with all possible wormholes j
    for(int j=i+1;j<=N;j++)
        if(partner[j]==0)
        {
            partner[i]=j;       //choose & explore.
            partner[j]=i;
            total+= solve();
            partner[i] = 0;
            partner[j] = 0; //Unchoose.
        }

    return total;
}

bool has_cycles(void)
{
//    return true;          //sanity checking,

//Check all start positions.
    for(int start=1;start<=N;start++)
    {
        int posn=start;
        for(int count=0;count<N;count++)
            posn = next_right[partner[posn]];

        if(posn!=0) return true;

    }
return false;
}






