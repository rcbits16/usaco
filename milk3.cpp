/*
ID: rohitch1
PROG: milk3
LANG: C++
*/
// Don't really need to keep track of a, it must always be C-(b+c)

#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
// Search through solution space with dfs, and stop when the node has already been visited.
// Print only the one's where a is zero. :P
#define MAX 21
int A,B,C;
int m[MAX][MAX][MAX];

void find(int a,int b,int c);
string prbl(int c);
int main(void)
{
    ifstream fin("milk3.in");
    fin >> A >> B >> C;
    fin.close();
string tp;
    find(0,0,C);
    for(int c=0;c<=C;c++)
    for(int b=0;b<=B;b++)
        if(m[0][b][c]==1){
            tp+=prbl(c);
        }
    tp.resize(tp.length()-1);
    ofstream fout("milk3.out");
    fout<<tp <<'\n';
    fout.close();
return 0;
}
void find(int a,int b,int c)
{
    if(m[a][b][c]==0)
    {
    m[a][b][c]=1;
        //C->A
        if(a+c>A) find(A,b,a+c-A);
        else find(a+c,b,0);

        //C->B
        if(b+c>B) find(a,B,b+c-B);
        else find(a,b+c,0);

        //A->B
        if(a+b>B) find(a+b-B,B,c);
        else find(0,a+b,c);

        //A->C
        if(a+c>C) find(a+c-C,b,C);
        else find(0,b,a+c);

        //B->A
        if(a+b>A) find(A,a+b-A,c);
        else find(a+b,0,c);

        //B->C
        if(b+c>C) find(a,b+c-C,C);
        else find(a,0,b+c);
    }
}
string prbl(int c)
{
    string x;
    if(c==0){
        x+="0 ";
        return x;
    }

    while(c>0)
    {
        x += (char)(c%10+'0');
        c/=10;
    }
    reverse(x.begin(),x.end());
    x+=' ';
return x;
}


