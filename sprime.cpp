/*
ID: rohitch1
PROG: sprime
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;
// Further digits can only be 1,3,7,9.

typedef vector<int> vi;
typedef vector<vi> vvi;

bool isprime(int x);
int main(void)
{
    int n; // 1<<n <<8
    ifstream fin("sprime.in");
    fin >> n;
    fin.close();

    vvi sp;    vi temp;
    temp.push_back(2); temp.push_back(3);
    temp.push_back(5); temp.push_back(7);
    sp.push_back(temp);

    for(int digs=1;digs<n;digs++)
    {
        temp.clear();
        for(int j=0; j<sp[digs-1].size();j++)
        {
            for(int num=1;num<10;num+=2)
            {
                if(isprime((sp[digs-1][j]*10)+num))
                {
                //    cout << (sp[digs-1][j]*10)+num<<'\n';
                    temp.push_back((sp[digs-1][j]*10)+num);
                }
            }
        }
        sp.push_back(temp);
    }

    ofstream fout("sprime.out");
    for(int i=0;i<sp[n-1].size();i++){
        fout << sp[n-1][i] <<'\n';
    }
    fout.close();


}
bool isprime(int x)
{
    int root= (int)sqrt(x);
    for(int i=2;i<=root;i++)
        if(x%i==0) return false;
    return true;
}




