/*
ID: rohitch1
PROG: beads
LANG: C++
*/
// Dynamic programming solution,
// Complexity : O(n)
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main(void)
{
    ifstream fin;
    fin.open("beads.in");

    ofstream fout;
    fout.open("beads.out",ios::out);

    int nbeads;
    char temp[400], s[800];
    int left[800][2],right[800][2];  //1st row would store no of extractable red beads, 2nd - blue beads
    fin >> nbeads >> temp;
    for(int i=0;i<nbeads;i++)
    {
        s[i] = temp[i];
        s[i+nbeads] = temp[i];
    }

// We calculate the no. of red beads and blue beads we can take out from left side, if cut at that position.
    left[0][0]=0; left[0][1]=0;
    for (int i=1; i<= 2*nbeads; i++)
    {
        if (s[i - 1] == 'r')
        {
           left[i][0] = left[i - 1][0] + 1;
           left[i][1] = 0;
        }
        else if (s[i - 1] == 'b')
        {
           left[i][1] = left[i - 1][1] + 1;
           left[i][0] = 0;
        }
        else
        {
           left[i][0] = left[i - 1][0] + 1;
           left[i][1] = left[i - 1][1] + 1;
        }
    }

// We calculate the no. of red beads and blue beads we can take out from right side, if cut at that position.
   right[2*nbeads][0] = right[2*nbeads][1] = 0;
   for (int i=2 * nbeads - 1; i >= 0; i--)
   {
       if (s[i] == 'r')
       {
           right[i][0] = right[i + 1][0] + 1;
           right[i][1] = 0;
       }
       else if (s[i] == 'b')
       {
           right[i][1] = right[i + 1][1] + 1;
           right[i][0] = 0;
       }
       else
       {
           right[i][0] = right[i + 1][0] + 1;
           right[i][1] = right[i + 1][1] + 1;
       }
   }

    int m = 0;
    for (int i=0; i<2*nbeads; i++)
    {
        m = max(m,(max(left[i][0], left[i][1]) + max(right[i][0], right[i][1])) );
    }
    //In case we have the whole string of same color, we'd end up with m = 2*nbeads!.
    //so handling that situation.
    m = min(m, nbeads);

    fout << m <<'\n';
   return 0;




}