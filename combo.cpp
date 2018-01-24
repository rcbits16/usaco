/*
ID: rohithc1
PROG: combo
LANG: C++

*/

// I used set and only checked values that already were close enough!
// Alternatively, we could have iterated over all possible combinations, and checked if they are close enough, then we wouldn't have to wrry about repetiton


#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> key;

int main(void)
{

    int N,jl1,jl2,jl3,ml1,ml2,ml3;
    set<key> valid_keys;
    ifstream fin;
    fin.open("combo.in");
    fin >> N;
    fin >> jl1 >> jl2 >> jl3;
    fin >> ml1 >> ml2 >> ml3;
    key temp;

    ofstream fout;
    fout.open("combo.out");

    if(N==1)
    {
        fout << 1 <<'\n';
    }
    else if(N==2)
    {
        fout << 8 << '\n';
    }
    else{
    for(int i=jl1-2; i<=jl1+2 ;i++)
    {
        for(int j=jl2-2; j<=jl2+2 ;j++)
        {
            for(int k=jl3-2; k<=jl3+2 ;k++)
            {
                temp.first =i;
                temp.second.first =j;
                temp.second.second =k;

                if(i<1) temp.first += N; if(j<1) temp.second.first += N; if(k<1) temp.second.second += N;
                if(i>N) temp.first -= N; if(j>N) temp.second.first -= N; if(k>N) temp.second.second -= N;
                    valid_keys.insert(temp);
                    printf("%d %d %d\n",temp.first,temp.second.first,temp.second.second);
            }
        }
    }
    for(int i=ml1-2; i<=ml1+2 ;i++)
    {
        for(int j=ml2-2; j<=ml2+2 ;j++)
        {
            for(int k=ml3-2; k<=ml3+2 ;k++)
            {
                temp.first =i;
                temp.second.first =j;
                temp.second.second =k;

                if(i<1) temp.first += N; if(j<1) temp.second.first += N; if(k<1) temp.second.second += N;
                if(i>N) temp.first -= N; if(j>N) temp.second.first -= N; if(k>N) temp.second.second -= N;

                    valid_keys.insert(temp);
                    printf("%d %d %d\n",temp.first,temp.second.first,temp.second.second);

            }
        }
    }

    fout << valid_keys.size() << '\n';
    }
return 0;
}



