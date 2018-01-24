/*
ID: rohitch1
PROG: pprime
LANG: C++
*/
// Generating primes here will be wasteful.
// lasrgest primes <10^8 is 99999989
#include<bits/stdc++.h>
using namespace std;

int smal,lar;
vector<int> ans;

bool isprime(int x);
void generatePalindromes(int n);
int main(void)
{
    ifstream fin("pprime.in");
    fin >> smal >>lar;
    fin.close();

    generatePalindromes(lar+1);
    sort(ans.begin(),ans.end());

    ofstream fout("pprime.out");
    for(int i=0;i<ans.size();i++)
        fout << ans[i] <<'\n';

    fout.close();
return 0;
}
void generatePalindromes(int n)
{

}

bool isprime(int x)
{
    int root= (int)sqrt(x);
    for(int i=2;i<=root;i++)
        if(x%i==0) return false;
    return true;
}

