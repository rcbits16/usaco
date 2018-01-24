/*
ID: rohitch1
PROG: numtri
LANG: C++
*/
//Classic dynamic programming problem.
//Build recursive soln, & save max sum for each node you visit. (top-down dp)
//Or build sum bottom up. (Dat's what I did.)
// All numbers are less than 100, (and max 1000 will be added) so overflow won't happen.
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
int main(void)
{
    int R;
    vvi rows;
    ifstream fin("numtri.in");
    fin >> R;
    for(int i=1;i<=R;i++){   // ith row has i elements
        vi temp;
        for(int n=1;n<=i;n++){
            int x;    fin >> x;
            temp.pb(x);
        }
        rows.pb(temp);
    }
    fin.close();

    for(int i=R-2;i>=0;i--)     // Last row doesn't need processing
    {
        for(int j=0;j<=i;j++)
        {
            rows[i][j]+= max(rows[i+1][j],rows[i+1][j+1]);
        }
    }
    ofstream fout("numtri.out");
    fout << rows[0][0]<<endl;
    fout.close();
return 0;
}











